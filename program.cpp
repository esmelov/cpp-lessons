#include <iostream>
#include <cmath>
#include <typeinfo>
#include "constants.h"
using namespace std;

// Получаем начальную высоту от пользователя и возвращаем её
double getInitialHeight()
{
    cout << "Enter the height of the tower in meters: ";
    double initialHeight;
    cin >> initialHeight;

    return initialHeight;
}

uint8_t getInitialNumber()
{
    int initialNumber;
    while (true) {
        cout << "Enter the number from 0 to 255: ";
        cin >> initialNumber;
        if (initialNumber > 0 && initialNumber < 256)
            break;
        else
            cout << "Wrong number." << endl;
    }   

    return static_cast<uint8_t>(initialNumber);
}

void convertToBinaryAndPrint(uint8_t number) {
    uint8_t init = 128;

    while (init > 0) {
        if (number >= init) {
            cout << "1";
            number -= init;
        }
        else {
            cout << "0";
        }

        init >>= 1;
        if (init == 8) {
            cout << " ";
        }
    }

    cout << endl;
}

// Возвращаем расстояние от земли после "..." секунд падения
double calculateCurrentHeight(double initialHeight, int seconds)
{
    // Используем формулу: [ s = u * t + (a * t^2) / 2 ], где u(начальная скорость) = 0
    double distanceFallen = (myConstants::gravity * seconds * seconds) / 2;
    double currentHeight = initialHeight - distanceFallen;

    return currentHeight;
}

// Выводим высоту, на которой находится мячик после каждой секунды падения
void printHeight(double height, int seconds)
{
    if (height > 0.0)
        cout << "At " << seconds << " seconds, the ball is at height: " << height << " meters\n";
    else
        cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

void calculateAndPrintHeight(double initialHeight, int seconds)
{
    double height = calculateCurrentHeight(initialHeight, seconds);
    printHeight(height, seconds);
}

// Примечание: экспонент не должен быть отрицательным
int pow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

bool isEven(int x)
{
    return x % 2 == 0;
}

// Возвращаем true, если разница между a и b в пределах процента эпсилона
bool approximatelyEqual(double a, double b, double epsilon)
{
    return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

// Возвращаем true, если разница между a и b меньше absEpsilon или в пределах relEpsilon
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
    // Проверяем числа на их близость - это нужно в случаях, когда сравниваемые числа являются нулевыми или около нуля
    double diff = fabs(a - b);
    if (diff <= absEpsilon)
        return true;

    // В противном случае, возвращаемся к алгоритму Кнута
    return diff <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * relEpsilon);
}

void flags() {
    unsigned char myFlags = 0;
    myFlags |= (myOptions::option4 | myOptions::option5); // включаем option4 и option5
    myFlags ^= myOptions::option4; // включаем или выключаем option4 
    myFlags ^= (myOptions::option4 | myOptions::option5); // изменяем состояния option4 и option5

    unsigned char me = 0;
    me |= emotionalState::isHappy | emotionalState::isLaughing; // Я isHappy и isLaughing
	me &= ~emotionalState::isLaughing; // Я уже не isLaughing
 
	// Запрашиваем сразу несколько состояний (мы будем использовать static_cast<bool> для конвертации результатов в значения типа bool)
	cout << "I am happy? " << static_cast<bool>(me & emotionalState::isHappy) << '\n';
	cout << "I am laughing? " << static_cast<bool>(me & emotionalState::isLaughing) << '\n';
}

void approximatelyEquals() {
    auto result = isEven(4);
    double a = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;
    result = approximatelyEqual(0.0000001, 0.00000015, 0.001);
    cout << approximatelyEqual(a, 1.0, 1e-8) << "\n";                    // сравниваем "почти 1.0" с 1.0
    cout << approximatelyEqual(a - 1.0, 0.0, 1e-8) << "\n";              // сравниваем "почти 0.0" с 0.0
    cout << approximatelyEqualAbsRel(a - 1.0, 0.0, 1e-12, 1e-8) << "\n"; // сравниваем "почти 0.0" с 0.0
}

void types() {
    short s = 3;
    cout << "Size of type short: " << sizeof(s) << endl;

    short x(3);
    short y(6);
    std::cout << typeid(x + y).name() << " " << x + y << std::endl; // вычисляем решающий тип данных в выражении x + y

    double a(3.0);
    short b(2);
    std::cout << typeid(a + b).name() << " " << a + b << std::endl; // вычисляем решающий тип данных в выражении a + b
}

int main() {
    flags();
    approximatelyEquals();
    types();    

    const uint8_t initialNumber = getInitialNumber();
    convertToBinaryAndPrint(initialNumber);    

    const double initialHeight = getInitialHeight();

    calculateAndPrintHeight(initialHeight, 0);
    calculateAndPrintHeight(initialHeight, 1);
    calculateAndPrintHeight(initialHeight, 2);
    calculateAndPrintHeight(initialHeight, 3);
    calculateAndPrintHeight(initialHeight, 4);
    calculateAndPrintHeight(initialHeight, 5);

    return 0;
}