//
// Created by root on 9/22/22.
//
#include "workflow/WFFacilities.h"
#include <csignal>
#include "wfrest/HttpServer.h"
#include "wfrest/json.hpp"
#include "wfrest/CodeUtil.h"
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <faiss/IndexIVFFlat.h>

//#include <exception>
#include <nlohmann/json.hpp>
#include "Slog.h"
#include "../Pool/ThreadPool.h"
#include "dynamic_dict.h"
#include "LightGBMPredict.h"
#include "Abnormal.h"

using namespace wfrest;
using Json = nlohmann::json;

static WFFacilities::WaitGroup wait_group(1);

void sig_handler(int signo)
{
    wait_group.done();
}

static LightGBMPredict lightgbm = LightGBMPredict();
AbnormalDetect* abnormalDetect = new AbnormalDetect();
int main(){
    signal(SIGINT, sig_handler);
    char *buffer;
    buffer = getcwd(NULL, 0);
    cout << "文件路径" << buffer << endl;
//将需要调用的模块使用 strcat 作拼接;
    const char *model_path = strcat(buffer,"");

    std::cout<< "hhhhhhhhhhhhhhhhhhhhhhhhhhhh" << model_path << std::endl;
    // /root/inforefiner-model/model-data/LightGBM_model.txt
    const std::string model_file = "/home/gaosm/Downloads/dev-1/inforefiner-model/model-data/LightGBM_model.txt";
    lightgbm.LoadModel(model_file);
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
        Json req_context = req->json();
        time_t t = time(NULL);
        struct tm *stime = localtime(&t);
        printf("predict begin ******** %4d-%02d-%02d %02d/%02d/%2d\n",stime->tm_year+1900,stime->tm_mon+1,stime->tm_mday,stime->tm_hour,stime->tm_min,stime->tm_sec);
        if(req_context.contains("scenesClass") && req_context.contains("data") && req_context["scenesClass"] == "forecast"){
            Json json_data = req_context["data"];
            std::vector<std::vector<double>> res_vec;
            std::cout << "---------------------------------------------------> " << req_context["data"].size() << std::endl;
            for (Json::iterator it = json_data.begin(); it != json_data.end(); ++it) {
                std::vector<float> row_data = *it;
                res_vec.push_back(lightgbm.predictVec(row_data));
                //std::cout << "                 " << lightgbm.predict(row_data) << '\n';
            }
            json_result["result"] = res_vec;
        }
        if(req_context.contains("scenesClass") && req_context.contains("data") && req_context["scenesClass"] == "explore") {
            Json json_data = req_context["data"];
            std::vector<std::vector<double>> dataVec;
            for (Json::iterator it = json_data.begin(); it != json_data.end(); ++it) {
                std::vector<double> row_data = *it;
                dataVec.push_back(row_data);
            }
            int rowcnt = dataVec.size(), colcnt = dataVec[0].size();
            abnormalDetect->ModelPredict(dataVec,rowcnt,colcnt);
            json_result["result"] = abnormalDetect->getResultVec();
//            std::vector<int> dvec = std::vector<int>(rowcnt);
//            ini();
//            test3(dataVec,rowcnt,colcnt,dvec);
//            json_result["result"] = dvec;
            delete abnormalDetect;
        }
        printf("predict finish ******** %4d-%02d-%02d %02d/%02d/%2d\n",stime->tm_year+1900,stime->tm_mon+1,stime->tm_mday,stime->tm_hour,stime->tm_min,stime->tm_sec);
        std::string str = to_string(req_context);
        Log.Info("json string : %s", str.c_str());
        Log.Error("json string : %s", str.c_str());
        Log.Warn("json string : %s", str.c_str());
        Log.Debug("json string : %s", str.c_str());

        if (req->content_type() != APPLICATION_JSON){
            resp->String("NOT APPLICATION_JSON");
            Log.Error("asdfasdf");
            Log.Debug("Debug log[%d]", 10000);
            //LOG_INFO("server start ip : " << addr << " port : " << port);
            //Log.Error("Debug log[%d]", 10000);
            //Log.Fatal("Debug log[%d]", 10000);
            return;
        }
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
