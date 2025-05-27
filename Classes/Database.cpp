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

void AddLanguage(Software* obj) {
    bool quit = false;
    while (!quit) {
        cout << "Enter language to add: ";
        string language;
        cin >> language;
        obj->AddLanguage(language);
        cout << "Would you like to add another language? (y/n): ";
        char choice;
        cin >> choice;
        quit = choice == 'n';
    }
}

void Database::Create(Software::eType type) {
    Software* obj = nullptr;
    switch (type) {
        case Software::eType::IDE:
            obj = new Ide(InputName(), GetSize());
            AddLanguage(obj);
            break;
        case Software::eType::MALWARE:
            obj = new Malware(InputName(), GetSize());
            cout << "How many computers has it infected ?";
            int size;
            cin >> size;
            obj->AddComputersInfected(size);
            cout << "What is the danger rating (0.0 to 5.0) ?";
            float danger;
            cin >> danger;
            obj->SetDanger(danger);
            break;
    }
    obj->Read(cout, cin);
    objects.push_back(obj);
}

void Database::DisplayAll() {
}

void Database::Display(const string &name) {
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


