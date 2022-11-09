cmake_minimum_required(VERSION 3.22)
project(inforefiner-model)

set(CMAKE_CXX_STANDARD 14)
set(EXE_SERVER ${PROJECT_SOURCE_DIR}/Sources/server-test3.cc)
set(main ${PROJECT_SOURCE_DIR}/main.cpp)
set(lightgbm_so /usr/local/lib/lib_lightgbm.so)
set(SLOG_SRC ${PROJECT_SOURCE_DIR}/Lib/Slog.cc)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fPIC -pipe -std=c++14 -fexceptions")
set(LIB ${PROJECT_SOURCE_DIR}/Lib)
set(DICT ${PROJECT_SOURCE_DIR}/dict)
set(THREAD_POOL ${PROJECT_SOURCE_DIR}/Pool)
set(THREAD_POOL_HEAD ${PROJECT_SOURCE_DIR}/util)
set(LOG_FILE ${CMAKE_CURRENT_SOURCE_DIR}/log)
set(MODEL_HEAD ${PROJECT_SOURCE_DIR}/model)
set(GBM_SRC ${PROJECT_SOURCE_DIR}/model/LightGBMPredict.cc)
set(ABN_SRC ${PROJECT_SOURCE_DIR}/model/Abnormal.cc)
set(NUMPY_INCLUDE_DIR "/usr/local/lib/python3.6/dist-packages/numpy/core/include/")
set(PYLIB "/usr/include/python3.6")

file(GLOB_RECURSE INCLUDES "includes/*.h")
file(GLOB_RECURSE THRPL "util/*.h")
file(GLOB_RECURSE LIBS "Lib/*.cc")
file(GLOB_RECURSE THREAD_POOL "Pool/ThreadPool.cc")
file(GLOB_RECURSE DYDICT "dict/dynamic_dict.cc")
file(GLOB_RECURSE GLOBAL_DATA "dict/global_data.cc")
file(GLOB_RECURSE LINEAR_REGRESSION "model/LinearRegression.cc")
file(GLOB_RECURSE MODEL_SRC "model/*.cc")
file(GLOB_RECURSE PYENV "/usr/lib/python3.6/config-3.6m-x86_64-linux-gnu/*.so")

# 创建日志文件夹
execute_process( COMMAND ${CMAKE_COMMAND} -E make_directory ${LOG_FILE})
#set(CXX_FLAGS
#        -Wall
#        -std=c++14
#        -lpthread
#        -Wno-unused-parameter
#        -03
#        )
link_libraries(pthread)
#link_libraries(memcached)
#如果不加 提示找不到 fatal error: Slog.h: No such file or directory #include "Slog.h"
include_directories(${LIB} ${NUMPY_INCLUDE_DIR} ${THREAD_POOL} ${THREAD_POOL_HEAD} ${DICT} ${MODEL_HEAD} ${PYLIB})
#include_directories(${THREAD_POOL_HEAD})
#include_directories(${DICT})
#include_directories(${THREAD_POOL})
#include_directories(${MODEL_HEAD})

find_package(OpenSSL REQUIRED)
find_package(wfrest REQUIRED CONFIG HINTS ..)
#先找
find_package(workflow REQUIRED CONFIG HINTS ..)
#再链接
link_directories(${WFREST_LIB_DIR} ${WORKFLOW_LIB_DIR})
#include_directories(
#        ${OPENSSL_INCLUDE_DIR}
#        ${CMAKE_CURRENT_BINARY_DIR}
#        ${WORKFLOW_INCLUDE_DIR}
#        ${WFREST_INCLUDE_DIR}
#        ${LOG_LIB}
#)

#加子目录，第二个 Lib 是生成文件夹名字
ADD_SUBDIRECTORY(Lib Lib)
aux_source_directory("Sources" SOURCES)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
if (APPLE)
    set(WFREST_LIB wfrest workflow pthread OpenSSL::SSL OpenSSL::Crypto protobuf z)
else ()
    set(WFREST_LIB wfrest)
endif ()

#set_property(TARGET ${Lib} PROPERTY IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/LOGLIB)

#include_directories(${PROJECT_SOURCE_DIR}) # 头文件的路径
link_directories(${LIB})
link_directories(${MODEL_HEAD})
find_library (libpath libSlog.a ${LIB})
#find_path(libp Slog.h ${PROJECT_SOURCE_DIR}/Lib)
#find_package(Slog REQUIRED)
message (STATUS "XXXXXXXXXXXXXXXXXXXXXXXXXXXX      ${libpath}")
if (${libpath} STREQUAL "libpath-NOTFOUND")
    message (STATUS "***************************required libSlog library but not found!")
else()
    message (STATUS "--------------------------libpath libSlog found in ${libpath}")
endif()

add_executable(server-test3 ${EXE_SERVER} ${LIBS} ${MODEL_SRC} ${THREAD_POOL} ${DYDICT} ${GLOBAL_DATA} ${THRPL} ${ABN_SRC})
add_executable(main ${main} ${LINEAR_REGRESSION} )
#set(lib_dir ${PROJECT_SOURCE_DIR}/lib)
## 拷贝 src文件夹下的内容  到  save_src_dir 中
#execute_process( COMMAND ${CMAKE_COMMAND} -E copy_directory
#        ${LOG_LIB}/Slog.a
#        ${LOG_LIB}/Slog.so
#        ${lib_dir})

target_link_libraries(server-test3 pthread ${WFREST_LIB} log4cplus ${lightgbm_so} ${PYENV})
#target_link_libraries(server-test3 ${LIB}/libSlog.so)
#target_include_directories(server-test3 PUBLIC ${PROJECT_SOURCE_DIR}/Lib)