#include "algorithms/de_bruijin_graph.h"
#include "utility/utility.h"

using namespace std;
using namespace sdsl;

int main() {
    string S = parse_fast_a("1M_ecoli.fasta");

    DeBruijinGraph graph(S);

    DeBruijinGraph::print_graph(graph);
}