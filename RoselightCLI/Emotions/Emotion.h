#ifndef EMOTION_H
#define EMOTION_H
#include <memory>
#include <string>
#pragma once
#include <unordered_map>
using namespace std;

// namespace being used so I can disginguish static functions easily

class Emotion {
protected:
    static float emotionLvl; // negative values change emotion negatively, positive positively. Between -2.9 and 2.9
    string finalContext; // value to be fed to the user responding LLM

    enum responseSize {
        SMALL,
        MEDIUM,
        LARGE,
    };

public:
    enum class eType {
        EXCITED = 2,
        HAPPY = 1,
        NEUTRAL = 0,
        ANGRY = -1,
        SAD = -2
    };

    // -- STATIC FUNCTIONS --
    static void updateEmLvl(float tone);
    static float getEmLvl() {return emotionLvl;};
    static string eTypeToString(eType type);


    // custom operator to add to emotion to change its type
    Emotion& operator+=(float tone) {
        emotionLvl += tone;
        return *this;
    };

    Emotion& operator-=(float tone) {
        emotionLvl -= tone;
        return *this;
    };

    // -- ABSTRACT FUNCTIONS --
    // abstract that defines specific emotions
    // virtual Context OutputContext();
    virtual ~Emotion();
    virtual eType GetType() const = 0;
    virtual string GetContext() = 0;
    virtual void SetContext(string input) = 0;
};

#endif //EMOTION_H