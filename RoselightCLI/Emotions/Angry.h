//
// Created by anabelle on 05/06/25.
//

#ifndef ANGRY_H
#define ANGRY_H
#include "Emotion.h"


class Angry : public Emotion {
protected:
    string finalContext;
    eType emotion = eType::ANGRY;
public:
    ~Angry() = default;
    eType GetType() const override { return eType::ANGRY; };
    void SetContext(string input);
    string GetContext() { return finalContext; };
};

#endif //ANGRY_H
