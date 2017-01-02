#include "brujin_algorithms.h"

#include <iostream>
#include <sdsl/suffix_arrays.hpp>
#include <sdsl/lcp.hpp>

using namespace std;
using namespace sdsl;

// Algorithm1.
vector<Node *> create_compress_graph(const uint64_t &k, csa_wt<> &csa, lcp_wt<> &lcp) {
    bool open = false;
    uint64_t counter = 1;

    vector<Node *> graph;
    queue<Node *> queue;

    bit_vector B(csa.size(), 0);

    vector<uint64_t> lex_smaller_table(256, 0);
    for (uint64_t i = 0, sum = 0; i < 256; ++i) {
        lex_smaller_table[i] = sum;
        sum += csa.wavelet_tree.rank(csa.wavelet_tree.size(), i);
    }

//    lb will be initialized, I promise. See line below.
    for (uint64_t i = 0, lb; i < csa.size(); ++i) {
        if (lcp[i] < k and open) {
            open = false;
            B[i - 1] = 1;

            Node *node = new Node(counter, lb, i - 1, k); // DRY
            graph.push_back(node);
            queue.push(node);
            counter++;
        } else if (lcp[i] == k and not open) {
            B[lb] = 1;
            open = true;
        }

        if (lcp[i] < k) {
            lb = i;
        }
    }

    bit_vector::rank_1_type bv_rank;
    util::init_support(bv_rank, &B);

    Node *stop_node = new Node(counter, 1, 1, 1);
    graph.push_back(stop_node); // Add stopnode.
    queue.push(stop_node);
    counter++;

//    PASS
    uint64_t quantity;
    vector<uint8_t> cs(csa.wavelet_tree.sigma);
    vector<uint64_t> rank_c_i(csa.wavelet_tree.sigma);
    vector<uint64_t> rank_c_j(csa.wavelet_tree.sigma);
    while (not queue.empty()) {
        Node *node = queue.front();
        queue.pop();
        bool extendable;

        do { // "repeat"
            extendable = false;
            interval_symbols(csa.wavelet_tree, node->lb, node->rb, quantity, cs, rank_c_i, rank_c_j);

            for (uint64_t i = 0; i < quantity; ++i) {
                uint8_t c = cs[i]; // Onaj u lijevo za jedan.
                uint64_t lb = lex_smaller_table[c] + rank_c_i[i];
                uint64_t rb = lex_smaller_table[c] + rank_c_j[i] - 1;
                uint64_t ones = bv_rank(lb + 1);
                uint64_t id;

                if (ones % 2 == 0 and B[i] == 0) {
                    id = ground;
                } else {
                    id = (ones + 1) / 2;
                }

                if (id != ground) {
                    graph[node->id]->successors.push_back(make_pair(node->id, rb - lb + 1)); //DRY
                    graph[node->id]->lb = node->lb;
                    graph[node->id]->rb = node->rb;
                    graph[node->id]->len = node->len;
                } else if (c <= 1) {
                    graph[node->id]->lb = node->lb;
                    graph[node->rb]->rb = node->rb;
                    graph[node->id]->len = node->len;
//                    start_nodes?
                } else if (not c <= 1) {
                    if (quantity == 1) {
                        extendable = true;
                        node->len++;
                        node->lb = lb;
                        node->rb = rb;
                    } else {
                        Node *new_node = new Node(counter, lb, rb, k);
                        graph.push_back(new_node);

                        graph[node->id]->successors.push_back(make_pair(node->id, rb - lb + 1)); //DRY
                        graph[node->id]->lb = node->lb;
                        graph[node->id]->rb = node->rb;
                        graph[node->id]->len = node->len;

                        queue.push(new_node);
                        counter++;
                    }
                }
            }
        } while (extendable);
    }
    return graph;
}

// Only for development purposes. When the project is done this may as well be deleted.
int main() {
    string input_string = "ACTACGTACGTACG"; // Notice no explicit dollar!

    csa_wt<> csa;
    construct_im(csa, input_string, 1);

    //region GET_INTERVALS
    lcp_wt<> lcp;
    construct_im(lcp, input_string, 1);

    cout << "Brujin:" << endl;
    vector<Node *> brojin = create_compress_graph(3, csa, lcp);
    for (int i = 0; i < brojin.size(); ++i) {
        cout << brojin[i]->id << endl;
    }
    cout << endl;
    //endregion
}
