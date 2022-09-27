cmake_minimum_required(VERSION 3.22)
project(inforefiner-model)

set(CMAKE_CXX_STANDARD 14)
#set(CXX_FLAGS
#        -Wall
#        -std=c++14
#        -lpthread
#        -Wno-unused-parameter
#        -03
#        )
link_libraries(pthread)
include_directories("includes")
find_package(OpenSSL REQUIRED)
find_package(wfrest REQUIRED CONFIG HINTS ..)
find_package(workflow REQUIRED CONFIG HINTS ..)
include_directories(
        ${OPENSSL_INCLUDE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
        ${WORKFLOW_INCLUDE_DIR}
        ${WFREST_INCLUDE_DIR}
)
link_directories(${WFREST_LIB_DIR} ${WORKFLOW_LIB_DIR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fPIC -pipe -std=c++11 -fno-exceptions")
file(GLOB_RECURSE INCLUDES "includes/*.h")
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
add_executable(server-test3 Sources/server-test3.cc)
target_link_libraries(server-test3 ${WFREST_LIB} log4cplus)