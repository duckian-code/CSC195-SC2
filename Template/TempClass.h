//
// Created by anabelle on 02/06/25.
//

#ifndef TEMPCLASS_H
#define TEMPCLASS_H


template<typename T>
class TempClass {
private:

    T x,y;
public:
    TempClass() : x{0}, y{0} {};
    TempClass(T x, T y) : x(x), y(y) {};
};

template<typename T, int size>
class TempArray {
private:
    T m_elements[size];

public:
    T operator [] (int index) { return m_elements[index]; }
};



#endif //TEMPCLASS_H
