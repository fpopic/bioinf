cmake_minimum_required(VERSION 3.6)
project(bioinf_cpp)
set(CMAKE_CXX_STANDARD 11)

# gcc
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# set dir for root folder at tuntime , e.g. cin/cout root path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}")

# set dir for compiled libs
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Search for headers .h at compile time in:
include_directories(
        include
        lib
)

# compile subprojects (source of my libs) too
add_subdirectory(lib/mylib)
add_subdirectory(test)

# create run configs executable
add_executable(bioinf_cpp_exe src/main.cpp)

# add libraries to executable
target_link_libraries(bioinf_cpp_exe mylib)