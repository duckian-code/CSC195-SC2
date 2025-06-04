#include <iostream>

#include "Fraction.h"
using namespace std;

int main() {
    Fraction<int> a {15, 5};
    cout << a << endl;

    Fraction<int> b {15, 6};
    b.simplify();
    cout << b << endl;

    cout << a << " == " << b << " result: " << (a == b) << endl;
    cout << a << " > " << b << " result: " << (a > b) << endl;
    cout << a << " + " << b << " result: " << (a + b) << endl;
    cout << a << " * " << b << " result: " << (a - b) << endl;

    Fraction<int> c;
    cout << "Input fraction: \n";
    cin >> c;
    cout << c << endl;
    cout << c.toDouble() << endl;
}
