#include <iostream>

#include "Database.h"
#include "Ide.h"
#include "Malware.h"
#include "Software.h"
using namespace std;

Software::eType which_software() {
    while (true) {
        cout << "Which software type ?\n"
            "1 - Create IDE\n"
            "2 - Create Malware\n";
        int choice;
        cin >> choice;
        Software::eType type = static_cast<Software::eType>(choice - 1);
        return type;
    }
}

string which_software_name() {
    cout << "Enter name of software you would like to locate: ";
    string name;
    cin >> name;
    return name;
}

int main() {
    Database db;

    bool quit = false;
    while (!quit) {
        cout << "1 - Create \n"
                "2 - Display All\n"
                "3 - Display by Name\n"
                "4 - Display by type\n"
                "5 - Quit\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                db.Create(which_software());
            case 2:
                db.DisplayAll();
            case 3:
                db.Display(which_software_name());
            case 4:
                db.Display(which_software());
            case 5:
                quit = true;
            default:
                cout << "Invalid choice !\n";
        }
    }
}

