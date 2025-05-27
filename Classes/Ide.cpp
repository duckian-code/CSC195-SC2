//
// Created by anabelle on 22/05/25.
//

#include "Ide.h"
#include <iostream>
using namespace std;

void Ide::Read(ostream& ostream, istream& istream) {
    Ide::Read(ostream, istream);
    string language;
    ostream << "Enter language to add: ";
    istream >> language;
    supported_languages.push_back(language);
}

void Ide::Write(ostream& ostream) {
    for (auto language : supported_languages) {
        ostream << language + ", " << endl;
    }
}
