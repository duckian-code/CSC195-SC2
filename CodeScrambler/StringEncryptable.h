//
// Created by anabelle on 08/05/25.
//

#ifndef STRINGENCRYPTABLE_H
#define STRINGENCRYPTABLE_H
#include <string>
using namespace std;

class StringEncryptable {
public:
    virtual string encrypt(string phraseToEncrypt) = 0;
    virtual string decrypt(string phraseToDecrypt) = 0;
};



#endif //STRINGENCRYPTABLE_H
