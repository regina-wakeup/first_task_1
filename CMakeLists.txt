cmake_minimum_required(VERSION 3.10)

project(ip_sort CXX)

include(${PROJECT_SOURCE_DIR}/cmake/conan.cmake)
	conan_cmake_run(
	CONANFILE conanfile.txt
	BASIC_SETUP
	CMAKE_TARGETS
	BUILD
	missing
)

option(BUILD_TESTS "Build unit tests" ON)

include_directories(${PROJECT_SOURCE_DIR}})
add_subdirectory(lib)
add_subdirectory(main)

if(BUILD_TESTS)
	add_subdirectory(tests)
endif()
