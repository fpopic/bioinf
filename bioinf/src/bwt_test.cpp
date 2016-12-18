#include <bits/stdc++.h>
#include <sais.hxx>

using namespace std;

int main() {
    ifstream in("input.txt", ifstream::binary | ifstream::ate);
    ios::sync_with_stdio(false);
    cin.rdbuf(in.rdbuf());

    int N = (int) cin.tellg();
    cin.seekg(0);

    // ulaz
    vector<char> T(N);
    for (int i = 0; i < N; ++i) cin >> T[i];

    // izlaz
    vector<char> bwt(N);
    vector<int> temp(N);

    int pindex = saisxx_bwt(T.begin(), bwt.begin(), temp.begin(), N);

    cout << "Input:\t";
    for (auto &c: T) cout << c;
    cout << "\tN = " << N << endl;

    cout << "BWT:\t";
    for (auto &c : bwt) cout << c;
    cout << "\tIndex of '$' = " << pindex << endl;

    return 0;
}

/* http://www.allisons.org/ll/AlgDS/Strings/BWT/
refStr      = mississippi
suffix array= 11,10,7,4,1,0,9,8,6,3,5,2
BWT refStr  = ipssm$pissii
recover bwt = mississippi$
locate(0...): 11,10,7,4,1,0,9,8,6,3,5,2,
*/