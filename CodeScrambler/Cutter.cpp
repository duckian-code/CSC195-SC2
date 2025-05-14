//
// Created by anabelle on 08/05/25.
//

#include "Cutter.h"

string Cutter::encrypt(string phraseToEncrypt) {
    return phraseToEncrypt.substr(phraseToEncrypt.length() / 2)
    + phraseToEncrypt.substr(0, phraseToEncrypt.length() / 2);
}

string Cutter::decrypt(string phraseToDecrypt) {
    return encrypt(phraseToDecrypt);
}

string Cutter::to_string() {
    return "Cutter";
}
