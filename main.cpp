#include <iostream>
#include "includes/httplib.h"
#define CPPHTTPLIB_OPENSSL_SUPPORT
using namespace httplib;
int main() {
    std::cout << "Hello, World!" << std::endl;
    Server serv;

    return 0;
}
