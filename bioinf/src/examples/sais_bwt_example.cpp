#include <bits/stdc++.h>
#include <sais.hxx>

typedef int32_t integer;
typedef int8_t character;

using namespace std;

/* http://www.allisons.org/ll/AlgDS/Strings/BWT/
refStr      = mississippi
suffix array= 11,10,7,4,1,0,9,8,6,3,5,2
BWT refStr  = ipssm$pissii
recover bwt = mississippi$
locate(0...): 11,10,7,4,1,0,9,8,6,3,5,2,
*/

int main() {
    ifstream in("res/input.txt", ifstream::binary | ifstream::ate);
    ios::sync_with_stdio(false);
    cin.rdbuf(in.rdbuf());

    int32_t N = (int32_t) cin.tellg();
    cin.seekg(0);

    // ulaz
    vector<int8_t> T(N);
    for (int i = 0; i < N; ++i) cin >> T[i];

    // izlaz
    vector<int8_t> bwt(N);
    vector<int32_t> temp(N);

    int32_t pindex = saisxx_bwt(T.begin(), bwt.begin(), temp.begin(), N);

    cout << "Input:\t";
    for (auto &c: T) cout << (char) c;
    cout << "\tN = " << N << endl;

    cout << "BWT:\t";
    for (auto &c : bwt) cout << (char) c;
    cout << "\tIndex of '$' = " << pindex << endl;

    return 0;
}

