//
// Created by root on 10/16/22.
//

#pragma once
#include <iostream>
#include <memory>
#include <thread>
#include <vector>
#include <sstream>
#include <exception>
#include <math.h>
#include "dynamic_dict.h"
#include "../Lib/Slog.h"

namespace inforefiner{
    namespace model{
        enum ModelConfigType {
            MC_ALL_OTHER = 0,       // 默认配置
            MC_FEED_FEED,           // 主feed-feed
            MC_FEED_FULLSCREEN,     // 主feed-横屏
            MC_RELATED_DEFAULT,     // 相关-默认
            MC_RELATED_INSERT,      // 相关-插入
            MC_RELATED_CLICK,       // 相关-点入
            MC_RELATED_PUSH,        // 相关-push
            MC_RELATED_FULLSCREEN,  // 相关-横屏

        };

        enum RequestSource {
            REQSOURCE_FEED = 1,        // feed
            REQSOURCE_RELATED = 2,     // 相关推荐
            REQSOURCE_GAME = 3,        // 主feed 横屏
            REQSOURCE_MINI_VIDEO = 4,  // 小视频
            REQSOURCE_DOUBLE_FEED = 5, // 双排
        };

//request scene
        const std::string REQSCENE_DOUBLEFEED = "home";
        const std::string REQSCENE_CLICKIN = "1";
        const std::string REQSCENE_INSERT = "2";
        const std::string REQSCENE_PUSH = "3";

        struct KeyValue {
            std::string key;
            double value;
        };

        inline bool compareKvForSort(const KeyValue &a, const KeyValue &b) {
            return a.value > b.value;
        };

        inline long str2Long(const std::string &string_temp) {
            try {
                return std::stol(string_temp);
            } catch (const std::exception& e) { }
            return 0;
        };

        inline int str2Int(const std::string &string_temp) {
            try {
                return std::stoi(string_temp);
            } catch (const std::exception& e) { }
            return 0;
        };

        inline double str2Double(const std::string &string_temp) {
            try {
                return std::stod(string_temp);
            } catch (const std::exception& e) { }
            return 0.0;
        };

        inline bool str2Bool(const std::string &string_temp) {
            return string_temp == "true" || string_temp == "True";
        };
        inline void fmComputeFixFeature(std::vector<long> &features, std::shared_ptr<DynamicFmCtrModel> dict,
                                        double &fix_sum_weight, std::vector<double> &fix_tsum, std::vector<double>&fix_sumSqr)
        {
            // intercept
            int numFactors = dict->numFactors;
            // w * x
            size_t f_size = features.size();
            for (size_t i = 0; i < f_size; i++)
            {
                std::vector<double> * weight_vec = dict->getWeight(features[i]);
                if (weight_vec != NULL)
                {
                    fix_sum_weight += (*weight_vec)[0];
                }
            }
            // <vi * vj> xi *xj
            for (int i = 1; i < (numFactors + 1); i++)
            {
                double tsum = 0.0;
                double sumSqr = 0.0;
                for (size_t j = 0; j < f_size; j++)
                {
                    std::vector<double> * matrix_vec = dict->getWeight(features[j]);
                    if (matrix_vec != NULL)
                    {
                        tsum += (*matrix_vec)[i];
                        sumSqr += (*matrix_vec)[i] * (*matrix_vec)[i];
                    }
                }
                fix_tsum.push_back(tsum);
                fix_sumSqr.push_back(sumSqr);
            }
        }

