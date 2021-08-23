add_library(ip_converter ip_converter.h ip_converter.cpp)

target_include_directories(ip_converter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(ip_converter PUBLIC cxx_std_17)