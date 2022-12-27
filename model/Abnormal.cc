//
// Created by root on 11/8/22.
//
#include "Abnormal.h"
//AbnormalDetect::AbnormalDetect() {
//
//}
//AbnormalDetect::~AbnormalDetect() {
////    Py_DECREF(pFunc);
////    Py_DECREF(pModule);
////    Py_DECREF(pDict);
////    Py_DECREF(pReturn);
//
//}
//std::vector<int>& AbnormalDetect::getResultVec(){
//    return this->result_vec;
//}
//void AbnormalDetect::ModelPredict(std::vector<std::vector<double>> CArray_d, const int row, const int col) {
////    double CArray_d[row][col]= {{1.23,2.31,4.13,2.14,5.12,0.12},
////                                {2.45,3.14,6.48,3.66,4.21,2.32}};
//    this->result_vec = std::vector<int>(row);
//    Py_Initialize();
////    PyObject * pModule = NULL;
////    PyObject * pFunc = NULL;
////    PyObject *pDict = NULL;
////    PyObject *pReturn = NULL;
//    PyRun_SimpleString("import sys");
//    PyRun_SimpleString("import pyod");
//    PyRun_SimpleString("import joblib");
//    PyRun_SimpleString("sys.path.append('/home/gaosm/Downloads/dev-1/inforefiner-model/model')");
////3、调用python文件名。当前的测试python文件名是test.py。在使用这个函数的时候，只需要写文件的名称就可以了。不用写后缀。
//    //Py_DECREF(PyImport_ImportModule("abnormal_detect"));
//    pModule = PyImport_ImportModule("abnormal_detect");
//    pDict = PyModule_GetDict(pModule);
//    pFunc = PyDict_GetItemString(pDict, "load_model_predict");
//    cout<<"C two-dim Array Pass Into The Python List:"<<endl;
//
//    PyObject *PyList  = PyList_New(0);//定义该PyList对象为0和PyList_Append有关，相当于定义PyList为[]
//    PyObject *ArgList = PyTuple_New(1);
//    for(int i = 0; i < row; i++){
//        PyObject *PyList1  = PyList_New(col);
//        for(int j = 0; j < col; j++){
//            PyList_SetItem(PyList1, j, PyFloat_FromDouble(CArray_d[i][j]));
//            //PyList_SetItem(PyList1, j, PyLong_FromLong(CArray[i][j]));
//        }
//        PyList_Append(PyList,PyList1);//PyList_Append可以参考Python中，list的append的用处
//    }
//
//    PyTuple_SetItem(ArgList, 0, PyList);//将PyList对象放入PyTuple对象中
//    pReturn=PyObject_CallObject(pFunc, ArgList);//调用函数，返回一个list
//    cout<<"&&&&&&&&&&&&&&&&&&& " << pFunc << "    " << ArgList << "-------------------------------> " << pReturn <<endl;
//    if(PyList_Check(pReturn)){ //检查是否为List对象
//        int SizeOfList = PyList_Size(pReturn);//List对象的大小，这里SizeOfList = 2
//
//        printf("返回的结果result： ");
//        for(int i = 0; i < SizeOfList; i++){
//            PyObject *ListItem = PyList_GetItem(pReturn, i);//获取List对象中的每一个元素
//            int NumOfItems = PyList_Size(ListItem);//List对象子元素的大小，这里NumOfItems = 3
//            for(int j = 0; j < NumOfItems; j++){
//                PyObject *Item = PyList_GetItem(ListItem, j);//遍历List对象中子元素中的每个元素
//                int result;
//                PyArg_Parse(Item, "i", &result);//i表示转换成int型变量
//                result_vec.push_back(result);
//                std::cout << "    " << result ;
//                //cout << PyInt_AsLong(Item) <<" "; //输出元素
//                Py_DECREF(Item); //释放空间
//            }
//            cout<<endl;
//            Py_DECREF(ListItem); //释放空间
//        }
//    }else{
//        std::cout << "Not a List" << std::endl;
//    }
//    //Py_Finalize();
//    std::cout<< "@!  finish !@ " << std::endl;
////    Py_DECREF(pFunc);
////    Py_DECREF(pModule);
////    Py_DECREF(pDict);
////    Py_DECREF(pReturn);
//}
