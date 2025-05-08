#include <iostream>

int main() {
    std::string name;
    char initial;
    short age;
    bool isAdult;
    unsigned int zipcode;
    float wage;
    short daysWorked;
    float hoursWorkedPerDay[7];
    const float TAX = 0.1f;

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

    float totalHours = 0;
    for (int i = 0; i < daysWorked; i++) {
        std::cout << "Enter hours worked on day " << (i + 1) << ": ";
        std::cin >> hoursWorkedPerDay[i];

        totalHours += hoursWorkedPerDay[i];
    }

    float grossIncome = totalHours * wage;
    float taxAmount = grossIncome * TAX;
    float netIncome = grossIncome - taxAmount;

    std::cout << "\n Employee Payroll Summary \n";
    std::cout << "--------------------------- \n";
    std::cout << "Name: " << name << " " << initial << ".\n";
    // ? operator prints yes or no for isAdult
    std::cout << "Age: " << age << " (Adult: " << (isAdult ? "Yes" : "No") << ").\n";
    std::cout << "Zipcode: " << zipcode << "\n";
    std::cout << "Hourly Wage: $" << wage << " per hour \n";
    std::cout << "Total Hours Worked: " << totalHours << " hours \n";
    std::cout << "Gross Income: $" << grossIncome << "\n";
    std::cout << "Tax Amount: $" << taxAmount << "\n";
    std::cout << "Net Income: $" << netIncome << "\n";

}