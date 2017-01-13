#ifndef BIOINF_PROJECT_GRAPH_H
#define BIOINF_PROJECT_GRAPH_H

#include <ostream>
#include <iostream>
#include <vector>
#include <limits>
#include <utility>
#include <sdsl/suffix_arrays.hpp>
#include <sdsl/lcp.hpp>
#include <sais.hxx>

using namespace std;
using namespace sdsl;

struct Node {
    uint64_t id;
    uint64_t lb;
    uint64_t rb;
    uint64_t len;
    vector<uint64_t> adjList;
    vector<uint64_t> posList;
    bool is_exit;

    Node(uint64_t id, uint64_t lb, uint64_t rb, uint64_t len, bool is_exit = false) : id(id), lb(lb), rb(rb), len(len), is_exit(is_exit) {}

    friend ostream& operator<<(ostream& os, const Node& node) {
        os << "id: " << node.id << " lb: " << node.lb << " rb: " << node.rb << " len: " << node.len;
        return os;
    }
};

struct Edge {
    uint64_t start;
    uint64_t end;
    uint64_t multiplicity;

    Edge(uint64_t start, uint64_t end, uint64_t multiplicity) : start(start), end(end), multiplicity(multiplicity) {}

    friend ostream& operator<<(ostream& os, const Edge& edge) {
        os << "start: " << edge.start << " end: " << edge.end << " multiplicity: " << edge.multiplicity;
        return os;
    }
};

struct DeBruijinGraph {

    vector<Node*> vertices;
    vector<Edge> edges;

    DeBruijinGraph(string input_file);

    //print
    static void print_graph(DeBruijinGraph& graph);

};

#endif //BIOINF_PROJECT_GRAPH_H
