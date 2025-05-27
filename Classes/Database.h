//
// Created by anabelle on 22/05/25.
//

#ifndef DATABASE_H
#define DATABASE_H
#include <vector>

#include "Software.h"
using namespace std;


class Database {
public:
    ~Database();
    void Create(Software::eType type);
    void DisplayAll();
    void Display(const string& name);
    void Display(Software::eType type);
protected:
    string InputName();
    float GetSize();
    vector<Software*> objects;
};



#endif //DATABASE_H
