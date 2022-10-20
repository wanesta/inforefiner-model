//
// Created by root on 10/14/22.
//
#include <fstream>
#include <folly/String.h>
#include "dynamic_dict.h"
#include "common.h"
#include "str_fun.h"
#include "ghash.h"
#include "../Lib/Slog.h"
namespace inforefiner{
    namespace model{
        const std::string DynamicDict::base_dict = "../data/";

        bool DynamicFmCtrModel::load() {
            fm_dict.clear();
            numFactors = 0;
            std::string file_path = fullFileName(file_name);
            std::ifstream  infile(file_path);
            if (!infile.is_open()) {
                Log.Error(" load dict %s failed.",file_path.c_str());
                return false;
            }
            std::string line;
            std::vector<std::string> line_vec;
            std::vector<double> value_vec;
            int error_count = 0;
            while(getline(infile,line)) {
                line_vec.clear();
                value_vec.clear();
                split_string(line.c_str(), "\t", line_vec);
                if (line_vec.size() < 2) {
                    Log.Error(" load dict= %s error line = %s ",file_name.c_str(),line.c_str());
                    error_count++;
                    continue;
                }
                if (line_vec[0] != "intercept") {
                    long key = str2Long(line_vec[0]);
                    for (int i = 1; i < line_vec.size(); i++) {
                        value_vec.push_back(str2Double(line_vec[i]));
                    }
                    fm_dict[key] = value_vec;
                    numFactors = line_vec.size() - 2;
                } else if (line_vec[0] == "intercept") {
                    long key = -1;
                    value_vec.push_back(str2Double(line_vec[1]));
                    fm_dict[key] = value_vec;
                }
            }
            // LOG_INFO("label_dict map_size=" << fm_dict.size()  <<" error_count=" << error_count);
            // infile.close();
            return true;
        }

        std::vector<double>* DynamicFmCtrModel::getWeight(long key) {
            auto it = fm_dict.find(key);
            if (it != fm_dict.end()) {
                return &fm_dict[key];
            }
            return NULL;
        }
    }
}



