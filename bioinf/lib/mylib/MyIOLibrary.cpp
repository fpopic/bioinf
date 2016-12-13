#include "MyIOLibrary.h"

using namespace std;


void MyIOLibrary::fileToCin(string path) {
    freopen(path.c_str(), "r", stdin);
}