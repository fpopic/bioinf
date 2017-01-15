#include <gtest/gtest.h>
#include "test_utility.h"

using namespace std;

TEST(a1, ecoli_1e6) {
    vector<string> argv = {"", "res/input/1e6_ecoli.fasta", "res/input/1e6_ecoli.k", "A1", "res/output/1e6_ecoli."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}

TEST(a1, seq3) {
    vector<string> argv = {"", "res/input/seq_3.fasta", "res/input/seq3.k", "A1", "res/output/seq3."};
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

///////////////////////////

TEST(a2, ecoli_1e6) {
    vector<string> argv = {"", "res/input/1e6_ecoli.fasta", "res/input/1e6_ecoli.k", "A2", "res/output/1e6_ecoli."};
    RUN_BOTH_AND_ASSERT_OUTPUTS(argv);
}

TEST(a2, seq_3) {
    vector<string> argv = {"", "res/input/seq_3.fasta", "res/input/seq3.k", "A2", "res/output/seq3."};
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