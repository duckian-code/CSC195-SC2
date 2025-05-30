//
// Created by anabelle on 28/05/25.
//

#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"


class Circle : public Shape {
public:
    Circle(float r) { m_radius = r; }
    ~Circle() {}

    float Area() override {
        return 3.14f * m_radius * m_radius;
    }

    void SetRadius(float radius) const { radius = radius; }
    float GetRadius() { return m_radius; }

private:
    float m_radius;
};



#endif //CIRCLE_H
