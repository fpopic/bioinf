# to enable include "gtest/gtest.h"
include_directories(${gtest_SOURCE_DIR} ${gtest_SOURCE_DIR}/include)

# here you define runnable exe for tests included:
add_executable(bioinf_tests.exe sais_tests.cpp mylib_tests.cpp debruijn_tests.cpp)

# here you add libraries which will test exe use:
target_link_libraries(bioinf_tests.exe gtest gtest_main)
target_link_libraries(bioinf_tests.exe debruijn)
