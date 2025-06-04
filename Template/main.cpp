#include <iostream>

#include "TempClass.h"
using namespace std;

namespace awe {
    // int max(int i1, int i2) {
    //     return i1 > i2 ? i1 : i2;
    // }
    //
    // float max(float i1, float i2) {
    //     return i1 > i2 ? i1 : i2;
    // }

    template<typename T, typename D>
    T max(T i1, D i2) {
        return i1 > i2 ? i1 : i2;
    }
}

int main() {
    cout << awe::max(1.1f, 2.2f) << endl;

    TempClass t1(2,3);
}