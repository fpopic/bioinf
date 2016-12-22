#include <sdsl/suffix_arrays.hpp>

using namespace sdsl;

int main(int argc, char *argv[]) {

    csa_wt<> fm_index;
    construct_im(fm_index, "mississippi!", 1);

    std::cout << "'si' occurs " << count(fm_index, "si") << " times.\n";

}