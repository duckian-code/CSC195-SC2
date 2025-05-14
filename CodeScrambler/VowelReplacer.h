//
// Created by anabelle on 08/05/25.
//

#ifndef VOWELREPLACER_H
#define VOWELREPLACER_H
#include "StringEncryptable.h"


class VowelReplacer : public StringEncryptable{
public:
    string encrypt(string phraseToEncrypt);
    string decrypt(string phraseToDecrypt);
    string to_string();
};



#endif //VOWELREPLACER_H
