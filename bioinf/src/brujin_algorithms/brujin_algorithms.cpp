#include "brujin_algorithms.h"

#include <iostream>
#include <sdsl/suffix_arrays.hpp>
#include <sdsl/lcp.hpp>
#include <sais.hxx>

using namespace std;
using namespace sdsl;

// Algorithm1.
pair<vector<Node *>, vector<Edge>> create_compress_graph(const uint64_t &k, wt_huff<> &wta, lcp_wt<> &lcp) {
    bool open = false;
    uint64_t counter = 1;

    vector<Node *> graph;
    vector<Edge> edges;
    queue<Node *> queue;

    bit_vector B(wta.size(), 0);

    vector<uint64_t> lex_smaller_table(256, 0);
    for (uint64_t i = 0, sum = 0; i < 256; ++i) {
        lex_smaller_table[i] = sum;
        sum += wta.rank(wta.size(), i);
    }

//    lb will be initialized, I promise. See line below.
    for (uint64_t i = 0, lb; i < wta.size(); ++i) {
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

    Node *stop_node = new Node(counter, 0, 0, 1);
    graph.push_back(stop_node); // Add stopnode.
    queue.push(stop_node);
    counter++;

//    PASS
    uint64_t quantity;
    vector<uint8_t> cs(wta.sigma);
    vector<uint64_t> rank_c_i(wta.sigma);
    vector<uint64_t> rank_c_j(wta.sigma);
    while (not queue.empty()) {
        Node *node = queue.front();
        queue.pop();
        bool extendable;

        do { // "repeat"
            extendable = false;
            interval_symbols(wta, node->lb, node->rb + 1, quantity, cs, rank_c_i, rank_c_j);

            for (uint64_t iter = 0; iter < quantity; ++iter) {
                uint8_t c = cs[iter]; // Onaj u lijevo za jedan.
                uint64_t lb = lex_smaller_table[c] + rank_c_i[iter];
                uint64_t rb = lex_smaller_table[c] + rank_c_j[iter] - 1;
                uint64_t ones = bv_rank(lb + 1);
                uint64_t id;

                if (ones % 2 == 0 and B[lb] == 0) {
                    id = ground;
                } else {
                    id = (ones + 1) / 2;
                }

                if (id != ground) {
                    edges.push_back(Edge(id, node->id, rb - lb + 1));
                } else if (c > 1) {
                    if (quantity == 1) {
                        extendable = true;
                        node->len++;
                        node->lb = lb;
                        node->rb = rb;
                    } else {
                        Node *new_node = new Node(counter, lb, rb, k);
                        graph.push_back(new_node);
                        edges.push_back(Edge(counter, node->id, rb - lb + 1));

                        queue.push(new_node);
                        counter++;
                    }
                }
            }
        } while (extendable);
    }

    return make_pair(graph, edges);
}

// Only for development purposes. When the project is done this may as well be deleted.
int main() {
    string input_string = "ACTACGTACGTACG"; // Notice no explicit dollar!

//    BWT construction
    string bwt(input_string.size(), ' ');
    vector<int> temp(input_string.size());
    int btw_dollar_index =
            saisxx_bwt(input_string.begin(), bwt.begin(), temp.begin(), (int) input_string.size());

    bwt.insert(btw_dollar_index, 1, 1);

    cout << bwt << endl;

    wt_huff<> wta;
    construct_im(wta, bwt, 1);

    //region GET_INTERVALS
    lcp_wt<> lcp;
    construct_im(lcp, input_string, 1);

    cout << "Vertices:" << endl;
    pair<vector<Node *>, vector<Edge>> graph_edges = create_compress_graph(3, wta, lcp);
    vector<Node *> brojin = graph_edges.first;
    for (int i = 0; i < brojin.size(); ++i) {
        cout << brojin[i]->id << " " << brojin[i]->lb << " " << brojin[i]->rb << endl;
    }
    cout << endl;

    cout << "Edges:" << endl;
    vector<Edge> edges = graph_edges.second;
    for (int i = 0; i < edges.size(); ++i) {
        cout << edges[i] << endl;
    }
    cout << endl;
    //endregion
}
