//
// Created by anabelle on 05/06/25.
//

#include "Angry.h"

void Angry::SetContext(string input) {
    float happinessLvl = -Emotion::getEmLvl();
    string amplifier;
    if (happinessLvl > 3) {
        amplifier = "very";
    } if (happinessLvl > 2) {
        amplifier = "";
    } else {
        amplifier = "a little";
    }

    string context = "You are " + amplifier + " angry ! The user input is: " + input;
    finalContext = context;
}