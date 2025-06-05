//
// Created by anabelle on 05/06/25.
//

#ifndef HAPPY_H
#define HAPPY_H
#include "Emotion.h"


class Happy : public Emotion {
protected:
    string finalContext;
    eType emotion = eType::HAPPY;
public:
    ~Happy() = default;
    eType GetType() const override { return eType::HAPPY; }
    void SetContext(string input);
    string GetContext() { return finalContext; };
private:
};



#endif //HAPPY_H
