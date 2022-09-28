cmake_minimum_required(VERSION 3.22)
project(inforefiner-model)

set(CMAKE_CXX_STANDARD 14)
set(EXE_SERVER ${PROJECT_SOURCE_DIR}/Sources/server-test3.cc)
set(SLOG_SRC ${PROJECT_SOURCE_DIR}/LogLib/Slog.cc)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fPIC -pipe -std=c++11 -fno-exceptions")
set(LOG_LIB ${PROJECT_SOURCE_DIR}/LogLib)
set(LOG_FILE ${CMAKE_CURRENT_SOURCE_DIR}/log)

# 创建 public_include 指向的文件夹
execute_process( COMMAND ${CMAKE_COMMAND} -E make_directory ${LOG_FILE})
#set(CXX_FLAGS
#        -Wall
#        -std=c++14
#        -lpthread
#        -Wno-unused-parameter
#        -03
#        )
link_libraries(pthread)
include_directories(${LOG_LIB})
find_package(OpenSSL REQUIRED)
find_package(wfrest REQUIRED CONFIG HINTS ..)
find_package(workflow REQUIRED CONFIG HINTS ..)
#include_directories(
#        ${OPENSSL_INCLUDE_DIR}
#        ${CMAKE_CURRENT_BINARY_DIR}
#        ${WORKFLOW_INCLUDE_DIR}
#        ${WFREST_INCLUDE_DIR}
#        ${LOG_LIB}
#)
link_directories(${WFREST_LIB_DIR} ${WORKFLOW_LIB_DIR})

file(GLOB_RECURSE INCLUDES "includes/*.h")

ADD_SUBDIRECTORY(LogLib LOGLIB)
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
#set_property(TARGET ${LogLib} PROPERTY IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/LOGLIB)

#include_directories(${PROJECT_SOURCE_DIR}) # 头文件的路径
#link_directories(${LogLib})
find_library (libpath libSlog ${LogLib})

if (${libpath} STREQUAL "libpath-NOTFOUND")
    message (STATUS "***************************required libSlog library but not found!")
else()
    message (STATUS "--------------------------libpath libSlog found in ${libpath}")
endif()

add_executable(server-test3 ${EXE_SERVER} ${SLOG_SRC})
target_link_libraries(server-test3 ${WFREST_LIB} log4cplus)
#target_link_libraries(server-test3 PRIVATE ${LogLib})
#target_include_directories(server-test3 PUBLIC ${PROJECT_SOURCE_DIR}/LogLib)