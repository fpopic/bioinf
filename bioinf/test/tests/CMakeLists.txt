# to enable include "gtest/gtest.h"
include_directories(${gtest_SOURCE_DIR} ${gtest_SOURCE_DIR}/include)

# here you define runnable exe for tests included:
add_executable(debruijn_tests.exe debruijn_a1_a2_tests.cpp test_utility.h)

# here you add libraries which will test exe use:
target_link_libraries(debruijn_tests.exe gtest gtest_main debruijn sdsl divsufsort divsufsort64)