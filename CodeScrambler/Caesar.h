//
// Created by anabelle on 08/05/25.
//

#ifndef CAESAR_H
#define CAESAR_H
#include "StringEncryptable.h"

class Caesar {
// does not inherit from StringEncryptable because of needing a key
public:
    string encrypt(string phraseToEncrypt, int key);
    string decrypt(string phraseToDecrypt, int key);
    string to_string();
};



#endif //CAESAR_H
