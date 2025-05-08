#include <iostream>

#include "Sandwich.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
// structs by default public, classes by default private






int main() {
    typedef float salary;
    salary wage_butcher = 12.4f;
    salary wage_cleaner = 9.5f;
    salary wage_chef = 15.8f;

    Sandwich bbq;

    bbq.bread = "Honey Rye";
    // bbq.price = 25.00f;
    bbq.setPrice(25.00f);
    bbq.isDelicious = true;
    bbq.meat = Meat::Chicken;

    // PrintPrice(bbq);
    bbq.PrintPrice(); // OOP = data members + member functions
}
