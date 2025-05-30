//
// Created by anabelle on 28/05/25.
//

#ifndef POINT_H
#define POINT_H
#pragma once
#include <iosfwd>
using namespace std;

namespace ost {
    class Point {
    public:
        float x, y;

    public:
        Point() : x{0}, y{0} {}
        Point(float x, float y) : x{x}, y{y} {}

        ost::Point operator+(Point &p2);
        // ost::Point operator-(Point &p2);

        ost::Point operator-(ost::Point point);

        ost::Point operator*(float s);

        friend ostream& operator<<(ostream& os, const Point& point);

        void Write(ostream& os);
        void Add(Point& point);
    };
}


#endif //POINT_H
