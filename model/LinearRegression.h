//
// Created by root on 10/17/22.
//

#pragma once
class LinearRegression {
public:
    double *x;
    double *y;
    int m;
    double *theta;
    LinearRegression(double x[], double y[], int m);
    void train(double alpha, int iterations);
    double predict(double x);
private:
    //计算模型损失
    static double compute_cost(double x[], double y[], double theta[], int m);
    //计算单个预测值
    static double h(double x, double theta[]);
    //预测
    static double *calculate_predictions(double x[], double theta[], int m);
    //梯度下降
    static double *gradient_descent(double x[], double y[], double alpha, int iter, double *J, int m);
};

