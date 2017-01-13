#include "de_bruijin_graph.h"
#include "brujin_algorithms.h"


DeBruijinGraph::DeBruijinGraph(string input_file) {
//    ifstream in(input_file);
    //string S = "AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGCTTCTGAACTGGTTACCTGCCGTGAGTAAATTAAAATTTTATTGACTTAGGTCACTAAATACTTTAACCAATATAGGCATAGCGCACAGACAGATAAAAATTACAGAGTACACAACATCCATGAAACGCATTAGCACCACCATTACCACCACCATCACCATTACCACAGGTAACGGTGCGGGCTGACGCGTACAGGAAACACAGAAAAAAGCCCGCACCTGACAGTGCGGGCTTTTTTTTTCGACCAAAGGTAACGAGGTAACAACCATGCGAGTGTTGAAGTTCGGCGGTACATCAGTGGCAAATGCAGAACGTTTTCTGCGTGTTGCCGATATTCTGGAAAGCAATGCCAGGCAGGGGCAGGTGGCCACCGTCCTCTCTGCCCCCGCCAAAATCACCAACCACCTGGTGGCGATGATTGAAAAAACCATTAGCGGCCAGGATGCTTTACCCAATATCAGCGATGCCGAACGTATTTTTGCCGAACTTTTGACGGGACTCGCCGCCGCCCAGCCGGGGTTCCCGCTGGCGCAATTGAAAACTTTCGTCGATCAGGAATTTGCCCAAATAAAACATGTCCTGCATGGCATTAGTTTGTTGGGGCAGTGCCCGGATAGCATCAACGCTGCGCTGATTTGCCGTGGCGAGAAAATGTCGATCGCCATTATGGCCGGCGTATTAGAAGCGCGCGGTCACAACGTTACTGTTATCGATCCGGTCGAAAAACTGCTGGCAGTGGGGCATTACCTCGAATCTACCGTCGATATTGCTGAGTCCACCCGCCGTATTGCGGCAAGCCGCATTCCGGCTGATCACATGGTGCTGATGGCAGGTTTCACCGCCGGTAATGAAAAAGGCGAACTGGTGGTGCTTGGACGCAACGGTTCCGACTACTCTGCTGCGGTGCTGGCTGCCTGTTTACGCGCCGATT"; // Notice no explicit dollar!
    string S = "ACTAGTTTTTCTAGTCC";

    // CSA
    csa_bitcompressed<> csa;
    construct_im(csa, S, 1);

    // BWT
    string bwt(S.size(), ' ');
    vector<int> temp(S.size());
    auto bwt_dollar = saisxx_bwt(S.begin(), bwt.begin(), temp.begin(), (int) S.size());
    bwt.insert(bwt_dollar, 1, 1);

    wt_huff<> wta;
    construct_im(wta, bwt, 1);

    lcp_wt<> lcp;
    construct_im(lcp, S, 1);

    pair<vector<Node*>, vector<Edge>> graph_edges = DeBruijinAlgorithms::create_compress_graph(3, wta, lcp);

    this->vertices = graph_edges.first;
    this->edges = graph_edges.second;

    DeBruijinAlgorithms::finishGraphA2(this->vertices, csa);
    //DeBruijinAlgorithms::finishGraphA1(vertices, edges, csa);

}

void DeBruijinGraph::print_graph(DeBruijinGraph& graph) {
    vector<Node*>& vertices = graph.vertices;

    cout << "digraph G {" << endl;
    for (int i = 0; i < vertices.size(); ++i) {
        Node* v = vertices[i];

        cout << "  " << v->id << " [label=\"";

        for (int j = 0; j < v->posList.size(); ++j) {
            cout << v->posList[j] + 1;
            if (j != v->posList.size() - 1) {
                cout << ",";
            }
        }
        cout << ":" << v->len << "\"]" << endl;

        for (int j = 0; j < v->adjList.size(); ++j) {
            cout << "  " << v->id << " -> " << v->adjList[j] << endl;
        }
    }
    cout << "}";
    cout << endl;
}
