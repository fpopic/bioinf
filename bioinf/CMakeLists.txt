cmake_minimum_required(VERSION 3.6)
project(bioinf_project)
set(CMAKE_CXX_STANDARD 11)

# gcc (do not use -static flag because google tests needs linker help)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3") # -O0 -g -pg -Q for gprof  after put -03

# set dir for root folder at tuntime , e.g. cin/cout root path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}")

# set dir for compiled libs
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Search for headers and source at compile time in:
# This enables include as roots from these directories
include_directories(include lib)

# compile subprojects (source of my libs) too
add_subdirectory(lib/debruijn)
add_subdirectory(test)

# create run configs executable
add_executable(debruijn.exe src/main.cpp)

# add libraries to executable
target_link_libraries(debruijn.exe debruijn sdsl divsufsort divsufsort64)