//
// Created by root on 10/14/22.
//
#include <chrono>
#include <vector>
#include <unistd.h>
#include "global_data.h"
#include "../util/ThreadPool.h"
#define ASYNC_ADD_DICT(DictClass, filename) \
  pool.enqueue( \
    [this] () { \
      { \
      std::unique_lock<std::mutex> locker(factory_mutex); \
      dict_factory[filename] = \
        [f = filename] () -> std::shared_ptr<DynamicDict> { \
        return std::dynamic_pointer_cast<DynamicDict>( \
          std::make_shared<DictClass>(f)); \
        }; \
      } \
      return addDict(std::make_shared<DictClass>(filename)); \
    } \
  ) \


namespace inforefiner {
    namespace model {

        std::unordered_map<std::string, std::shared_ptr<DynamicDict>>
                GlobalData::global_data;
        //std::shared_mutex GlobalData::static_mutex;
        std::map<std::string, DictFactory> GlobalData::dict_factory;
        std::mutex GlobalData::factory_mutex;


        bool GlobalData::addDict(std::shared_ptr<DynamicDict> dict) {
            if (dict == nullptr) {
                Log.Error("dict is nullptr");
                return false;
            }
            auto start_time = std::chrono::steady_clock::now();
            if (!dict->load()) {
                Log.Error("addDict %s failed",dict->file_name.c_str());
                return false;
            }
            auto finish_time = std::chrono::steady_clock::now();
            auto total_time = std::chrono::duration_cast<std::chrono::seconds>(
                    finish_time - start_time);
            Log.Info("reloadDict_rpc %s , %d seconds",dict->file_name.c_str(),total_time.count());
            //std::unique_lock<std::shared_mutex> locker(static_mutex);
            global_data[dict->file_name] = dict;
            return true;
        }


        // 全局模型的注册
        bool GlobalData::initDict() {
            auto thread_count = sysconf(_SC_NPROCESSORS_ONLN);
            Log.Info("thread count: %d",thread_count);
            ::ThreadPool pool(thread_count);
            std::vector<std::future<bool>> fs;
            //global_thread_parameter.clear();
            // 粗排模型
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, fm_model_file_name));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, fm_model_file_name_con));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, fm_model_file_name_ID));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, rpush_fm_model_file_name_ID));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, rel_fm_model_file_name_ID));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, feed_watchit_fm_model_file_name));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, rel_fm_model_file_name));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, rel_fm_model_file_name_con));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, push_fm_model_file_name));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, fm_new_user_model_file_name));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, fm_client_model_test_file_name));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, fm_model_test_file_name));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, fm_model_test1_file_name));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, fm_model_test2_file_name));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, fm_model_test3_file_name));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, fm_model_test4_file_name));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, fm_model_test5_file_name));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, fm_model_test6_file_name));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, fm_model_test7_file_name));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, fm_model_test8_file_name));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, fm_model_test9_file_name));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, rel_fm_test_model_file_name));
//            fs.push_back(ASYNC_ADD_DICT(DynamicFmCtrModel, push_fm_test_model_file_name));

            // join futures
            bool succ = true;
            for (auto &fut : fs) {
                if (!fut.get()) {
                    succ = false;
                }
            }
            return succ;
        }
    }
}