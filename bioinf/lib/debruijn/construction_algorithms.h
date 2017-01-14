#ifndef BIOINF_PROJECT_BRUJIN_ALGORITHMS_H
#define BIOINF_PROJECT_BRUJIN_ALGORITHMS_H

#include <sdsl/suffix_arrays.hpp>
#include <sdsl/lcp.hpp>

using namespace std;
using namespace sdsl;

typedef int algorithm_t;

struct Node {
    uint64_t id;
    uint64_t lb;
    uint64_t rb;
    uint64_t len;
    vector<uint64_t> adjList;
    vector<uint64_t> posList;
    bool is_exit;

    Node(uint64_t id, uint64_t lb, uint64_t rb, uint64_t len, bool is_exit = false) : id(id), lb(lb), rb(rb), len(len), is_exit(is_exit) {}

    friend ostream& operator<<(ostream& os, const Node& node);
};

struct Edge {
    uint64_t start;
    uint64_t end;
    uint64_t multiplicity;

    Edge(uint64_t start, uint64_t end, uint64_t multiplicity) : start(start), end(end), multiplicity(multiplicity) {}
};

class ConstructionAlgorithms {

public:

    /* Algorithm 1 */
    static pair<vector<Node*>, vector<Edge>> create_compressed_graph(const uint64_t& k, const wt_huff<>& wta, const lcp_wt<>& lcp);

    /* A1 */
    static void finish_graph_A1(const csa_bitcompressed<>& csa, vector<Node*>& vertices, const vector<Edge>& edges);

    /* A2 */
    static void finish_graph_A2(const csa_bitcompressed<>& csa, vector<Node*>& vertices);

private:

    /* Ground value from pseudocode */
    static const uint64_t GND;

};

#endif //BIOINF_PROJECT_BRUJIN_ALGORITHMS_H