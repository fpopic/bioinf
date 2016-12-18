#include <gtest/gtest.h>
#include "mylib/MyIOLibrary.h"

using namespace std;

TEST(test2, t1) {
    MyIOLibrary myIOLibrary;
    string file = "res/a.txt";

    int expected = 5;

    myIOLibrary.fileToCin(file);
    int actual;
    cin >> actual;

    EXPECT_EQ(actual, expected);
}