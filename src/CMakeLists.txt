cmake_minimum_required(VERSION 3.1)
project(ip_sort CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(ip_sort ip_sort.cpp)
