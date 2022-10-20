//
// Created by root on 10/14/22.
//

#pragma once
#include <functional>
#include <map>
#include <memory>
#include <mutex>
#include <shared_mutex>
#include "dynamic_dict.h"
#include "../Pool/ThreadPool.h"
#include "../Lib/Slog.h"
namespace inforefiner{
    namespace model{
        using DictFactory = std::function< std::shared_ptr<DynamicDict>() >;
        class GlobalData{
            private:
                static std::unordered_map<std::string, std::shared_ptr<DynamicDict>> global_data;
                //static std::shared_mutex static_mutex;
            static std::map<std::string, DictFactory> dict_factory;
            static std::mutex factory_mutex;         // for dict_factory when init
            bool addDict(std::shared_ptr<DynamicDict> dict);

        public:
            bool initDict();

            template <class T>
            static std::shared_ptr<T> getDynamicDict(const std::string& dict_name) {
                //std::shared_lock<std::shared_mutex> locker(static_mutex);
                auto it = global_data.find(dict_name);
                if (it != global_data.end()) {
                    return std::dynamic_pointer_cast<T>(it->second);
                } else {
                    Log.Error("error: no such dict=%s ",dict_name.c_str());
                    return nullptr;
                }
            }

            static bool updateDynamicDict(const std::string& dict_name) {
                auto it = dict_factory.find(dict_name);
                if (it == dict_factory.end()) {
                    return false;
                }
                auto dict = it->second();
                if (dict == nullptr) {
                    return false;
                }
                if (!dict->load()) {
                    Log.Error("load %s failed",dict->file_name.c_str());
                    return false;
                }
                //std::unique_lock<std::shared_mutex> locker(static_mutex);
                global_data[dict->file_name] = dict;
                return true;
            }
        };
    }
}

