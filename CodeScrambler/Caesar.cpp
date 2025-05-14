//
// Created by anabelle on 08/05/25.
//

#include "Caesar.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
// namespace caesar {
//
// }

string Caesar::encrypt(string phraseToEncrypt, int key) {
    for (char& c : phraseToEncrypt) {
        if (isalpha(c)) {
            char base = 'a';
            if (!islower(c)) {
                base = 'A';
            }
            c = (c - base + key) % 26 + base;
        }
    }
    return phraseToEncrypt;
}
string Caesar::decrypt(string phraseToDecrypt, int key) {
    // inverse the key to get the decrypt
    key = 26 - (key % 26);
    return encrypt(phraseToDecrypt, key);
}
string Caesar::to_string() {
    return "Caesar";
}