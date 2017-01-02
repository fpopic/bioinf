/* Pure utility functions that can be used throughout the project. */

#ifndef BIOINF_PROJECT_UTILITY_H
#define BIOINF_PROJECT_UTILITY_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
void print_vector(vector<T> const &vec, char delimiter = ' ') {
    for (auto element : vec) {
        cout << element << delimiter;
    }
    cout << endl;
}

#endif //BIOINF_PROJECT_UTILITY_H