        inline double fmCompute(std::vector<long> &features, std::shared_ptr<DynamicFmCtrModel> dict, double &fix_sum_weight, std::vector<double> &fix_tsum, std::vector<double>&fix_sumSqr){
            double sum_weight = fix_sum_weight;
            // intercept
            int numFactors = dict->numFactors;
            if (numFactors != fix_tsum.size() || numFactors != fix_sumSqr.size())
            {
                return 0.0;
            }
            long intercept = -1;
            std::vector<double> * intercept_vec = dict->getWeight(intercept);
            if (intercept_vec != NULL)
            {
                sum_weight += (*intercept_vec)[0];
            }
            // w * x
            size_t f_size = features.size();
            for (size_t i = 0; i < f_size; i++)
            {
                std::vector<double> * weight_vec = dict->getWeight(features[i]);
                if (weight_vec != NULL)
                {
                    sum_weight += (*weight_vec)[0];
                }
            }
            // <vi * vj> xi *xj
            for (int i = 1; i < (numFactors + 1); i++)
            {
                double tsum = 0.0;
                double sumSqr = 0.0;
                for (size_t j = 0; j < f_size; j++)
                {
                    std::vector<double> * matrix_vec = dict->getWeight(features[j]);
                    if (matrix_vec != NULL)
                    {
                        tsum += (*matrix_vec)[i];
                        sumSqr += (*matrix_vec)[i] * (*matrix_vec)[i];
                    }
                }
                tsum += fix_tsum[i-1];
                sumSqr += fix_sumSqr[i-1];
                sum_weight += (tsum * tsum - sumSqr)/2;
            }
            return  (1.0 / (1+exp(-sum_weight)));
        };

        inline double fmCompute(std::vector<long> &features, std::shared_ptr<DynamicFmCtrModel> dict)
        {
            double sum_weight = 0.0;
            // intercept
            int numFactors = dict->numFactors;
            long intercept = -1;
            std::vector<double> * intercept_vec = dict->getWeight(intercept);
            if (intercept_vec != NULL)
            {
                sum_weight += (*intercept_vec)[0];
            }
            // w * x
            size_t f_size = features.size();
            for (size_t i = 0; i < f_size; i++)
            {
                std::vector<double> * weight_vec = dict->getWeight(features[i]);
                if (weight_vec != NULL)
                {
                    sum_weight += (*weight_vec)[0];
                }
            }
            // <vi * vj> xi *xj
            for (int i = 1; i < (numFactors + 1); i++)
            {
                double tsum = 0.0;
                double sumSqr = 0.0;
                for (size_t j = 0; j < f_size; j++)
                {
                    std::vector<double> * matrix_vec = dict->getWeight(features[j]);
                    if (matrix_vec != NULL)
                    {
                        tsum += (*matrix_vec)[i];
                        sumSqr += (*matrix_vec)[i] * (*matrix_vec)[i];
                    }
                }
                sum_weight += (tsum * tsum - sumSqr)/2;
            }
            return  (1.0 / (1+exp(-sum_weight)));
        };

        inline double fmComputeRegression(std::vector<long> &features, std::shared_ptr<DynamicFmCtrModel> dict)
        {
            double sum_weight = 0.0;
            // intercept
            int numFactors = dict->numFactors;
            long intercept = -1;
            std::vector<double> * intercept_vec = dict->getWeight(intercept);
            if (intercept_vec != NULL)
            {
                sum_weight += (*intercept_vec)[0];
            }
            // w * x
            size_t f_size = features.size();
            for (size_t i = 0; i < f_size; i++)
            {
                std::vector<double> * weight_vec = dict->getWeight(features[i]);
                if (weight_vec != NULL)
                {
                    sum_weight += (*weight_vec)[0];
                }
            }
            // <vi * vj> xi *xj
            for (int i = 1; i < (numFactors + 1); i++) {
                double tsum = 0.0;
                double sumSqr = 0.0;
                for (size_t j = 0; j < f_size; j++)
                {
                    std::vector<double> * matrix_vec = dict->getWeight(features[j]);
                    if (matrix_vec != NULL)
                    {
                        tsum += (*matrix_vec)[i];
                        sumSqr += (*matrix_vec)[i] * (*matrix_vec)[i];
                    }
                }
                sum_weight += (tsum * tsum - sumSqr)/2;
            }
            return sum_weight;
        };
    }
}
