#include <bits/stdc++.h>
#include <sdsl/suffix_arrays.hpp>

using namespace std;
using namespace sdsl;

int main() {

    // [0,a], [0,b]
    uint64_t a = 1;
    uint64_t b = 3;

    // [[ 0  1  2  3  4]  5  6  7  8  9   10  11  12   13
    // [[ A  C  T  A  C]  G  T  A  C  G   T    A   C    G
    string S = "ACTACGTACGTACG";

    wt_huff<> wta; // mora biti huff a ne csa_wt

    construct_im(wta, S, 1);

    uint64_t quantity;
    vector<uint8_t> cs(wta.sigma); //char-ovi
    vector<uint64_t> rank_za_c_do_a_ukljucivo(wta.sigma);
    vector<uint64_t> rank_za_c_do_b_ukljucivo(wta.sigma);

    //For each symbol c in wt[i..j-1] get rank(i,c) and rank(j,c).
    //moram na desnu granicu ovdje sam dodat 1 jer wt prima iskljucivu desnu stranu
    interval_symbols(wta, a, b + 1, quantity, cs, rank_za_c_do_a_ukljucivo, rank_za_c_do_b_ukljucivo);

    //printanje
    cout << "S:" << S << endl;
    cout << "[0," << a << "], [0," << b << "] indeksiranje od 0" << endl << endl;

    for (auto i = 0; i < cs.size() and cs[i] != 0; ++i) {
        cout << "do " << a << " ima " << cs[i] << "-ova :" << rank_za_c_do_a_ukljucivo[i] << endl;
        cout << "do " << b << " ima " << cs[i] << "-ova :" << rank_za_c_do_b_ukljucivo[i] << endl;
        cout << endl;
    }

//    uint64_t lb = carray[c] + rank_c_i[i];
//    uint64_t rb = carray[c] + rank_c_j[i] - 1;

    return 0;
}