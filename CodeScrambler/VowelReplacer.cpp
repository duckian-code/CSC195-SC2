//
// Created by anabelle on 08/05/25.
//

#include "VowelReplacer.h"
#include <vector>
const string vowels = "aeiou";

string VowelReplacer::encrypt(string phraseToEncrypt) {
        std::vector<char> output;
        string outputStr = "";

        // loop over word
        for (int i = 0; i < phraseToEncrypt.length(); ++i) {
            // loop check for vowels
            for (int j = 0; j < vowels.length(); ++j) {
                if (phraseToEncrypt[i] == vowels[j]) {
                    // prevent index out of bounds
                    if (j + 1 > vowels.length() - 1) {
                        output.push_back(vowels[0]);
                        break;
                    }
                    output.push_back(vowels[j + 1]);
                    break;
                    // if not vowel, add the const back into the word
                } else if (j == vowels.length() - 1) {
                    output.push_back(phraseToEncrypt[i]);
                    break;
                }
            }
        }
        for (int i = 0; i < output.size(); ++i) {
            outputStr += output[i];
        }
        return outputStr;
    }

    string VowelReplacer::decrypt(string phraseToDecrypt) {
        std::vector<char> output;
        string outputStr = "";

        // loop over word
        for (int i = 0; i < phraseToDecrypt.length(); ++i) {
            // loop check for vowels
            for (int j = 0; j < vowels.length(); ++j) {
                if (phraseToDecrypt[i] == vowels[j]) {
                    // prevent index out of bounds
                    if (j - 1 < 0) {
                        output.push_back(vowels[0]);
                        break;
                    }
                    output.push_back(vowels[j + 1]);
                    break;
                    // if not vowel, add the const back into the word
                } else if (j == vowels.length() - 1) {
                    output.push_back(phraseToDecrypt[i]);
                    break;
                }
            }
        }
        for (int i = 0; i < output.size(); ++i) {
            outputStr += output[i];
        }
        return outputStr;
    }

    string VowelReplacer::to_string() {
        return "Vowel Replacer";
    }