#include "construction_algorithms.h"


#include <cfloat>
#include <chrono>

using namespace std;

typedef chrono::high_resolution_clock Time;
typedef chrono::duration<float> fsec;


const uint64_t ConstructionAlgorithms::GND = numeric_limits<uint64_t>::max();

/*
 * Created by Deni Munjas, Filip Popic
 */
void ConstructionAlgorithms::create_compressed_graph(const uint64_t& k, const wt_huff<>& wt, const lcp_wt<>& lcp,
                                                     vector<Node*>& graph, vector<uint64_t>& start_nodes, vector<Edge>& edges) {
    bool open = false;
    uint64_t counter = 0;

    queue<Node*> queue;

    bit_vector B(wt.size(), 0);

    vector<uint64_t> lex_smaller_table(256, 0);
    for (uint64_t i = 0, sum = 0; i < 256; ++i) {
        lex_smaller_table[i] = sum;
        sum += wt.rank(wt.size(), i);
    }

    uint64_t lb = 0;
    for (uint64_t i = 0; i < wt.size(); ++i) {
        if (lcp[i] < k and open) {
            open = false;
            B[i - 1] = 1;
            Node* node = new Node(counter, lb, i - 1, k); // DRY
            graph.push_back(node);
            queue.push(node);
            counter++;
        }
        else if (lcp[i] == k and not open) {
            B[lb] = 1;
            open = true;
        }

        if (lcp[i] < k) {
            lb = i;
        }
    }
    if (open) {
        Node* node = new Node(counter, lb, wt.size() - 1, k); // DRY
        graph.push_back(node);
        queue.push(node);
        B[wt.size() - 1] = 1;
        counter++;
    }

    bit_vector::rank_1_type bv_rank;
    util::init_support(bv_rank, &B);


    // region Adding stop nodes
//    Node* stop_node = new Node(counter, 0, 0, 1);
//    graph.push_back(stop_node);
//    queue.push(stop_node);
//    counter++;
    for (uint64_t i = lex_smaller_table[1]; i < lex_smaller_table[2]; ++i) {
        Node* stop_node = new Node(counter, i, i, 1, true);
        graph.push_back(stop_node);
        queue.push(stop_node);
        counter++;
    }
    //endregion

    auto start = Time::now();
    fsec elapsed_seconds;
    printf("Time=%fs\n", elapsed_seconds.count());

    uint64_t quantity;
    vector<uint8_t> cs(wt.sigma);
    vector<uint64_t> rank_c_i(wt.sigma);
    vector<uint64_t> rank_c_j(wt.sigma);

    while (not queue.empty()) {
        Node* node = queue.front();
        queue.pop();
        bool extendable;

        do {
            extendable = false;
            interval_symbols(wt, node->lb, node->rb + 1, quantity, cs, rank_c_i, rank_c_j);

            for (uint64_t iter = 0; iter < quantity; ++iter) {
                uint8_t c = cs[iter]; // Onaj u lijevo za jedan.
                uint64_t lb = lex_smaller_table[c] + rank_c_i[iter];
                uint64_t rb = lex_smaller_table[c] + rank_c_j[iter] - 1;
                uint64_t ones = bv_rank(lb + 1);
                uint64_t id;

                id = GND;
                if (ones % 2 == 0 and B[lb] == 0) {

                }
                else {
                    id = (ones + 1) / 2;
                }

                if (id != GND) {
                    edges.push_back(Edge(id - 1, node->id, rb - lb + 1));
                }

                else if (c == 1) {
                    start_nodes.push_back(node->id);
                }
                else if (c > 1) {
                    if (quantity == 1) {
                        extendable = true;
                        node->len++;
                        node->lb = lb;
                        node->rb = rb;
                    }
                    else {
                        Node* new_node = new Node(counter, lb, rb, k);
                        graph.push_back(new_node);
                        edges.push_back(Edge(counter, node->id, rb - lb + 1));
                        queue.push(new_node);
                        counter++;
                    }
                }
            }
        } while (extendable);
    }

    elapsed_seconds = Time::now() - start;
    printf("Elapsed=%f\n", elapsed_seconds.count());
}

/*
 * Created by Dario Smolcic
 */
void ConstructionAlgorithms::finish_graph_A1(const csa_bitcompressed<>& csa, vector<Node*>& vertices, const vector<Edge>& edges) {
    for (const Edge& edge: edges) {
        Node* start_node = vertices[edge.start];
        for (int i = 0; i < edge.multiplicity; ++i) {
            start_node->adjList.push_back(edge.end);
        }
    }
    for (Node* node: vertices) {
        for (uint64_t i = node->lb; i <= node->rb; ++i) {
            auto csa_i = csa[i];
            node->posList.push_back(csa_i);
        }
        sort(node->posList.begin(), node->posList.end());
        reverse(node->adjList.begin(), node->adjList.end());
    }
}

/*
 * Created by Dario Smolcic
 */
void ConstructionAlgorithms::finish_graph_A2(const csa_bitcompressed<>& csa, vector<Node*>& vertices) {
    vector<uint64_t> A(csa.size(), -1);
    for (uint64_t i = 0; i < vertices.size(); ++i) {
        Node* node = vertices[i];
        for (uint64_t j = node->lb; j <= node->rb; ++j) {
            A[csa[j]] = i;
        }
    }
    Node* node = vertices[A[0]];
    node->posList.push_back(0);
    for (uint64_t j = 1; j < csa.size(); ++j) {
        uint64_t i = A[j];
        if (i != -1) {
            if (!node->is_exit) {
                node->adjList.push_back(i);
            }
            node = vertices[i];
            node->posList.push_back(j);
        }
    }
}


ostream& operator<<(ostream& os, const Node& node) {
    os << "  " << node.id << " [label=\"";
    for (int j = 0; j < node.posList.size(); ++j) {
        os << node.posList[j] + 1; // human indexing starts from 1
        if (j != node.posList.size() - 1) {
            os << ",";
        }
    }
    os << ":" << node.len << "\"]" << endl;

    for (auto adj_node : node.adjList) {
        os << "  " << node.id << " -> " << adj_node << endl;
    }
    return os;
}