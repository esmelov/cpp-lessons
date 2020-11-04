#include <iostream>

bool isPrime(int digit);

void primeDigit() {
    std::cout << "enter digit from 2 to 10" << std::endl;
    int x;
    std::cin >> x;
    if (x > 1 && x <= 10) {
        if (isPrime(x))
            std::cout << "The digit is prime" << std::endl;
        else
            std::cout << "The digit is not prime" << std::endl;
    }
    else
        std::cout << "Wrong digit" << std::endl;
}

bool isPrime(int digit) {
    return digit == 2 || digit == 3 || digit == 5 || digit == 7;
}