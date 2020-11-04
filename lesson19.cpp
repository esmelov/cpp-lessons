#include <iostream>

int doMath(int, int, int, int); 
int addNumbers(int, int);
 
void functionPrototype() {
    std::cout << "3 + 4 = " << addNumbers(3, 4) << std::endl;
}
 
int addNumbers(int x, int y) {
    return x + y;
}

int doMath(int first, int second, int third, int fourth) {
    return first + second * third / fourth;
}