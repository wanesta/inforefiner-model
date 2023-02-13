//
// Created by root on 10/14/22.
//

#pragma once
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <nlohmann/json.hpp>
namespace inforefiner {
    namespace model {
        class DynamicDict{
        public:
            const static std::string base_dict;
            std::string file_name;
            DynamicDict(const std::string& file_name_p) : file_name(file_name_p){}
            virtual ~DynamicDict(){}
            virtual bool load(){};
            std::string fullFileName(const std::string& file_name_t){
                return base_dict+file_name_t+".txt";
            }
        };
        class DynamicFmCtrModel : public DynamicDict {
        public:
            DynamicFmCtrModel(const std::string & file_name): DynamicDict(file_name){};
            bool load();
            std::vector<double> * getWeight(long key);
            int numFactors;
            std::unordered_map<long, std::vector<double>> fm_dict;
        };
    }
}

