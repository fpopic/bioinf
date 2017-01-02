#ifndef BIOINF_PROJECT_BRUJIN_ALGORITHMS_H
#define BIOINF_PROJECT_BRUJIN_ALGORITHMS_H

#include <utility>
#include <ostream>
#include <vector>
#include <limits>

using namespace std;

/** This value +1 = alphabet size. */
const int alphabet_index = 4;

/** Algorithms need this to exist. Sorted alphabet of possible letters. */
const char alphabet[alphabet_index + 1] = {'$', 'T', 'G', 'C', 'A'};

const uint64_t ground = numeric_limits<uint64_t>::max();

struct Node {
    uint64_t id;
    uint64_t lb;
    uint64_t rb;
    uint64_t len;

    /** target node, edge multiplicity */
    vector<pair<uint64_t, uint64_t >> successors;

    Node(uint64_t id, uint64_t lb, uint64_t rb, uint64_t len) : id(id), lb(lb), rb(rb), len(len) {}

    friend ostream &operator<<(ostream &os, const Node &node) {
        os << "id: " << node.id << " lb: " << node.lb << " rb: " << node.rb << " len: " << node.len;
        return os;
    }
};

#endif //BIOINF_PROJECT_BRUJIN_ALGORITHMS_H
