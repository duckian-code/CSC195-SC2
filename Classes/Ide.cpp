//
// Created by anabelle on 22/05/25.
//

#include "Ide.h"
#include <iostream>
using namespace std;

void Ide::Read(ostream& ostream, istream& istream) {
    Software::Read(ostream, istream);
    // string language;
    // ostream << "Enter language to add: ";
    // istream >> language;
    bool quit = false;
    do {
        cout << "Enter language to add: ";
        string language;
        cin >> std::ws >> language;
        supported_languages.push_back(language);
        cout << "Would you like to add another language ?: \n"
                "1 - yes\n"
                "2 - no\n";
        int choice;
        cin >> std::ws >> choice;
        quit = choice == 2;
    } while (!quit);
}

void Ide::Write(ostream& ostream) {
    cout << GetName() << ": IDE" << endl;
    for (auto language : supported_languages) {
        ostream << language + ", " << endl;
    }
}
