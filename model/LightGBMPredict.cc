//
// Created by root on 10/18/22.
//
#include "LightGBMPredict.h"

using namespace std;
LightGBMPredict::LightGBMPredict() {

}
void LightGBMPredict::LoadModel(const std::string filename) {
    int temp;
    int p = 1;
    temp = LGBM_BoosterCreateFromModelfile(filename.c_str(),&p,&this->handle);
    if(temp == 0){
        std::cout << "Load Model success ... !" << std::endl;
    }
}
const double LightGBMPredict::predict(std::vector<float> &row){
//    std::vector<float> row = {0.07946399999999999, 0.9537260000000001, 0.9621209999999999, 0.976303, 7.0, 3.0};
//    for (auto value : row)
//        std::cout << value << ",";
//    std::cout << std::endl;
    void *in_p = static_cast<void *>(row.data());
    std::vector<double> out(1, 0);
    std::vector<std::vector<double>> rVec;
    double *out_result = static_cast<double *>(out.data());
    int64_t out_len;
    LGBM_BoosterPredictForMat(this->handle, in_p, C_API_DTYPE_FLOAT32, 1, 28, 1, C_API_PREDICT_NORMAL, 0, -1, "", &out_len, out_result);
    std::cout << "out &&&&&                                 ---- ---------------- "<< std::endl;
    for(auto& r : out){
        std::cout << "out &&&&&" << r << std::endl;
    }
    return out[0];
    //std::cout << "file predict result is:" << res << std::endl;
    //std::cout << "row predict result size is " << out.size() << " value is " << out[0] << std::endl;
}
std::vector<double> LightGBMPredict::predictVec(std::vector<float> &row){
//    std::vector<float> row = {0.07946399999999999, 0.9537260000000001, 0.9621209999999999, 0.976303, 7.0, 3.0};
//    for (auto value : row)
//        std::cout << value << ",";
//    std::cout << std::endl;
    void *in_p = static_cast<void *>(row.data());
    std::vector<double> out(1, 0);
    std::vector<std::vector<double>> rVec;
    double *out_result = static_cast<double *>(out.data());
    int64_t out_len;
    LGBM_BoosterPredictForMat(this->handle, in_p, C_API_DTYPE_FLOAT32, 1, 28, 1, C_API_PREDICT_NORMAL, 0, -1, "", &out_len, out_result);
    std::cout << "out &&&&&                                 ---- ---------------- "<< std::endl;
    for(auto& r : out){
        std::cout << "out &&&&&" << r << std::endl;
    }
    return out;
    //std::cout << "file predict result is:" << res << std::endl;
    //std::cout << "row predict result size is " << out.size() << " value is " << out[0] << std::endl;
}
