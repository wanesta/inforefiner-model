//
// Created by root on 9/22/22.
//

#include "httplib.h"
#include <iostream>
#include "nlohmann/json.hpp"
#define CA_CERT_FILE "./ca-bundle.crt"

using namespace std;

nlohmann::json req_j = nlohmann::json{
        {"name", "王五"},
        {"age", 69},
};
struct test
{
    string name;
    int age;
};
void from_json(const nlohmann::json &j, test &t)
{
    t.name = j.value("name", "");
    t.age = j.value("age", 0);
};
int main(void)
{
#ifdef CPPHTTPLIB_OPENSSL_SUPPORT
    httplib::SSLClient cli("localhost", 8080);
  // httplib::SSLClient cli("google.com");
  // httplib::SSLClient cli("www.youtube.com");
  cli.set_ca_cert_path(CA_CERT_FILE);
  cli.enable_server_certificate_verification(true);
#else
    httplib::Client cli("127.0.0.1", 8080);
#endif
    test t;
    req_j.get_to(t);
    string str = "/test1?name=" + t.name + "&age=" + to_string(t.age);
    cout << str << endl;
    cout << str.data() << endl;

    if (auto res = cli.Get(str.data()))

    {
        cout << res << endl;
        cout << res->get_header_value("Content-Type") << endl;
        cout << res->body << endl;
    }
    else
    {
        cout << "error code: " << res.error() << std::endl;
#ifdef CPPHTTPLIB_OPENSSL_SUPPORT
        auto result = cli.get_openssl_verify_result();
    if (result)
    {
      cout << "verify error: " << X509_verify_cert_error_string(result) << endl;
    }
#endif
    }

    return 0;
}
