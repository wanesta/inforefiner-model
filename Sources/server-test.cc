//
// Created by root on 9/22/22.
//

#include "httplib.h"
#include "nlohmann/json.hpp"
#include <iostream>
#include <thread>
using namespace std;
using namespace httplib;

struct test
{
    string name;
    int age;
};
std::string dump_headers(const Headers &headers)
{
    std::string s;
    char buf[BUFSIZ];

    for (auto it = headers.begin(); it != headers.end(); ++it)
    {
        const auto &x = *it;
        snprintf(buf, sizeof(buf), "%s: %s\n", x.first.c_str(), x.second.c_str());
        s += buf;
    }

    return s;
}

std::string log(const Request &req, const Response &res)
{
    std::string s;
    char buf[BUFSIZ];

    s += "================================\n";

    snprintf(buf, sizeof(buf), "%s %s %s", req.method.c_str(),
             req.version.c_str(), req.path.c_str());
    s += buf;

    std::string query;
    for (auto it = req.params.begin(); it != req.params.end(); ++it)
    {
        const auto &x = *it;
        snprintf(buf, sizeof(buf), "%c%s=%s",
                 (it == req.params.begin()) ? '?' : '&', x.first.c_str(),
                 x.second.c_str());
        query += buf;
    }
    snprintf(buf, sizeof(buf), "%s\n", query.c_str());
    s += buf;

    s += dump_headers(req.headers);

    s += "--------------------------------\n";

    snprintf(buf, sizeof(buf), "%d %s\n", res.status, res.version.c_str());
    s += buf;
    s += dump_headers(res.headers);
    s += "\n";

    if (!res.body.empty())
    {
        s += res.body;
    }

    s += "\n";

    return s;
}
void s2()
{
    sleep(2);
    httplib::Client cli("localhost", 8080);
    auto ree = cli.Get("/hello");
}
void hi(const httplib::Request &req, httplib::Response &res)
{
    nlohmann::json req_j;
    req_j = nlohmann::json{
            {"streamId", 0000}};
    auto body = req_j.dump();
    res.set_content(body, "application/json");
    thread t1(s2);
    t1.detach();
};
void from_json(const nlohmann::json &j, test &t)
{
    t.name = j.value("name", "");
    t.age = stoi(j.value("age", "0"));
}
void hello(const httplib::Request &req, httplib::Response &res)
{

    // httplib::Client cli("localhost", 8080);
    // auto ree = cli.Get("/hello");
    //   if (auto res = cli.Get("/hello")) {
    //   cout << res << endl;
    //   cout << res->get_header_value("Content-Type") << endl;
    //   cout << res->body << endl;
    // }

    // res.set_content(ree->body + "sss", "application/json");
    nlohmann::json req_j;
    req_j = nlohmann::json{
            {"streamId", 1111}};
    auto body = req_j.dump();
    res.set_content(body, "application/json");

    req_j = nlohmann::json{
            {"streamId", 2222}};
    body = req_j.dump();
    res.set_content(body, "application/json");
}
void test1(const httplib::Request &req, httplib::Response &res)
{

    nlohmann::json req_j;
    test t;
    // for (auto &it : req.params)
    // {
    //   std::cout << "key:" << it.first << " value:" << it.second << std::endl;
    // }
    //std::map<std::string, int> c_map{{"one", 1}, {"two", 2}, {"three", 3}};

    try{
        nlohmann::json js(req.params);
        // nlohmann::json j = nlohmann::json::parse(js);

        js.get_to(t);
        req_j = nlohmann::json{
                {"name", t.name}, {"age", t.age}, {"test", "张三"}};
    }
    catch (nlohmann::json::parse_error &e)
    {

        req_j = nlohmann::json{
                {"msg", "JSON解析失败"},
                {"result", 1},
                {"streamId", 0},
        };
    }
    auto body = req_j.dump();
    res.set_content(body, "application/json");
}
int main(void)
{
    Server svr;

    svr.Get("/hi", [](const Request &req, Response &res)
    { hi(req, res); });
    svr.Get("/hello", [](const Request &req, Response &res)
    { hello(req, res); });
    svr.Get("/test1", [](const Request &req, Response &res)
    { test1(req, res); });
    svr.set_logger([](const Request &req, const Response &res)
                   { printf("%s", log(req, res).c_str()); });
    svr.listen("172.16.4.45", 8080);
}
