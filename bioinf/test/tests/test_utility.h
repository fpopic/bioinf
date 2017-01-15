#ifndef BIOINF_PROJECT_TEST_UTILITY_H
#define BIOINF_PROJECT_TEST_UTILITY_H

#include <gtest/gtest.h>

#include "debruijn/utility.h"
#include "debruijn/compressed_graph.h"

/* Compare .dot and .start_nodes files from original and corresponding implemented algorithm.*/
void ASSERT_FILES_EQ(uint64_t k, const string& output) {// read actual and expected output
    stringstream actual_ss, expected_ss;
    ifstream actual_file, expected_file;

    //region prepare inputs
    actual_file.open(output + ".actual.k" + to_string(k) + ".dot");
    actual_ss << actual_file.rdbuf();

    expected_file.open(output + ".expected.k" + to_string(k) + ".dot");
    expected_ss << expected_file.rdbuf();
    //endregion

    //region check file sizes
    actual_ss.seekg(0, ios::end);
    auto actual_size = actual_ss.tellg();
    actual_file.seekg(0, ios::beg);

    expected_ss.seekg(0, ios::end);
    auto expected_size = expected_ss.tellg();
    expected_file.seekg(0, ios::beg);

    ASSERT_EQ(actual_size, expected_size);
    //endregion

    // region check char by char
    string a, e;
    for (int i = 0; i < expected_size; ++i) {
        actual_ss >> a;
        expected_ss >> e;
        ASSERT_EQ(a, e);
    }
    // endregion


    //region prepare inputs
    actual_file.open(output + ".actual.k" + to_string(k) + ".start_nodes.txt");
    actual_ss << actual_file.rdbuf();

    expected_file.open(output + ".expected.k" + to_string(k) + ".start_nodes.txt");
    expected_ss << expected_file.rdbuf();
    //endregion

    //region check file sizes
    actual_ss.seekg(0, ios::end);
    actual_size = actual_ss.tellg();
    actual_file.seekg(0, ios::beg);

    expected_ss.seekg(0, ios::end);
    expected_size = expected_ss.tellg();
    expected_file.seekg(0, ios::beg);

    ASSERT_EQ(actual_size, expected_size);
    //endregion

    // region check char by char
    for (int i = 0; i < expected_size; ++i) {
        actual_ss >> a;
        expected_ss >> e;
        ASSERT_EQ(a, e);
    }
    // endregion

}

/*  Run original algorithm and corresponding implemented algorithm. */
void RUN_BOTH_AND_ASSERT_OUTPUTS(vector<string>& argv) {
    string S = Utility::parse_fasta(argv[1]);
    uint64_t k = Utility::parse_k(argv[2]);
    algorithm_t algorithm = Utility::parse_algorithm(argv[3]);
    string output = string(argv[4]) + string(argv[3]); // output folder / Ax

    //run expected algorithm
    string cmd = "./res/exe/a" + to_string(algorithm) + ".x " + string(argv[1]) + " " + output + ".expected " + string(argv[2]);
    int ok = system(cmd.c_str());

    //run actual algorithm
    CompressedDeBruijnGraph graph(S, k, algorithm);
    ofstream out;

    out.open(output + ".actual.k" + to_string(k) + ".dot");
    out << graph << endl;
    out.close();

    out.open(output + ".actual.k" + to_string(k) + ".start_nodes");
    for (auto start : graph.start_nodes) out << start << endl;
    out.close();

    ASSERT_FILES_EQ(k, output);
}

#endif //BIOINF_PROJECT_TEST_UTILITY/_H