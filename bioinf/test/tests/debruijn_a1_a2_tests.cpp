#include <gtest/gtest.h>
#include "test_utility.h"

using namespace std;

TEST(a1, ecoli_1m_chars) {
    vector<string> argv = {"", "res/input/ecoli_1m_chars.fasta", "res/input/ecoli_1m_chars.k", "A1", "res/output/1e6_ecoli."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}

TEST(a1, seq3) {
    vector<string> argv = {"", "res/input/seq_3.fasta", "res/input/seq_3.k", "A1", "res/output/seq3."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}

TEST(a1, paper_example) {
    vector<string> argv = {"", "res/input/paper_example.fasta", "res/input/paper_example.k", "A1", "res/output/paper_example."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}

TEST(a1, slides_example) {
    vector<string> argv = {"", "res/input/slides_example.fasta", "res/input/slides_example.k", "A1", "res/output/slides_example."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}

TEST(a1, ecoli_1x1e5) {
    vector<string> argv = {"", "res/input/ecoli_1x1e5.fasta", "res/input/10.k", "A1", "res/output/ecoli_1x1e5."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}

// 28.23MB output
TEST(a1, ecoli_1x1e6) {
    vector<string> argv = {"", "res/input/ecoli_1x1e6.fasta", "res/input/10.k", "A1", "res/output/ecoli_1x1e6."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}

TEST(a1, ecoli_10x1e2) {
    vector<string> argv = {"", "res/input/ecoli_10x1e2.fasta", "res/input/10.k", "A1", "res/output/ecoli_10x1e2."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}

TEST(a1, ecoli_10x1e3) {
    vector<string> argv = {"", "res/input/ecoli_10x1e3.fasta", "res/input/10.k", "A1", "res/output/ecoli_10x1e3."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}

TEST(a1, ecoli_10x1e4) {
    vector<string> argv = {"", "res/input/ecoli_10x1e4.fasta", "res/input/10.k", "A1", "res/output/ecoli_10x1e4."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}

TEST(a1, ecoli_reference) {
    vector<string> argv = {"", "res/input/ecoli_reference.fasta", "res/input/10.k", "A1", "res/output/ecoli_reference."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}


///////////////////////////


TEST(a2, ecoli_1m_chars) {
    vector<string> argv = {"", "res/input/ecoli_1m_chars.fasta", "res/input/ecoli_1m_chars.k", "A2", "res/output/1e6_ecoli."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}

TEST(a2, seq_3) {
    vector<string> argv = {"", "res/input/seq_3.fasta", "res/input/seq_3.k", "A2", "res/output/seq3."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}

TEST(a2, paper_example) {
    vector<string> argv = {"", "res/input/paper_example.fasta", "res/input/paper_example.k", "A2", "res/output/paper_example."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}

TEST(a2, slides_example) {
    vector<string> argv = {"", "res/input/slides_example.fasta", "res/input/slides_example.k", "A2", "res/output/slides_example."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}

TEST(a2, ecoli_1x1e5) {
    vector<string> argv = {"", "res/input/ecoli_1x1e5.fasta", "res/input/10.k", "A2", "res/output/ecoli_1x1e5."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}

TEST(a2, ecoli_1x1e6) {
    vector<string> argv = {"", "res/input/ecoli_1x1e6.fasta", "res/input/10.k", "A2", "res/output/ecoli_1x1e6."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}

TEST(a2, ecoli_10x1e2) {
    vector<string> argv = {"", "res/input/ecoli_10x1e2.fasta", "res/input/10.k", "A2", "res/output/ecoli_10x1e2."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}

TEST(a2, ecoli_10x1e3) {
    vector<string> argv = {"", "res/input/ecoli_10x1e3.fasta", "res/input/10.k", "A2", "res/output/ecoli_10x1e3."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}

TEST(a2, ecoli_10x1e4) {
    vector<string> argv = {"", "res/input/ecoli_10x1e4.fasta", "res/input/10.k", "A2", "res/output/ecoli_10x1e4."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}