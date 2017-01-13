#include "brujin_algorithms.h"



pair<vector<Node*>, vector<Edge>> DeBruijinAlgorithms::create_compress_graph(const uint64_t& k, wt_huff<>& wta, lcp_wt<>& lcp) {
    bool open = false;
    uint64_t counter = 0;

    vector<Node*> graph;
    vector<Edge> edges;
    queue<Node*> queue;

    bit_vector B(wta.size(), 0);

    vector<uint64_t> lex_smaller_table(256, 0);
    for (uint64_t i = 0, sum = 0; i < 256; ++i) {
        lex_smaller_table[i] = sum;
        sum += wta.rank(wta.size(), i);
    }

    int lb = 0;
    for (uint64_t i = 0; i < wta.size(); ++i) {
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
      Node *node = new Node(counter, lb, wta.size() - 1, k); // DRY
      graph.push_back(node);
      queue.push(node);
      B[wta.size()-1] = 1;
      counter++;
    }


    bit_vector::rank_1_type bv_rank;
    util::init_support(bv_rank, &B);

    Node* stop_node = new Node(counter, 0, 0, 1);
    graph.push_back(stop_node); // Add stopnode.
    queue.push(stop_node);
    counter++;

    uint64_t quantity;
    vector<uint8_t> cs(wta.sigma);
    vector<uint64_t> rank_c_i(wta.sigma);
    vector<uint64_t> rank_c_j(wta.sigma);
    while (not queue.empty()) {
        Node* node = queue.front();
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
                }
                else {
                    id = (ones + 1) / 2;
                }

                if (id != ground) {
                    edges.push_back(Edge(id - 1, node->id, rb - lb + 1));
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

    return make_pair(graph, edges);
}

void DeBruijinAlgorithms::finishGraphA1(vector<Node*>& graph, vector<Edge>& edges, csa_bitcompressed<>& csa) {

    for (Edge& edge: edges) {
        Node* start_node = graph[edge.start];
        for (int i = 0; i < edge.multiplicity; ++i) {
            start_node->adjList.push_back(edge.end);
        }
    }
    for (auto node: graph) {
        for (uint64_t i = node->lb; i <= node->rb; ++i) {
            auto csa_i = csa[i];
            node->posList.push_back(csa_i);
        }
        sort(node->posList.begin(), node->posList.end());
        reverse(node->adjList.begin(), node->adjList.end());
    }
}

void DeBruijinAlgorithms::finishGraphA2(vector<Node*>& graph, csa_bitcompressed<>& csa) {
    vector<uint64_t> A(csa.size(), -1);
    for (uint64_t i = 0; i < graph.size(); ++i) {
        Node* node = graph[i];
        for (uint64_t j = node->lb; j <= node->rb; ++j) {
            A[csa[j]] = i;
        }
    }
    uint64_t index = A[0];
    Node* node = graph[index];
    node->posList.push_back(0);
    for (uint64_t j = 1; j < csa.size(); ++j) {
        uint64_t i = A[j];
        if (i != -1) {
            node->adjList.push_back(i);
            node = graph[i];
            node->posList.push_back(j);
        }
    }
}
