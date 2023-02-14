//
// Created by root on 9/22/22.   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
//
#include "workflow/WFFacilities.h"
#include <csignal>
#include "wfrest/HttpServer.h"
#include "wfrest/json.hpp"
#include "wfrest/CodeUtil.h"
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
//#include <faiss/IndexIVFFlat.h>

//#include <exception>
#include <nlohmann/json.hpp>
#include "Slog.h"
#include "../Pool/ThreadPool.h"
#include "dynamic_dict.h"
#include "LightGBMPredict.h"
//#include "Abnormal.h"

using namespace wfrest;
using Json = nlohmann::json;

static WFFacilities::WaitGroup wait_group(1);

void sig_handler(int signo)
{
    wait_group.done();
}

static LightGBMPredict lightgbm_failure_rate = LightGBMPredict();
static LightGBMPredict lightgbm_repair_cost = LightGBMPredict();
//AbnormalDetect* abnormalDetect = new AbnormalDetect();
int main(){
    signal(SIGINT, sig_handler);
    char *buffer;
    buffer = getcwd(NULL, 0);
    cout << "文件路径" << buffer << endl;
//将需要调用的模块使用 strcat 作拼接;
    const char *model_path = strcat(buffer,"");
    // /root/inforefiner-model/model-data/LightGBM_model_test.txt   //测试
    // /root/inforefiner-model/model-data/LightGBM_model_failure_rate.txt   //故障率预测
    // /root/inforefiner-model/model-data/LightGBM_model_repair_cost.txt  //维修物资成本预测
    const std::string failure_rate_model_file = "/home/gaosm/Downloads/dev-1/inforefiner-model/model-data/LightGBM_model_failure_rate.txt";
    const std::string repair_cost_model_file =  "/home/gaosm/Downloads/dev-1/inforefiner-model/model-data/LightGBM_model_repair_cost.txt";
    lightgbm_failure_rate.LoadModel(failure_rate_model_file);
    lightgbm_repair_cost.LoadModel(repair_cost_model_file);
    HttpServer svr;
    //Log.init("/home/gaosm/Downloads/dev-1/inforefiner-model/config/slog.properties");
    Log.init("../config/slog.properties");
    // curl -v http://0.0.0.0:8888/json3
    svr.GET("/json3", [](const HttpReq *req, HttpResp *resp){
        std::string invalid_text = R"(
        {
            "strings": ["extra", "comma", ]
        }
        )";
        resp->Json(invalid_text);
    });

    // recieve json
    /***
     * scenesClass:  forecast（预测类）、evaluate（评价类）、explore（探索类）
     * curl -X POST http://0.0.0.0:8888/json4 -H 'Content-Type: application/json' -d
     * '{
     *   "scenesClass":  "forecast",
     *   "model":  "failure-rate-predict",
     *   "col-name":  ["Triangulum","Sagittarius_Dwarf","Andromeda_nebula","Sextans_Dwarf","Knife_Edge","Corona_Borealis","Centaurus",
     *                 "Pisces-Perseus","Mice","Coma","Antlia_Dwarf","Ursa_Major","Canis_Major","Large_Magellanic",
     *                 "Fornax","Fornax_cluster","Draco","Bullet Cluster","Virgo galaxy cluster","Ursa Minor","Small Magellanic",
     *                 "Stephans","Local cluster","Local supercluster","Tucana Dwarf Galaxy","Shapley supercluster","Whirlpool galaxy","Leo Doublet"],
     *   "data":[
     *      [0.644,1.4547,-6.447,2.862,0.374,0.854,-1.346,-0.790,2.173,1.3415,-1.001,1.400,0.000,1.575,1.807,2.007,0.000,3.585,-0.190,-0.744,1.102,0.658,1.061,0.9080,0.975,0.581,0.905,0.796],
     *      [0.833,0.809,1.657,1.637,1.019,0.705,1.077,-0.968,2.173,1.261,0.114,-0.298,1.107,1.032,0.017,0.236,0.000,0.640,-0.026,-1.598 ,0.000,0.894,0.982,0.981,1.250,1.054,1.018,0.853],
     *      [3.512,-1.094,-0.220,0.338,-0.328,1.962,-1.099,1.544,1.087,1.461,-1.305,-0.922,2.215,1.219,-1.289,0.400,0.000,0.731,0.155,1.249,0.000,1.173,1.366,0.993,2.259,2.000,1.626,1.349]
     *      ]
     * }'
     * */
    //inforefiner::model::ThreadPool pool;
    //pool.start(10);
    //std::future<int> res1 = pool.submit(sum1,200, 500);
    //std::future<int> res2 = pool.submit(sum2, 10, 200,10);
    svr.POST("/json4", [](const HttpReq *req, HttpResp *resp){
        Json json_result;
        try {
            Json req_context = req->json();
            time_t t = time(NULL);
            struct tm *stime = localtime(&t);
            printf("predict begin ******** %4d-%02d-%02d %02d/%02d/%2d\n", stime->tm_year + 1900, stime->tm_mon + 1,
                   stime->tm_mday, stime->tm_hour, stime->tm_min, stime->tm_sec);
            if (req_context.contains("scenesClass") && req_context.contains("data") && req_context["scenesClass"] == "forecast" && req_context["model"] == "failure-rate") {
                Json json_data = req_context["data"];
                std::vector<std::vector<double>> res_vec;
                std::cout << "---------------------------------------------------> " << req_context["data"].size()
                          << std::endl;
                for (Json::iterator it = json_data.begin(); it != json_data.end(); ++it) {
                    std::vector<double> row_data = *it;
                    row_data.push_back(lightgbm_failure_rate.predict(row_data));
                    res_vec.push_back(row_data);
                    //std::cout << "                 " << lightgbm.predict(row_data) << '\n';
                }
                json_result["scenesClass"] = "forecast";
                json_result["model"] = "failure-rate";
                json_result["result"] = res_vec;
            }else if(req_context.contains("scenesClass") && req_context.contains("data") && req_context["scenesClass"] == "forecast" && req_context["model"] == "repair-cost"){
                Json json_data = req_context["data"];
                std::vector<std::vector<double>> res_vec;
                std::cout << "---------------------------------------------------> " << req_context["data"].size()
                          << std::endl;
                for (Json::iterator it = json_data.begin(); it != json_data.end(); ++it) {
                    std::vector<double> row_data = *it;
                    row_data.push_back(lightgbm_repair_cost.predict(row_data));
                    res_vec.push_back(row_data);
                }
                json_result["scenesClass"] = "forecast";
                json_result["model"] = "repair-cost";
                json_result["result"] = res_vec;
            }else if (req_context.contains("scenesClass") && req_context.contains("data") && req_context["scenesClass"] == "explore" && req_context["model"] == "abnormal-detect") {
                Json json_data = req_context["data"];
                std::vector<std::vector<int>> dataVec(json_data.size(), vector<int>(json_data[0].size(), 0));
                std::cout << "   json_data size :" +  json_data.size() << std::endl;
                int i = 0;
                for (Json::iterator it = json_data.begin(); it != json_data.end() && i < json_data.size(); ++it,i++) {
                    std::vector<double> row_data = *it;
                    double sums = std::accumulate(std::begin(row_data), std::end(row_data), 0.0);
                    double mean = sums/row_data.size();
                    std::cout << " = = = = = = = = = = = = " << mean << std::endl;
                    for(int beg = 0; beg < row_data.size();beg++){
                        if(row_data[beg] > mean){
                            dataVec[i][beg] = 1;
                            //std::cout << " = <<<<<<<< " << i << " >>>>>>>> " << beg << dataVec[i][beg] << std::endl;
                        }
                    }
                }

                json_result["result"] = dataVec;
                json_result["scenesClass"] = "explore";
                json_result["model"] = "abnormal-detect";
            }else{
                throw 400;
            }
            printf("predict finish ******** %4d-%02d-%02d %02d/%02d/%2d\n", stime->tm_year + 1900, stime->tm_mon + 1,
                   stime->tm_mday, stime->tm_hour, stime->tm_min, stime->tm_sec);
            std::string str = to_string(req_context);
            Log.Info("json string : %s", str.c_str());
            Log.Error("json string : %s", str.c_str());
            Log.Warn("json string : %s", str.c_str());
            Log.Debug("json string : %s", str.c_str());
        }catch(exception &e){
            json_result["status"] = 400;
            Log.Error("json string exception!!! ");
        }catch (int i){
            if(i == 400) json_result["status"] = 400;
        }
        if (req->content_type() != APPLICATION_JSON){
            resp->String("NOT APPLICATION_JSON");
            Log.Error("asdfasdf");
            Log.Debug("Debug log[%d]", 10000);
            //LOG_INFO("server start ip : " << addr << " port : " << port);
            //Log.Error("Debug log[%d]", 10000);
            //Log.Fatal("Debug log[%d]", 10000);
            return;
        }
        if(!json_result.contains("status")) json_result["status"] = 200;
        resp->Json(json_result);
        //resp->String("\n  aa a a   \n");
        //fprintf(stderr, "Json : %s\n", req->json().dump(4).c_str());
    });
    //Log.Info("Debug log[%s]", 10000);
    const char *addr = "0.0.0.0";
    int port = 8888;
    if (svr.start(addr,port) == 0){
        Log.Info("server start ip : %s port : %d",addr,port);
        Log.Warn("server start ip : %s port : %d",addr,port);
        Log.Error("server start ip : %s port : %d",addr,port);
        wait_group.wait();
        svr.stop();
    } else {
        fprintf(stderr, "Cannot start server");
        exit(1);
    }
    return 0;
}
