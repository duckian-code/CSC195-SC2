//
// Created by anabelle on 08/05/25.
//

#ifndef CUTTER_H
#define CUTTER_H
#include "StringEncryptable.h"


class Cutter : public StringEncryptable{
public:
    string encrypt(string phraseToEncrypt);
    string decrypt(string phraseToDecrypt);
    string to_string();
};

#endif //CUTTER_H
