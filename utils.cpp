#include <iostream>

void print(std::string message) {
    std::cout << message;
}

void printLn(std::string message) {
    std::cout << message << std::endl;
}

double getNumber() {
    double a;
    std::cin >> a;
    return a;
}

int getIntNumber() {
    int a;
    std::cin >> a;
    return a;
}