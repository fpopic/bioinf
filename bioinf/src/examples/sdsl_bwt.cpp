#include <sdsl/construct_bwt.hpp>
#include <sdsl/construct.hpp>

using namespace std;
using namespace sdsl;

int main() {
    const sauchar_t str[] = {'A', 'C', 'T', 'A', 'C', 'G', 'T', 'A', 'C', 'G', 'T', 'A', 'C', 'G'};

    /**
     * Constructs the burrows-wheeler transformed string of a given string and suffix array.
     * @param T[0..n-1] The input string.
     * @param U[0..n-1] The output string. (can be T)
     * @param SA[0..n-1] The suffix array. (can be NULL)
     * @param n The length of the given string.
     * @param idx The output primary index.
     * @return 0 if no error occurred, -1 or -2 otherwise.
     */

    sauchar_t bwt[14];
    saidx_t idx;
    int status = bw_transform(str, bwt, NULL, 14, &idx);

    for (int i = 0; i < 14; i++) {
        printf("%c", bwt[i]);
    }
    printf("\n");
    printf("idx=%d", idx);


    return 0;
}
