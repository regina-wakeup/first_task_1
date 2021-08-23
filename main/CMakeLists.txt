add_executable(ip_sort main.cpp)

target_include_directories(ip_sort PUBLIC lib)
target_link_libraries(ip_sort ip_converter)