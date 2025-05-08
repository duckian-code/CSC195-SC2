//
// Created by anabelle on 08/05/25.
//

#include "Employee.h"

const float Employee::TAX = 0.1f; // Define TAX (10%)

void Employee::Read() {
    std::cout << "Enter first name: ";
    std::cin >> name;
    std::cout << "Enter initial of last name: ";
    std::cin >> initial;
    std::cout << "Enter age: ";
    std::cin >> age;
    isAdult = (age >= 18);
    std::cout << "Enter zipcode: ";
    std::cin >> zipcode;
    std::cout << "Enter hourly wage: ";
    std::cin >> wage;
    std::cout << "Enter number of days worked (max 7): ";
    std::cin >> daysWorked;

    totalHours = 0;
    for (int i = 0; i < daysWorked; i++) {
        std::cout << "Enter hours worked on day " << (i + 1) << ": ";
        std::cin >> hoursWorkedPerDay[i];

        totalHours += hoursWorkedPerDay[i];
    }
}

void Employee::Write() {
    float weeklyGross = wage * totalHours;
    float weeklyTax = weeklyGross * TAX;
    float weeklyNet = weeklyGross - weeklyTax;
    float yearlyGross = weeklyGross * 52;
    float yearlyNet = yearlyGross - (yearlyGross * TAX);

    std::cout << "\nEmployee Payroll Summary\n";
    std::cout << "-------------------------\n";
    std::cout << "Name: " << name << " " << initial << ".\n";
    std::cout << "Age: " << age << " (Adult: " << (isAdult ? "Yes" : "No") << ").\n";    std::cout << "Zipcode: " << zipcode << "\n";
    std::cout << "Hourly Wage: $" << wage << "\n";
    std::cout << "Total Hours Worked: " << totalHours << " hours \n";
    std::cout << "Weekly Gross Pay: $" << weeklyGross << "\n";
    std::cout << "Weekly Net Pay: $" << weeklyNet << "\n";
    std::cout << "Yearly Gross Pay: $" << yearlyGross << "\n";
    std::cout << "Yearly Net Pay: $" << yearlyNet << "\n";
}