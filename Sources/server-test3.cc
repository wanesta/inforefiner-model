//
// Created by root on 9/22/22.
//
#include "workflow/WFFacilities.h"
#include <csignal>
#include "wfrest/HttpServer.h"
#include "wfrest/json.hpp"
#include "wfrest/CodeUtil.h"
//#include "log.h"
#include "Slog.h"

using namespace wfrest;
using Json = nlohmann::json;

static WFFacilities::WaitGroup wait_group(1);

void sig_handler(int signo)
{
    wait_group.done();
}

int main()
{
    signal(SIGINT, sig_handler);

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
    //   curl -X POST http://0.0.0.0:8888/json4 -H 'Content-Type: application/json' -d '{"login":"inforefiner-model","password":"inforfiner_password"}'
    svr.POST("/json4", [](const HttpReq *req, HttpResp *resp){
        Json json;
        int N = 967;
        float random = rand() % (N + 1) / (float)(N + 1);
        json["result"] = random;
        //json["aaa"] = "test josn";
        Json j2 = {
                {"pi", 3.141},
                {"happy", true},
                {"name", "Niels"},
                {"nothing", nullptr},
                {"response", {
                               {"everything", 42}
                       }},
                {"list", {1, 0, 2}},
                {"object", {
                               {"currency", "USD"},
                             {"value", 42.99}
                       }}
        };
        std::string str = to_string(j2);
        Log.Info("json string : %s", str.c_str());
        if (req->content_type() != APPLICATION_JSON){
            resp->String("NOT APPLICATION_JSON");
            Log.Error("asdfasdf");
            Log.Debug("Debug log[%d]", 10000);
            //LOG_INFO("server start ip : " << addr << " port : " << port);
            //Log.Error("Debug log[%d]", 10000);
            //Log.Fatal("Debug log[%d]", 10000);
            return;
        }
        resp->Json(json);
        //resp->String("\n  aa a a   \n");
        fprintf(stderr, "Json : %s\n", req->json().dump(4).c_str());
    });
    //Log.Info("Debug log[%s]", 10000);
    const char *addr = "0.0.0.0";
    int port = 8888;
    if (svr.start(addr,port) == 0){
        Log.Info("server start ip : %s port : %d",addr,port);
        wait_group.wait();
        svr.stop();
    } else {
        fprintf(stderr, "Cannot start server");
        exit(1);
    }
    return 0;
}
