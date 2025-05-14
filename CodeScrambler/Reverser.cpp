//
// Created by anabelle on 08/05/25.
//

#include "Reverser.h"
string Reverser::encrypt(string phraseToEncrypt) {
    string returnString = "";
    for (int i = phraseToEncrypt.length(); i > 0; --i) {
        returnString += phraseToEncrypt[i - 1];
    }
    return returnString;
}

string Reverser::decrypt(string phraseToDecrypt) {
    return encrypt(phraseToDecrypt);
}

string Reverser::to_string() {
    return "Reverser";
}
