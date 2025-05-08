#include "Sandwich.h"

#include <bits/ostream.tcc>

void Sandwich::setPrice(float value) {
    price = value;
}

void Sandwich::PrintPrice() {
    std::cout << "Price: $" << price << std::endl;
}