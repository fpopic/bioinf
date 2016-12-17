# to enable include "gtest/gtest.h"
include_directories(${gtest_SOURCE_DIR} ${gtest_SOURCE_DIR}/include)

# here you define runnable exe for tests included:
add_executable(bioinf_tests.exe test1.cpp test2.cpp)

# here you add libraries which will test exe use:
target_link_libraries(bioinf_tests.exe gtest gtest_main)
target_link_libraries(bioinf_tests.exe mylib)