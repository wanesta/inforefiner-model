//
// Created by root on 11/8/22.
//
#pragma once
#include <iostream>
#include <vector>
#include "numpy/arrayobject.h"
#include <python3.6/Python.h>

using namespace std;
class AbnormalDetect{
public:
    AbnormalDetect();
    std::vector<int>& getResultVec();
    void ModelPredict(std::vector<std::vector<double>> CArray_d,const int row, const int col);
    ~AbnormalDetect();

private:
    std::vector<int> result_vec;
    PyObject * pModule = NULL;
    PyObject * pFunc = NULL;
    PyObject *pDict = NULL;
    PyObject *pReturn = NULL;
};
