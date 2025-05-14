#include <iostream>
#include <list>
#include <vector>

#include "Caesar.h"
#include "Cutter.h"
#include "Reverser.h"
#include "VowelReplacer.h"
#define REVERSER_IDX 0
#define CUTTER_IDX 1
#define VOWEL_IDX 2
#define CAESAR_IDX 3
#include "StringEncryptable.h"
using namespace std;
string encrypted = "";
string userInput = "";
bool encryptors[4];
Caesar caesar;
Reverser reverser;
Cutter cutter;
VowelReplacer vowelReplacer;

bool encryptOrDecrypt() {
    while (true) {
        std::cout << "Select your operation: \n"
                 "1 - Encrypt\n"
                 "2 - Decrypt\n";
        cin >> userInput;
        cout << userInput << endl;
        if (userInput == "1") {
            return true;
        } if (userInput == "2") {
            return false;
        } else {
            std::cout << "Invalid input. Please try again! \n";
        }
    }

}

void run () {
    std::cout << "Welcome to the Code Scrambler ! \n";

    int userChoice = -1;
    string userInput = "";
    while (userChoice != 4) {
        std::cout << "Options: \n"
                     "1 - Reverser\n"
                     "2 - Cutter\n"
                     "3 - Vowel Replacer\n"
                     "4 - Caesar Cypher (requires key)\n"
                     "5 - Do not add new method. Proceed to encrypt\n";
        std::cout << "What would you like to do ? \n";

        try {
            cin >> userInput;
            userChoice = stoi(userInput) - 1;
            if (userChoice == 4) {
                continue;
            } if (encryptors[userChoice] == false) {
                std::cout << "Encryptor added to list !\n";
                encryptors[userChoice] = true;
                continue;
            }
            std::cout << "Encryptor already in list ! \n";
        } catch (std::invalid_argument e) {
            std::cout << "Invalid input. Please try again! \n";
            continue;
        }
    }
    std::cout << "Please enter the string you would like to encrypt or decrypt: \n";
    cin >> userInput;
    int key = 0;
    if (encryptors[CAESAR_IDX]) {
        std::cout << "Please enter the key for the Caesar Cypher: \n";
        while (true) {
            try {
                cin >> key;
                break;
            } catch (std::invalid_argument e) {
                std::cout << "Please enter a number ! \n";
            }
        }
    }
     if (encryptOrDecrypt()) {
         for (int i = 0; i < sizeof(encryptors); ++i) {
             if (encryptors[i]) {
                 switch (i) {
                     case REVERSER_IDX:
                         std::cout << "Reversed: " + reverser.encrypt(userInput) << endl;
                         encryptors[i] = false;
                         break;
                     case CUTTER_IDX:
                         std::cout << "Cut: " + cutter.encrypt(userInput) << endl;
                         encryptors[i] = false;
                         break;
                     case VOWEL_IDX:
                         std::cout << "Vowels Replaced: " + vowelReplacer.encrypt(userInput) << endl;
                         encryptors[i] = false;
                         break;
                     case CAESAR_IDX:
                         std::cout << "Caesar Cyphered: " + caesar.encrypt(userInput, key) << endl;
                         encryptors[i] = false;
                         break;
                     default:
                         break;
                 }
             }
         }
        } else {
            for (int i = 0; i < sizeof(encryptors); ++i) {
                if (encryptors[i]) {
                    switch (i) {
                        case REVERSER_IDX:
                            std::cout << "Reversed: " + reverser.decrypt(userInput) << endl;
                            encryptors[i] = false;
                            break;
                        case CUTTER_IDX:
                            std::cout << "Cut: " + cutter.decrypt(userInput) << endl;
                            encryptors[i] = false;
                            break;
                        case VOWEL_IDX:
                            std::cout << "Vowels Replaced: " + vowelReplacer.decrypt(userInput) << endl;
                            encryptors[i] = false;
                            break;
                        case CAESAR_IDX:
                            std::cout << "Caesar Ciphered: " + caesar.decrypt(userInput, key) << endl;
                            encryptors[i] = false;
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    for (int i = 0; i < sizeof(encryptors); ++i) {

    }
}

int main() {
    while (true) {
        run();
        std::cout << "Would you like to encrypt or decrypt another string ? \n";
        std::cout << "1 - Yes \n"
                     "2 - No \n";
        std::string userInput = "";
        cin >> userInput;
        if (userInput == "1") {
            continue;
        } else {
            break;
        }
    }

}
