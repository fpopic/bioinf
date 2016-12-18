#include <gtest/gtest.h>
#include <sais.hxx>

using namespace std;

/* http://www.allisons.org/ll/AlgDS/Strings/BWT/
refStr      = mississippi
suffix array= 11,10,7,4,1,0,9,8,6,3,5,2
BWT refStr  = ipssm$pissii
recover bwt = mississippi$
locate(0...): 11,10,7,4,1,0,9,8,6,3,5,2,
*/

TEST(sais_checks, bwt) {
    vector<char> input = {'m', 'i', 's', 's', 'i', 's', 's', 'i', 'p', 'p', 'i'};
    int N = (int) input.size();

    vector<char> expected_bwt = {'i', 'p', 's', 's', 'm', 'p', 'i', 's', 's', 'i', 'i'};
    vector<char> actual_bwt(N);

    int expected_dollar_index = 5;
    int actual_dollar_index;

    vector<int> temp(N);
    actual_dollar_index = saisxx_bwt(input.begin(), actual_bwt.begin(), temp.begin(), N);

    EXPECT_EQ(actual_bwt, expected_bwt);
    EXPECT_EQ(actual_dollar_index, expected_dollar_index);

}

TEST(sais_checks, sais) {
    vector<char> input = {'m', 'i', 's', 's', 'i', 's', 's', 'i', 'p', 'p', 'i'};
    int N = (int) input.size();

    vector<int> expected = {10, 7, 4, 1, 0, 9, 8, 6, 3, 5, 2};
    vector<int> actual(N);
    saisxx(input.begin(), actual.begin(), N);

    EXPECT_EQ(actual, expected);
}

