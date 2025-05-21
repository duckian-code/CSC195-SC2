//
// Created by anabelle on 21/05/25.
//

#ifndef BIRD_H
#define BIRD_H
#include "Animal.h"


class Bird : public Animal {
public:
    eType GetType() override { return eType::BIRD; }

    void Read(ostream& ostream, istream& istream) override;
    void Write(ostream& ostream) override;

protected:
    int m_numFeathers = 0;
};



#endif //BIRD_H
