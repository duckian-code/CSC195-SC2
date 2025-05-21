//
// Created by anabelle on 21/05/25.
//

#ifndef DATABASE_H
#define DATABASE_H
#include "Animal.h"
#include <vector>
using namespace std;

class Database {
public:
    ~Database(); // Destructor
    void Create(Animal::eType type);
    void DisplayAll();
    void Display(const string& name);
    void Display(Animal::eType type);

private:
    vector<Animal*> m_animals;
};



#endif //DATABASE_H
