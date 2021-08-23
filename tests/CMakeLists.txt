add_executable(first_task_1_tests test_converter.cpp)
target_link_libraries(first_task_1_tests ip_converter CONAN_PKG::gtest)
add_custom_target(
    test $<TARGET_FILE:first_task_1_tests> 
    DEPENDS first_task_1_tests
)
