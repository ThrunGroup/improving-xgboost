cmake_minimum_required(VERSION 3.18)

project(dummy LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

find_package(xgboost REQUIRED)
add_executable(dummy dummy.cc)
target_link_libraries(dummy xgboost::xgboost)
