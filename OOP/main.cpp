#include <iostream>

#include "Food.h"

int main() {
    Food food;
    food.Consume();
    food.SetCalories(3299);

    Food* pFood = &food;
    pFood->Consume();
    (*pFood).Consume();
}
