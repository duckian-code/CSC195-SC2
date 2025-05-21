//
// Created by anabelle on 21/05/25.
//

#include "Animal.h"

#include <iostream>

void Animal::Read(ostream& ostream, istream& istream) {
    ostream << "Enter name: ";
    istream >> m_name;

    ostream << "Enter lifespan: ";
    istream >> m_lifespan;
}

void Animal::Write(ostream& ostream) {
    ostream << "Name: " << m_name << endl;
    ostream << "Lifespan: " << m_lifespan << endl;
}