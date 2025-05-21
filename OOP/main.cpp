#include <iostream>
#include <vector>

#include "Food.h"
#include "Meat.h"
#include "cmake-build-debug/Fruit.h"
using namespace std;

int main() {
    //
    // {
    //     Food food;
    //     food.Consume();
    //     food.SetCalories(3299);
    //
    //     Food* pFood = &food;
    //     pFood->Consume();
    //     (*pFood).Consume();
    // }
    cout << "Fruit Instance" << endl;
    Fruit apple(10);

    apple.Consume();
    cout << "Fruit Calories:" << apple.GetCalories() << endl;

    cout << "Meat Instance" << endl;
    Meat beef(true);

    // vector<Food*> = { apple, beef};
}
