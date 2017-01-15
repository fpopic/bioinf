#include "debruijn/utility.h"
#include "debruijn/compressed_graph.h"

using namespace std;
using namespace sdsl;

// cmd: res/input/ecoli_1m_chars.fasta res/input/ecoli_1m_chars.k A1 res/output/
int main(int argc, char* argv[]) {

    if (argc != 5) {
        cerr << "Usage: ./debruijn.exe <FILE.fasta> <FILE.k> <\"A1\" or \"A2\"> <OUTPUT_FOLDER>";
        return 1;
    }

    string S = Utility::parse_fasta(argv[1]);
    uint64_t k = Utility::parse_k(argv[2]);
    algorithm_t algorithm = Utility::parse_algorithm(argv[3]);

    CompressedDeBruijnGraph graph(S, k, algorithm);

    ofstream out;
    string output = string(argv[4]) + string(argv[3]);

    out.open(output + ".actual.k" + to_string(k) + ".dot");
    out << graph << endl;
    out.close();

    out.open(output + ".actual.k" + to_string(k) + ".start_nodes");
    for (auto start : graph.start_nodes) out << start << endl;
    out.close();

    return 0;
}