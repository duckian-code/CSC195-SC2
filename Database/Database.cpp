//
// Created by anabelle on 21/05/25.
//

#include "Database.h"

#include <iostream>

#include "Bird.h"

void Database::Create(Animal::eType type) {
    Animal* animal = nullptr;
    switch (type) {
        case Animal::eType::BIRD:
            animal = new Bird();
            break;
        case Animal::eType::REPTILE:
            // animal = new Reptile();
            break;
        default:
            break;
    }

    animal->Read(cout, cin);
    m_animals.push_back(animal);
}

void Database::DisplayAll() {
}
