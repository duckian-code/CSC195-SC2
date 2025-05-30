//
// Created by anabelle on 28/05/25.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

#endif //RECTANGLE_H
class Rectangle : public Shape {
public:
    Rectangle(float w, float h) {
        m_width = w;
        m_height = h;
    }

    float Area() override {
        return m_width * m_height;
    }

private:
    float m_width;
    float m_height;
};