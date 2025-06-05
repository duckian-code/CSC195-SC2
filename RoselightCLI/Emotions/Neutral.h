//
// Created by anabelle on 05/06/25.
//

#ifndef NEUTRAL_H
#define NEUTRAL_H
#include "Emotion.h"


class Neutral : public Emotion {
protected:
    string finalContext;
    eType emotion = eType::NEUTRAL;
public:
    ~Neutral() = default;
    eType GetType() const override { return eType::NEUTRAL; };
    void SetContext(string input);
    string GetContext() { return finalContext; };
};


#endif //NEUTRAL_H
