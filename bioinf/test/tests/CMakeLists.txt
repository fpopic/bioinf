#to enable include "gtest/gtest.h"

include_directories(
        ${gtest_SOURCE_DIR}
        ${gtest_SOURCE_DIR}/include
)

# here you define runnable exe for tests included:
add_executable(bioinf_cpp_tests_exe test1.cpp test2.cpp)

# here you add libraries which will test exe use:
target_link_libraries(bioinf_cpp_tests_exe gtest gtest_main)
target_link_libraries(bioinf_cpp_tests_exe mylib)