cmake_minimum_required(VERSION 3.6)
project(bioinf_project)
set(CMAKE_CXX_STANDARD 11)

# gcc (do not use -static flag because google tests needs linker help)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # -O0 -g -pg -Q for gprof

# set dir for root folder at tuntime , e.g. cin/cout root path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}")

# set dir for compiled libs
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Search for headers and source at compile time in:
# This enables include as roots from these directories
include_directories(include lib)

# compile subprojects (source of my libs) too
add_subdirectory(lib/mylib)
add_subdirectory(test)

# create run configs executable
add_executable(bioinf.exe src/main.cpp)
add_executable(bwt_example.exe src/bwt_example.cpp)
add_executable(sa_example.exe src/sa_example.cpp)

add_executable(sdsl_example.exe src/sdsl_example.cpp)
add_executable(
        playground.exe
        src/playground.cpp
        src/utility/utility.h
        src/utility/utility.cpp
)
add_executable(
        brujin_algorithms.exe
        src/brujin_algorithms/brujin_algorithms.h
        src/brujin_algorithms/brujin_algorithms.cpp
        src/utility/utility.h
        src/utility/utility.cpp
)

# add libraries to executable
target_link_libraries(bioinf.exe mylib)

target_link_libraries(sdsl_example.exe sdsl divsufsort divsufsort64)

target_link_libraries(playground.exe sdsl divsufsort divsufsort64)

target_link_libraries(brujin_algorithms.exe sdsl divsufsort divsufsort64)