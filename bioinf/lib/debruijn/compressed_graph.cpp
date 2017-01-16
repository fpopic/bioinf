#include "compressed_graph.h"
#include <cfloat>
#include <chrono>

typedef chrono::high_resolution_clock Time;
typedef chrono::duration<float> fsec;

CompressedDeBruijnGraph::CompressedDeBruijnGraph(string& S, const uint64_t& k, algorithm_t A) {

    // BWT of S
    string bwt(S.size(), ' ');
    vector<int> temp(S.size());
    auto bwt_dollar = saisxx_bwt(S.begin(), bwt.begin(), temp.begin(), (int) S.size());
    bwt.insert(bwt_dollar, 1, 1);

    // WT on BWT
    wt_huff<> wt;
    construct_im(wt, bwt, 1);

    // LCP of S
    lcp_bitcompressed<> lcp;
    construct_im(lcp, S, 1);

    // CSA of S
    csa_bitcompressed<> csa;
    construct_im(csa, S, 1);

    auto start = Time::now();
    fsec elapsed_seconds;
    cout << "Time=" << elapsed_seconds.count() << endl;

    // Algorithm 1
    ConstructionAlgorithms::create_compressed_graph(k, wt, lcp, this->vertices, this->start_nodes, this->edges);

    if (A == 1)
        ConstructionAlgorithms::finish_graph_A1(csa, this->vertices, this->edges);
    else
        ConstructionAlgorithms::finish_graph_A2(csa, this->vertices);
    elapsed_seconds = Time::now() - start;
    cout << "Construction and A12 total time=" << elapsed_seconds.count() << endl;
}

ostream& operator<<(ostream& os, const CompressedDeBruijnGraph& graph) {
    os << "digraph G {" << endl;
    for (Node* node : graph.vertices) {
        os << *node;
    }
    os << "}";
    return os;
}
