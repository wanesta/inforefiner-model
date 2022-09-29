cmake_minimum_required(VERSION 3.22)
project(inforefiner-model)

set(CMAKE_CXX_STANDARD 14)
set(EXE_SERVER ${PROJECT_SOURCE_DIR}/Sources/server-test3.cc)
set(SLOG_SRC ${PROJECT_SOURCE_DIR}/Lib/Slog.cc)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fPIC -pipe -std=c++11 -fno-exceptions")
set(LIB ${PROJECT_SOURCE_DIR}/Lib)
set(LOG_FILE ${CMAKE_CURRENT_SOURCE_DIR}/log)

file(GLOB_RECURSE INCLUDES "includes/*.h")
file(GLOB_RECURSE LIBS "Lib/*.cc")
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
#如果不加 提示找不到 fatal error: Slog.h: No such file or directory #include "Slog.h"
include_directories(${LIB})


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
#add_executable(server Sources/server-test.cc ${INCLUDES})
#add_executable(client Sources/client-test.cc ${INCLUDES})
#add_executable(server-test2 Sources/server-test2.cc ${INCLUDES})
#set_property(TARGET ${Lib} PROPERTY IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/LOGLIB)

#include_directories(${PROJECT_SOURCE_DIR}) # 头文件的路径
link_directories(${LIB})
find_library (libpath libSlog.a ${LIB})
#find_path(libp Slog.h ${PROJECT_SOURCE_DIR}/Lib)
#find_package(Slog REQUIRED)
message (STATUS "XXXXXXXXXXXXXXXXXXXXXXXXXXXX      ${libpath}")
if (${libpath} STREQUAL "libpath-NOTFOUND")
    message (STATUS "***************************required libSlog library but not found!")
else()
    message (STATUS "--------------------------libpath libSlog found in ${libpath}")
endif()

add_executable(server-test3 ${EXE_SERVER} ${LIBS})
#set(lib_dir ${PROJECT_SOURCE_DIR}/lib)
## 拷贝 src文件夹下的内容  到  save_src_dir 中
#execute_process( COMMAND ${CMAKE_COMMAND} -E copy_directory
#        ${LOG_LIB}/Slog.a
#        ${LOG_LIB}/Slog.so
#        ${lib_dir})

target_link_libraries(server-test3 ${WFREST_LIB} log4cplus)
#target_link_libraries(server-test3 ${LIB}/libSlog.so)
#target_include_directories(server-test3 PUBLIC ${PROJECT_SOURCE_DIR}/Lib)