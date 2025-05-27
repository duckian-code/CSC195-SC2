//
// Created by anabelle on 22/05/25.
//

#ifndef IDE_H
#define IDE_H
#include <vector>

#include "Software.h"


class Ide : public Software {
public:
    Ide(string name, float size) : Software(name, size) {};

    void AddLanguage(const string& language) override { supported_languages.push_back(language);};
    void Read(std::ostream& ostream, std::istream& istream) override;
    void Write(std::ostream& ostream) override;
    eType GetType() override { return eType::IDE; };
private:
    vector<string> supported_languages;
};



#endif //IDE_H
