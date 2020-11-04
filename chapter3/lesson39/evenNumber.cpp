#include <iostream>
#include "../../utils.h"

bool isEven(const int number) {
    return number % 2 == 0;
}

void check() {
    print("Enter the number: ");
    const int a = getIntNumber();
    std::cout << a << " is " << (isEven(a) ? "even" : "odd") << "." << std::endl;
}