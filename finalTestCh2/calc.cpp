#include <iostream>
#include <limits>
#include "math.h"
#include "../utils.h"

char getOperator() {
    char c;
    std::cin >> c;
    return c;
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

double calculate(double a, double b, char action) {
    switch (action) {
        case '+':
            return add(a, b);
        case '-':
            return subtract(a, b);
        case '*':
            return multiply(a, b);
        case '/':
            return divide(a, b);
    
        default:
            return std::numeric_limits<double>::quiet_NaN();
    }
}

void calculate() {
    print("Enter a double value: ");
    const double a = getNumber();
    print("Enter a double value: ");
    const double b = getNumber();

    print("Enter one of the following: +, -, *, or /: ");
    const char action = getOperator();

    const double result = calculate(a, b, action);

    if (!isnan(result))
        std::cout << a << " " << action << " " << b << " = " << result << std::endl;
    else
        std::cout << "enter valid number or action" << std::endl;
}