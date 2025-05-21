//
// Created by anabelle on 21/05/25.
//

#include "Bird.h"
#include <iostream>

void Bird::Read(ostream& ostream, istream& istream) {
    Animal::Read(ostream, istream);

    ostream << "Enter number of feathers: ";
    istream >> m_numFeathers;
}

void Bird::Write(ostream& ostream) {
    Animal::Write(ostream);
    ostream << "Number of feathers: " << m_numFeathers << endl;
}