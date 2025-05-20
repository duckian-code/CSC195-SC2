#include <array>
#include <iostream>
#include <list>
#include <map>
#include <vector>
using namespace std;

int main() {


}

void array() {
    // creates an array containing days of week and iterates through it
    array<string, 7> daysOfWeek = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    for (auto day : daysOfWeek) {
        cout << day << endl;
    }
}

void vector() {
    // creates vector with 1 to 5
    vector<int> numbers = { 1, 2, 3, 4, 5 };
    // add 6 and 7
    numbers.push_back(6);
    numbers.push_back(7);
    // remove last one
    numbers.pop_back();
    // iterate through
    for (auto number : numbers) {
        cout << number << endl;
    }
}

void list() {
    // create list of fruits
    pmr::list<string> fruits = { "Apple", "Banana", "Dragonfruit" };
    // add fruits to back then front
    fruits.push_back("Forbidden Fruit");
    fruits.push_front("Grapefruit");
    // remove fruit matching Forbidden Fruit
    fruits.remove("Forbidden Fruit");
    // loop through
    for (auto fruit : fruits) {
        cout << fruit << endl;
    }
}

void map() {
    // create map mapping prices to grocery. woah. Baby food is real expensive
    map<string, int> productPriceMap = {{"Eggs", 3}, {"Milk", 4}, {"Baby Food", 150}};
    // add new entries
    productPriceMap.insert({ "Bread", 3 });
    productPriceMap.insert({"Cheese", 2});
    productPriceMap.insert({ "Butter", 5});
    // change price of Baby Food. Thats more reasonable
    productPriceMap["Baby Food"] = 3;
    // loop through with nice formatting
    for (auto product : productPriceMap) {
        cout << product.first << " costs " << product.second << endl;
    }
}