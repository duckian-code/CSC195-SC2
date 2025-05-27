//
// Created by anabelle on 22/05/25.
//

#ifndef SOFTWARE_H
#define SOFTWARE_H
#include <string>
using namespace std;

class Software {
public:
    // Software() = default;
    Software(string name, float size) : name(name), size(size) {};
    void SetName(const string& name) { this->name = name;};
    void SetSize(float size) { this->size = size;};
    enum class eType {
        IDE,
        MALWARE
    };
    virtual void Read(std::ostream& ostream, std::istream& istream) {};
    virtual void Write(std::ostream& ostream) {};
    virtual string GetName() {return "";};
    virtual eType GetType() = 0;

    virtual void AddLanguage(const string& language) {};
    virtual void AddComputersInfected(int computers_infected) {};
    virtual void SetDanger(float danger) {};
protected:
    string name;
    float size; // in GB
};




#endif //SOFTWARE_H
