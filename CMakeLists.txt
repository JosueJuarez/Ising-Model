cmake_minimum_required(VERSION 3.21.4)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(IsingModel VERSION 1.0)
add_executable(IsingModel main.cpp)

target_include_directories(IsingModel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)