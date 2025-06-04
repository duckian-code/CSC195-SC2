//
// Created by anabelle on 03/06/25.
//

#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <numeric>
using namespace std;

#endif //FRACTION_H

template<typename T>
class Fraction {
    T numerator;
    T denominator;
public:
    Fraction() : numerator(1), denominator(1) {};
    Fraction(T numerator, T denominator) : numerator(numerator), denominator(denominator) {};
    void simplify();
    double toDouble() const;

    // mutation operators
    Fraction<T> operator+(const Fraction<T>& fr) const;
    Fraction<T> operator-(const Fraction<T>& fr) const;
    Fraction<T> operator*(const Fraction<T>& fr) const;
    Fraction<T> operator/(const Fraction<T>& fr) const;

    // comparative operators
    bool operator==(const Fraction<T>& fr) const;
    bool operator!=(const Fraction<T>& fr) const;
    bool operator<(const Fraction<T>& fr) const;
    bool operator>(const Fraction<T>& fr) const;
    bool operator<=(const Fraction<T>& fr) const;
    bool operator>=(const Fraction<T>& fr) const;

    template<typename U>
    friend ostream& operator<<(ostream& os, const Fraction<U>& fr);
    template<typename U>
    friend istream& operator>>(istream& is, Fraction<U>& fr);
};

template<typename T>
void Fraction<T>::simplify() {
    // grcode -> gr co de greatest common denominator
    T grcode = gcd(numerator, denominator);
    numerator /= grcode;
    denominator /= grcode;
    if (denominator < 0) { // Keep denominator positive
        numerator = -numerator;
        denominator = -denominator;
    }
}

template<typename T>
double Fraction<T>::toDouble() const {
    return static_cast<double>(numerator) / denominator;
}

template<typename T>
Fraction<T> Fraction<T>::operator+(const Fraction<T>& fr) const {
    // originally was gonna do an expanded form, but found this
    T num = (numerator * fr.denominator) + (fr.numerator * denominator);
    T denom = denominator * fr.denominator;
    return Fraction(num, denom);
}

template<typename T>
Fraction<T> Fraction<T>::operator-(const Fraction<T>& fr) const {
    T num = (numerator * fr.denominator) - (fr.numerator * denominator);
    T denom = denominator * fr.denominator;
    return Fraction(num, denom);
}

template<typename T>
Fraction<T> Fraction<T>::operator*(const Fraction<T>& fr) const {
    T num = numerator * fr.numerator;
    T denom = denominator * fr.denominator;
    return Fraction(num, denom);
}

template<typename T>
Fraction<T> Fraction<T>::operator/(const Fraction<T>& fr) const {
    // division is inverse multiplications
    T num = numerator * fr.denominator;
    T denom = denominator * fr.numerator;
    return Fraction(num, denom);
}

template<typename T>
bool Fraction<T>::operator==(const Fraction<T>& fr) const {
    // I could simplify the fractions and then compare, or use this formula I found
    return numerator * fr.denominator == denominator * fr.numerator;
}

template<typename T>
bool Fraction<T>::operator!=(const Fraction<T>& fr) const {
    return numerator * fr.denominator != denominator * fr.numerator;
}

template<typename T>
bool Fraction<T>::operator<(const Fraction<T>& fr) const {
    // also works for comparing size
    return numerator * fr.denominator < denominator * fr.numerator;
}

template<typename T>
bool Fraction<T>::operator>(const Fraction<T>& fr) const {
    return numerator * fr.denominator > denominator * fr.numerator;
}

template<typename T>
bool Fraction<T>::operator<=(const Fraction<T>& fr) const {
    return (numerator * fr.denominator < denominator * fr.numerator || *this == fr);
}

template<typename T>
bool Fraction<T>::operator>=(const Fraction<T>& fr) const {
    return (numerator * fr.denominator > denominator * fr.numerator || *this == fr);
}

template<typename T>
ostream& operator<<(ostream& os, const Fraction<T>& fr) {
    os << fr.numerator << "/" << fr.denominator;
    return os;
}

template<typename T>
istream& operator>>(istream& is, Fraction<T>& fr) {
    cout << "Enter numerator: ";
    is >> fr.numerator;
    cout << "Enter denominator: ";
    is >> fr.denominator;
    fr.simplify();
    return is;
}