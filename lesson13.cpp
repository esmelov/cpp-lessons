#include <iostream>

int addFunc(int a, int b) {
   return a + b;
}
 
int multiply(int c, int d) {
   return c * d;
}

int doubleNumber(int x) {
   return 2 * x;
}

void argumentsAndParameters()
{
   std::cout << addFunc(7, 8) << std::endl; // внутри функции add(): a = 7, b = 8, значит a + b = 15
   std::cout << multiply(4, 5) << std::endl; // внутри функции multiply(): c = 4, d = 5, значит c * d = 20
 
   // Мы можем передавать целые выражения в качестве аргументов
   std::cout << addFunc(2 + 3, 4 * 5) << std::endl; // внутри функции add(): a = 5, b = 20, значит a + b = 25
 
   // Мы можем передавать переменные в качестве аргументов
   int x = 4;
   std::cout << addFunc(x, x) << std::endl; // будет 4 + 4
 
   std::cout << addFunc(1, multiply(2, 3)) << std::endl; // будет 1 + (2 * 3)
   std::cout << addFunc(1, addFunc(2, 3)) << std::endl; // будет 1 + (2 + 3)

   int i;
   std::cout << "Enter number: ";
   std::cin >> i;
   std::cout << doubleNumber(i) << std::endl;
}