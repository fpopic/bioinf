/* Pure utility functions that can be used throughout the project. */

#ifndef BIOINF_PROJECT_UTILITY_H
#define BIOINF_PROJECT_UTILITY_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

struct Utility {

    static uint64_t parse_k(string file_path);

    static string parse_fasta(string file_path);

    static int parse_algorithm(string algorithm);

};

#endif //BIOINF_PROJECT_UTILITY_H
