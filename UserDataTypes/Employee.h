//
// Created by anabelle on 08/05/25.
//

#pragma once
#include <iostream>
#include <string>

class Employee {
public:
    void Read();
    void Write();

private:
    std::string name;
    char initial;
    short age;
    bool isAdult;
    unsigned int zipcode;
    float wage;
    short daysWorked;
    float hoursWorkedPerDay[7];
    float totalHours;

    static const float TAX; // Declare tax as a static constant
};
