#include "utility.h"

uint64_t Utility::parse_k(string file_path) {
    ios::sync_with_stdio(false);
    ifstream in(file_path);

    if (!in.good()) {
        cerr << "<INPUT>.k file does not exist at:" + file_path << endl;
        exit(1);
    }

    string result;
    getline(in, result);

    return stoul(result);
}

string Utility::parse_fasta(string file_path) {
    ios::sync_with_stdio(false);
    ifstream in(file_path);

    if (!in.good()) {
        cerr << "<INPUT>.fasta file does not exist at:" + file_path << endl;
        exit(1);
    }

    string result;
    int num_of_strings = 0;

    string line;
    while (getline(in, line)) {
        if (line[0] == '>') {
            if (num_of_strings != 0) {
                result.resize(result.size() + 1);
                result[result.size() - 1] = 1;
            }
            num_of_strings++;
            continue;
        }
        result += line;
    }
//    result.resize(result.size() + 1);
//    result[result.size() - 1] = 0;
    return result;
}

int Utility::parse_algorithm(string algorithm) {
    ios::sync_with_stdio(false);
    if (algorithm != "A1" and algorithm != "A2") {
        cerr << "Wrong Algorithm name:" + algorithm << endl << "Allowed algorithms: A1 or A2" << endl;
        exit(1);
    }

    return algorithm == "A1" ? 1 : 2;
}