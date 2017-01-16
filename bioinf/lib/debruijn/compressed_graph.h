#ifndef BIOINF_PROJECT_GRAPH_H
#define BIOINF_PROJECT_GRAPH_H

// C++
#include <ostream>

// BIOINF
#include <sdsl/suffix_arrays.hpp>
#include <sdsl/lcp.hpp>
#include <sais.hxx>

// DEBRUIJN
#include "construction_algorithms.h"

using namespace std;
using namespace sdsl;

struct CompressedDeBruijnGraph {
    vector<Node*> vertices;
    vector<Edge> edges;
    vector<uint64_t> start_nodes;

    CompressedDeBruijnGraph(string& input_file, const uint64_t& k, algorithm_t finish_algorithm);

    friend ostream& operator<<(ostream& os, const CompressedDeBruijnGraph& graph);
};

#endif //BIOINF_PROJECT_GRAPH_H