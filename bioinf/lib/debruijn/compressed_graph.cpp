#include "compressed_graph.h"

CompressedDeBruijnGraph::CompressedDeBruijnGraph(string S, const uint64_t& k, algorithm_t A) {

    // BWT of S
    string bwt(S.size(), ' ');
    vector<int> temp(S.size());
    auto bwt_dollar = saisxx_bwt(S.begin(), bwt.begin(), temp.begin(), (int) S.size());
    bwt.insert(bwt_dollar, 1, 1);

    // WT on BWT
    wt_huff<> wt;
    construct_im(wt, bwt, 1);

    // LCP of S
    lcp_wt<> lcp;
    construct_im(lcp, S, 1);

    // Algorithm 1
    Triple triple = ConstructionAlgorithms::create_compressed_graph(k, wt, lcp);

    this->vertices = triple.nodes;
    this->start_nodes = triple.start_nodes;
    this->edges = triple.edges;

    // CSA of S
    csa_bitcompressed<> csa;
    construct_im(csa, S, 1);

    if (A == 1)
        ConstructionAlgorithms::finish_graph_A1(csa, this->vertices, this->edges);
    else
        ConstructionAlgorithms::finish_graph_A2(csa, this->vertices);
}

ostream& operator<<(ostream& os, const CompressedDeBruijnGraph& graph) {
    os << "digraph G {" << endl;
    for (Node* node : graph.vertices) {
        os << *node;
    }
    os << "}";
    return os;
}