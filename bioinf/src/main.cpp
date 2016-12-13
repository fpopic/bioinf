#include <iostream>
#include "mylib/MyIOLibrary.h"

using namespace std;

int main() {
    MyIOLibrary myIOLibrary;
    myIOLibrary.fileToCin("res/input.txt");

    int x;
    for (int i = 0; i < 4; ++i) {
        cin >> x;
        cout << x << endl;
    }
    return 0;
}