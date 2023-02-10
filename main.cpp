#include <iostream>
#include <fstream>
#include "model/LinearRegression.h"
//#include "Jieba.hpp"
#include <Eigen/Core>
#include "tensorflow/core/public/session.h"
#include "tensorflow/core/platform/env.h"

#define CPPHTTPLIB_OPENSSL_SUPPORT
using namespace tensorflow;
double* readFile(std::string fileName) {
    std::ifstream in;
    in.open(fileName);
    double temp;
    int index = 0;
    double* data = new double[50];
    while (in >> temp) {
        data[index] = temp;
        index++;
    }
    for (int i = 0; i < 50; i++)
        std::cout << "X,Y" << data[i] << std::endl;
    return data;
}
int main() {
    Session* session;
    Status status = NewSession(SessionOptions(), &session);
    if(!status.ok()){
        std::cerr << status.ToString() << std::endl;
        return 1;
    } else {
        std::cout << "Session created successfully" << std::endl;
    }
    if (argc != 2) {
        std::cerr << std::endl << "Usage: ./project path_to_graph.pb" << std::endl;
        return 1;
    }
    double alpha = 0.07;
    int iterations = 200;
    double x_predict = 2.1212;
    double y_predict;

    // 读取文件
    std::string fileNameX = "data/ex2x.dat";
    std::string fileNameY = "data/ex2y.dat";
    std::ifstream in;
    try{
        throw(-1);
    }catch (int i) {

    }catch (double d){

    }
    in.open(fileNameX);
    double temp;
    int length = 0;
    while (in >> temp) {
        length++;
    }
    double* X = new double[length];
    double* Y = new double[length];

    // 模型训练预测
    X = readFile(fileNameX);
    Y = readFile(fileNameY);
    LinearRegression lr(X, Y, length);
    lr.train(alpha, iterations);
    y_predict = lr.predict(x_predict);
    std::cout << y_predict << std::endl;
    return 0;
}
