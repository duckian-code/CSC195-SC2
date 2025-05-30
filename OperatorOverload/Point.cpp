//
// Created by anabelle on 28/05/25.
//
#include "Point.h"

#include <iosfwd>
#include <iostream>
using namespace std;

void operator + (ost::Point& p1, ost::Point& p2) {
    p1.x += p2.x;
    p1.y += p2.y;
}

// void operator << (ostream& os, ost::Point& p) {
//     os << p.x << ",  " << p.y << endl;
// }

ost::Point ost::Point::operator- (ost::Point point) {
    // ost::Point point3;
    // point3.x = point1.x - point2.x;
    // point3.y = point1.y - point2.y;
    // return point3;
    return Point(x - point.x, y - point.y);
}

ost::Point ost::Point::operator* (float s) {
    return Point(x * s, y * s);
}

void ost::Point::Write(ostream& os) {
    os << x << ",  " << y << endl;
}

void ost::Point::Add(Point& point) {
    x+=point.x;
    y+=point.y;
}

ostream & ost::operator<<(ostream &os, const Point &point) {
    os << point.x << ",  " << point.y << endl;
    return os;
}
