#include <iostream>
#include <sais.hxx>
#include <sdsl/lcp.hpp>
#include <sdsl/suffix_arrays.hpp>

#include "utility/utility.h"

using namespace std;
using namespace sdsl;

int main() {
    string input_string = "ACTACGTACGTACG$";
    cout << input_string << endl;
    cout << input_string.size() << endl;

    //region SA array construction
    vector<int> suffix_array(input_string.size());
    saisxx(input_string.begin(), suffix_array.begin(), (int) input_string.size());

    cout << "SA array construction:" << endl;
    cout << input_string.substr((unsigned long) suffix_array.at(0)) << endl;
    print_vector(suffix_array);
    //endregion

    cout << endl;

    //region BWT array construction
    input_string.pop_back();
    string bwt(input_string.size(), ' ');
    vector<int> temp(input_string.size());
    int btw_dollar_index =
            saisxx_bwt(input_string.begin(), bwt.begin(), temp.begin(), (int) input_string.size());

    cout << "BWT array construction:" << endl;
    cout << bwt << endl;
    cout << btw_dollar_index << endl;
    print_vector(temp);
    input_string.push_back('$');
    //endregion

    cout << endl;

    //region CSA, BWT, LCP array construction
    string file = "res/book_example.txt";
    input_string = "ACTACGTACGTACG";
    lcp_wt<> lcp;
    construct_im(lcp, input_string, 1);
//    construct(lcp, file, 1);

    csa_wt<> csa;
    construct_im(csa, input_string, 1);
    cout << "CSA array construction:" << endl;
    cout << csa << endl;
    cout << locate(csa, "ACG") << endl;

    cout << endl;

    cout << "Wavelet analysis:" << endl;
    cout << csa.wavelet_tree << endl;

    cout << endl;

    cout << "LCP array construction:" << endl;
    cout << input_string << endl;
    cout << lcp << endl;
    //endregion

    return 0;
}