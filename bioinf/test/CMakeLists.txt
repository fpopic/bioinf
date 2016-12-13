#here you define independent project (subproject) with it's subdirectories
project(bioinf_cpp_tests)

# set dir for root folder at tuntime , e.g. cin/cout root path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}")


add_subdirectory(lib/gtest-1.8.0)
add_subdirectory(tests)

