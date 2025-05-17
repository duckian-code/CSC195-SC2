#include <iostream>
#include <array>
#include <list>
using namespace std;

int main() {
    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


    // iterate through
    for (int i = 0; i < sizeof(numbers); ++i) {
        cout << numbers[i] << endl;
    }

    int size = sizeof(numbers) / sizeof(int);

    cout << "Address of first element: " << numbers << endl;

    // fixed length at compile time
    // no built-in methods for common operations
    //fast access, easy set-up

    //STL array
    cout << endl << "STL Array" << endl;
    array<string, 4> animals = {"cat", "dog", "fish", "bird"};
    cout << "Third element: " << animals[2] << endl;
    cout << "Size of array: " << animals.size() << endl;
    cout << "All elements: ";
    for (string ani : animals) {
        cout << ani << " ";
    }
    cout << endl;

    cout << animals.end() << endl;

    list<float> height = {5.6f, 6.3f, 4.2f};
    cout << "Size of list: " << height.size() << endl;

    height.push_front(2.3f);
    height.push_back(7.3f);

    // iterate
    cout << "All elements: ";
    for (float h : height) {
        cout << h << " ";
    }
    cout << endl;

    // resiseable container - helpful for frequent and efficient insertion/deletion
    // high memory overhead

    
}