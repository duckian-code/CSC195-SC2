//
// Created by anabelle on 08/05/25.
//

#ifndef REVERSER_H
#define REVERSER_H
#include "StringEncryptable.h"

class Reverser : public StringEncryptable{
public:
    string encrypt(string phraseToEncrypt);
    string decrypt(string phraseToDecrypt);
    string to_string();
};



#endif //REVERSER_H
