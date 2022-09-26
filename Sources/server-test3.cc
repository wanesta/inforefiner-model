//
// Created by root on 9/22/22.
//
#include "workflow/WFFacilities.h"
#include <csignal>
#include "wfrest/HttpServer.h"
#include "wfrest/json.hpp"
#include "wfrest/CodeUtil.h"
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

    // curl -v http://ip:port/json1
    svr.GET("/json1", [](const HttpReq *req, HttpResp *resp)
    {
        Json json;
        json["test"] = 123;
        json["json"] = "test json";
        resp->Json(json);
    });

    // curl -v http://ip:port/json2
    svr.GET("/json2", [](const HttpReq *req, HttpResp *resp)
    {
        std::string valid_text = R"(
        {
            "numbers": [1, 2, 3]
        }
        )";
        resp->Json(valid_text);
    });

    // curl -v http://ip:port/json3
    svr.GET("/json3", [](const HttpReq *req, HttpResp *resp)
    {
        std::string invalid_text = R"(
        {
            "strings": ["extra", "comma", ]
        }
        )";
        resp->Json(invalid_text);
    });

    // recieve json
    //   curl -X POST http://ip:port/json4
    //   -H 'Content-Type: application/json'
    //   -d '{"login":"my_login","password":"my_password"}'
    svr.POST("/json4", [](const HttpReq *req, HttpResp *resp){
        Json json;
        json["test"] = 123;
        json["aaa"] = "test josn";
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
        if (req->content_type() != APPLICATION_JSON)
        {
            resp->String("NOT APPLICATION_JSON");
            return;
        }
        resp->Json(j2);
        resp->String("\n  aa a a   \n");
        fprintf(stderr, "Json : %s", req->json().dump(4).c_str());
    });

    if (svr.start("0.0.0.0",8888) == 0)
    {
        wait_group.wait();
        svr.stop();
    } else
    {
        fprintf(stderr, "Cannot start server");
        exit(1);
    }
    return 0;
}
