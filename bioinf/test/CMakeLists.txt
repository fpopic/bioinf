#here you define independent project (subproject) with it's subdirectories
project(bioinf_tests)

# set dir for root folder at tuntime , e.g. cin/cout root path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}")

# set dir for compiled libs
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_subdirectory(lib/gtest-1.8.0)
add_subdirectory(tests)