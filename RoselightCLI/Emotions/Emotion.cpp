#include "Emotion.h"

float Emotion::emotionLvl = 0.0f;

void Emotion::updateEmLvl(float tone) {
    emotionLvl += tone;
    if (emotionLvl >= 3.0) {
        emotionLvl = 2.9;
    } else if (emotionLvl < -2.0) {
        emotionLvl = -2.9;
    }
}

string Emotion::eTypeToString(eType type) {
    switch (type) {
        case eType::ANGRY:
            return "angry";
        case eType::HAPPY:
            return "happy";
        default:
            return "neutral";
    }
}

Emotion::~Emotion() = default;

