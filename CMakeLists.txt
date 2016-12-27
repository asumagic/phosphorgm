cmake_minimum_required(VERSION 2.8)
project(gmsc)

set(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -flto")

file(GLOB_RECURSE sources "*.cpp")
add_executable(${PROJECT_NAME} ${sources})

file(GLOB_RECURSE headers "*.hpp")
add_custom_target(headers SOURCES ${headers})
