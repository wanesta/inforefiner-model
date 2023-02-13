//
// Created by root on 10/17/22.
//

#pragma once
#include<string>
#include<iostream>
#include <math.h>
using namespace std;

class LinearUtil {
public:
    static double* array_diff(double predictions[], double y[], int m);
    static double* array_multiplication(double diff[], double x[], int m);
    static double* array_pow(double error[], int m, int n);
    static double array_sum(double error[], int m);
};

double* LinearUtil::array_diff(double predictions[], double y[], int m) {
    double *diff = new double[m];
    for (int i = 0; i < m; i++) {
        diff[i] = predictions[i] - y[i];
    }

    return diff;
}

double* LinearUtil::array_multiplication(double diff[], double x[], int m) {
    double *differror = new double[m];
    for (int i = 0; i < m; i++) {
        differror[i] = diff[i] * x[i];
    }

    return differror;
}

double LinearUtil::array_sum(double error[], int m) {
    double sum = 0.0;
    for (int i = 0; i < m; i++) {
        sum += error[i];
    }

    return sum;
}

double* LinearUtil::array_pow(double error[], int m, int n) {
    double *sq_errors = new double[m];
    for (int i = 0; i < m; i++) {
        sq_errors[i] = pow(error[i], n);
    }

    return sq_errors;
}
