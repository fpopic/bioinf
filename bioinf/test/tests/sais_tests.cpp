#include <gtest/gtest.h>
#include <sais.hxx>
#include <fstream>
#include "../../src/algorithms/de_bruijin_graph.h"

using namespace std;

/* http://www.allisons.org/ll/AlgDS/Strings/BWT/
refStr      = mississippi
suffix array= 11,10,7,4,1,0,9,8,6,3,5,2  // 11 -> '$' (min. of alphabet)
BWT refStr  = ipssm$pissii
recover bwt = mississippi$
locate(0...): 11,10,7,4,1,0,9,8,6,3,5,2,
*/

TEST(sais_checks, bwt) {
    vector<int8_t> input = {'m', 'i', 's', 's', 'i', 's', 's', 'i', 'p', 'p', 'i'};
    int32_t N = (int32_t) input.size();

    vector<int8_t> expected_bwt = {'i', 'p', 's', 's', 'm', 'p', 'i', 's', 's', 'i', 'i'};
    vector<int8_t> actual_bwt(N);

    int32_t expected_dollar_index = 5;
    int32_t actual_dollar_index;

    vector<int32_t> temp(N);
    actual_dollar_index = saisxx_bwt(input.begin(), actual_bwt.begin(), temp.begin(), N);

    EXPECT_EQ(actual_bwt, expected_bwt);
    EXPECT_EQ(actual_dollar_index, expected_dollar_index);

}

TEST(sais_checks, sais) {
    vector<int8_t> input = {'m', 'i', 's', 's', 'i', 's', 's', 'i', 'p', 'p', 'i'};
    int32_t N = (int32_t) input.size();

    vector<int32_t> expected = {10, 7, 4, 1, 0, 9, 8, 6, 3, 5, 2};
    vector<int32_t> actual(N);
    saisxx(input.begin(), actual.begin(), N);

    EXPECT_EQ(actual, expected);
}

TEST(diff_test, file){
    ifstream in1("");
    ifstream in2("");


}