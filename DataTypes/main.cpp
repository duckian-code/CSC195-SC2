#include <iostream>

int main() {
    std::cout << "Data Types Project!" << std::endl;

    int i = 0;
    bool b;

    std::cout << i << std::endl;
    std::cout << &i << std::endl;
    std::cout << sizeof(i) << std::endl;
    std::cout << sizeof(b) << std::endl;

    // Data Type Conversion
    // Implicit Conversion
    // target data type has the capacity (memory to store the original value)

    short numShrt = 5;
    int numInt = numShrt;

    std::cout << numInt << std::endl;

    // explicit conversion
    double numDbl = 654.321;
    int numIntdbl = (int)numDbl; // traditional C++ way

    numIntdbl = static_cast<int>(numDbl); // Modern C++ way, use this if casting on runtime (like parent to child class, etc)
    // error on compiletime if wrong

    std::cout << numIntdbl << std::endl;
}