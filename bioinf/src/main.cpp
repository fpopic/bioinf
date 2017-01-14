#include "debruijn/utility.h"
#include "debruijn/compressed_graph.h"

using namespace std;
using namespace sdsl;

// cmd: res/input/1e6_ecoli.fasta res/input/1e6_ecoli.k A1 res/output/
int main(int argc, char* argv[]) {

    if (argc != 5) {
        cerr << "Usage: ./main_graph.exe <FILE.fasta> <FILE.k> <\"A1\" or \"A2\"> <OUTPUT_FOLDER>";
        return 1;
    }

    string S = Utility::parse_fasta(argv[1]);
    uint64_t k = Utility::parse_k(argv[2]);
    algorithm_t algorithm = Utility::parse_algorithm(argv[3]);

    CompressedDeBruijnGraph graph(S, k, algorithm);

    ofstream out;

    out.open(string(argv[4]) + string(argv[3]) + ".graph");
    out << graph;

//    out.open(string(argv[4] + string(argv[2]) + ".starts"));
//    out << graph.start_node;

    return 0;
}