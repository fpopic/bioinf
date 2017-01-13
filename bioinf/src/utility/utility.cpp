/* Pure utility functions that can be used throughout the project. */

#include "utility.h"

template<typename T>
void print_vector(vector<T> const& vec, char delimiter) {
    for (auto element : vec) {
        cout << element << delimiter;
    }
    cout << endl;
}

string parse_fast_a(string file_name) {
    ifstream in(file_name);

    string result;
    int num_of_strings = 0;

    string line;
    while (getline(in, line)) {
        if (line[0] == '>') {
            if (num_of_strings != 0) {
                result.resize(result.size() + 1);
                result[result.size() - 1] = 1;
            }
            num_of_strings++;
            continue;
        }
        result += line;
    }
//    result.resize(result.size() + 1);
//    result[result.size() - 1] = 0;
    return result;
}