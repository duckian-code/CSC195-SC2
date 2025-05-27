//
// Created by anabelle on 22/05/25.
//

#include "Database.h"

#include <iostream>

#include "Ide.h"
#include "Malware.h"

Database::~Database() {
    for (Software* obj : objects) {
        delete obj;
    }
}

string Database::InputName() {
    cout << "Enter name: ";
    string name;
    cin >> name;
    return name;
}

float Database::GetSize() {
    cout << "Enter size (in GB): ";
    float size;
    cin >> size;
    return size;
}

void Database::Create(Software::eType type) {
    Software* obj = nullptr;
    switch (type) {
        case Software::eType::IDE:
            obj = new Ide(InputName(), GetSize());
            break;
        case Software::eType::MALWARE:
            obj = new Malware(InputName(), GetSize());
            break;
    }
    obj->Read(cout, cin);
    objects.push_back(obj);
}

void Database::DisplayAll() {
    for (Software* obj : objects) {
        Display(obj->GetName());
    }
}

void Database::Display(const string &name) {
    cout << "Displaying " << name << endl;
    for (Software* obj : objects) {
        if (obj->GetName() == name) {
            obj->Write(cout);
        }
    }
}

void Database::Display(Software::eType type) {
    for (Software* obj : objects) {
        if (obj->GetType() == type) {
            obj->Write(cout);
        }
    }
}


