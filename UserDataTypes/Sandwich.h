#include <iostream>
#ifndef SANDWICH_H
#define SANDWICH_H

#endif //SANDWICH_H
enum Meat {
    Chicken,
    Prawns,
    Pastrami
};

class Sandwich {
public:
    std::string bread;
    bool isDelicious;
    Meat meat;

private:
    float price;

public:
    void setPrice(float value);
    void PrintPrice();
};