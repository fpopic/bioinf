#ifndef BIOINF_PROJECT_BRUJIN_ALGORITHMS_H
#define BIOINF_PROJECT_BRUJIN_ALGORITHMS_H

#include <ostream>
#include <iostream>
#include <vector>
#include <limits>
#include <utility>
#include <sdsl/suffix_arrays.hpp>
#include <sdsl/lcp.hpp>
#include <sais.hxx>

#include "de_bruijin_graph.h"

using namespace std;
using namespace sdsl;

/** This value +1 = alphabet size. */
const int alphabet_index = 4;

/** Algorithms need this to exist. Sorted alphabet of possible letters. */
const char alphabet[alphabet_index + 1] = {'$', 'T', 'G', 'C', 'A'};

const uint64_t GND = numeric_limits<uint64_t>::max();

class DeBruijinAlgorithms {

public:

    //Algorithm1
    static pair<vector<Node*>, vector<Edge>> create_compress_graph(const uint64_t& k, wt_huff<>& wta, lcp_wt<>& lcp);

    //A1
    static void finishGraphA1(vector<Node*>& graph, vector<Edge>& edges, csa_bitcompressed<>& csa);

    //A2
    static void finishGraphA2(vector<Node*>& graph, csa_bitcompressed<>& csa);

};

#endif //BIOINF_PROJECT_BRUJIN_ALGORITHMS_H
