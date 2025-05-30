#include <iostream>

#include "Point.h"
using namespace std;
void print(int x) { cout << x << endl; }
void print(float x) { cout << x << endl; }
void print(bool x) { cout << x << endl; }

// ost::Point ost::Point::operator+(Point& p2) {
//     Point sumPoint;
//     sumPoint.x = x + p2.x;
//     sumPoint.y = y + p2.y;
//     return sumPoint;
// }

int main() {
    print(1);
    print(1.0f);
    print(true);

    // function overload

    ost::Point point1(10, 14);
    ost::Point point2(5, 8);
    ost::Point point3 = (point1 + point2) - point1;

    point1.Write(cout);
    point2.Add(point1);
}