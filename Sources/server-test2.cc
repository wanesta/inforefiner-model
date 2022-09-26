#include <iostream>
#include "httplib.h"

using Request = httplib::Request;
using Response = httplib::Response;
using Server = httplib::Server;
using Params = httplib::Params;

// get 请求中对 "/go" 的处理
void get_go(const Request& req, Response& res)
{
    // 设置 "/go" 请求返回的内容
    res.set_content("<html><h1>Inforefiner http api test </h1></html>\n", "text/html");

    std::cout << "Received a request of get [go]." << std::endl;
}

int main(int argc, char const *argv[])
{
    // 搭建服务端
    Server srv;

    // 这里注册用于处理 get 请求的函数，当收到对应的get请求时，程序会执行对应的函数
    srv.Get("/tempo-ai-design/api/ai/platform/service/gen-token", get_go); // 可能相比 lambda 表达式，刚从 C 语言转过来的同学更熟悉这种形式，这个get调用方式也更简介易懂

    // 这里注册的处理函数是 C++ 的 lambda 表达式，直接看成传入了一个指针就行了
    srv.Get("/hi", [&](const Request& req, Response& res){
        // 设置 get "hi" 请求返回的内容
        res.set_content("<html><h1>Hello world!</h1></html>", "text/html");

        std::cout << "Received a request of get [hi]." << std::endl;
    });

    srv.Get("/link", [&](const Request& req, Response& res){
        res.set_content("<html><h1 href=https://baike.baidu.com/item/%E8%A5%BF%E5%8D%8E%E5%A4%A7%E5%AD%A6%E6%9C%BA%E5%99%A8%E4%BA%BA%E8%B6%B3%E7%90%83%E5%8D%8F%E4%BC%9A/22274030>soccer robot</h1></html>", "text/html");

        std::cout << "Received a request of get [link]." << std::endl;
    });

    // POST 请求处理
    srv.Post("/get_info", [&](const Request& req, Response& res) {
        res.set_content("<html><h1>Go ahead!</h1></html>", "text/html");

        std::cout << "Received a request of POST [get_info]." << std::endl;
    });

    // 绑定端口，启动监听
    srv.listen("localhost", 8083);

    return 0;
}
