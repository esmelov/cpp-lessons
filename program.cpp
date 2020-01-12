#include <iostream>
#include <cmath>
#include <typeinfo>
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
#include <random> // для std::random_device и std::mt19937
#include "constants.h"
using namespace std;

typedef int status_t;
status_t editData();

using new_status_t = int;
new_status_t newEditData();

// Получаем начальную высоту от пользователя и возвращаем её
double getInitialHeight() {
    cout << "Enter the height of the tower in meters: ";
    double initialHeight;
    cin >> initialHeight;

    return initialHeight;
}

uint8_t getInitialNumber() {
    int initialNumber;
    while (true) {
        cout << "Enter the number from 0 to 255: ";
        cin >> initialNumber;
        if (initialNumber > 0 && initialNumber < 256)
            return static_cast<uint8_t>(initialNumber);
        else
            cout << "Wrong number." << endl;
    }
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
double calculateCurrentHeight(double initialHeight, int seconds) {
    // Используем формулу: [ s = u * t + (a * t^2) / 2 ], где u(начальная скорость) = 0
    double distanceFallen = (myConstants::gravity * seconds * seconds) / 2;
    double currentHeight = initialHeight - distanceFallen;

    return currentHeight;
}

// Выводим высоту, на которой находится мячик после каждой секунды падения
void printHeight(double height, int seconds) {
    if (height > 0.0)
        cout << "At " << seconds << " seconds, the ball is at height: " << height << " meters\n";
    else
        cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

void calculateAndPrintHeight(double initialHeight, int seconds) {
    double height = calculateCurrentHeight(initialHeight, seconds);
    printHeight(height, seconds);
}

// Примечание: экспонент не должен быть отрицательным
int pow(int base, int exp) {
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

bool isEven(int x) {
    return x % 2 == 0;
}

// Возвращаем true, если разница между a и b в пределах процента эпсилона
bool approximatelyEqual(double a, double b, double epsilon) {
    return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

// Возвращаем true, если разница между a и b меньше absEpsilon или в пределах relEpsilon
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon) {
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

void strings() {
    std::string fullName;
    int age;

    std::cout << "Enter your full name: ";    
    std::getline(std::cin, fullName);    
    std::cout << "Enter your age: ";
    std::cin >> age;
    std::cout << "You've lived " << static_cast<double>(age) / fullName.length() << " years for each letter in your name.";
}

void enums() {
    enum MonsterType {
    MONSTER_OGRE,
    MONSTER_GOBLIN,
    MONSTER_SKELETON,
    MONSTER_ORC,
    MONSTER_TROLL
    };

    MonsterType monsterType = MONSTER_OGRE;

    enum class Colors
    {
        PINK,
        GRAY
    };
 
    Colors color = Colors::PINK;
 
    if (color == Colors::PINK) // это нормально
        std::cout << "The color is pink!\n";
    else if (color == Colors::GRAY)
        std::cout << "The color is gray!\n";
}

// Сначала объявляем структуру Advertising 
struct Advertising {
    int adsShown;
    double clickThroughRatePercentage;
    double averageEarningsPerClick;
};
 
void printAdvertising(Advertising ad) {
    using namespace std;
    cout << "Number of ads shown: " << ad.adsShown << endl;
    cout << "Click through rate: " << ad.clickThroughRatePercentage << endl;
    cout << "Average earnings per click: $" << ad.averageEarningsPerClick << endl;
 
    // Следующая строка кода разбита из-за своей длины
    // Мы делим ad.clickThroughRatePercentage на 100, так как пользователь указывает проценты, а не готовое число
    cout << "Total Earnings: $" <<
        (ad.adsShown * ad.clickThroughRatePercentage / 100 * ad.averageEarningsPerClick) << endl;
}

struct FractionalNumber {
    uint nomerator;
    uint denominator;
};

float multiply(FractionalNumber a, FractionalNumber b) {
    float result;
    uint n = a.nomerator * b.nomerator;
    uint d = a.denominator * b.denominator;
    result = static_cast<float>(n) / d;
    return result;
}

FractionalNumber getNumber() {
    FractionalNumber a;
    std::cout << "Enter numerator: ";
    std::cin >> a.nomerator;
    std::cout << "Enter denominator: ";
    std::cin >> a.denominator;
    return a;
}

void structs() {
    struct Employee {
        short id;
        int age;
        double salary;
    };
    std::cout << "The size of Employee is " << sizeof(Employee) << std::endl;

    Advertising ad;
 
    cout << "How many ads were shown today? ";
    cin >> ad.adsShown;
    cout << "What percentage of users clicked on the ads? ";
    cin >> ad.clickThroughRatePercentage;
    cout << "What was the average earnings per click? ";
    cin >> ad.averageEarningsPerClick;
 
    printAdvertising(ad);

    FractionalNumber a = getNumber();
    FractionalNumber b = getNumber();
    std::cout << "Result of multiply: " << multiply(a, b) << std::endl;
}

enum class MonsterType {
    OGRE,
    GOBLIN,
    SKELETON,
    ORC,
    TROLL
};

std::string getMonsterTypeString(MonsterType type) {
    switch (type) {
    case MonsterType::GOBLIN:
        return "Goblin";
    case MonsterType::OGRE:
        return "Ogre";
    case MonsterType::SKELETON:
        return "Goblin";
    case MonsterType::ORC:
        return "Orc";
    case MonsterType::TROLL:
        return "Troll";
    default:
        return "Unknown";
    }
}

struct Monster {
    std::string name;
    float health;
    MonsterType type;
};

void printMonster(Monster monster) {
    std::cout << "This " << getMonsterTypeString(monster.type) << " is named " << monster.name <<" and has " << monster.health << " health." << std::endl;
}

void test4() {
    Monster goblinJohn { "John", 170.0, MonsterType::GOBLIN };
    Monster orcJames { "James", 35.0, MonsterType::ORC };
    printMonster(goblinJohn);
    printMonster(orcJames);
}

unsigned int PRNG() {
    // Наше стартовое число - 4 541
    static unsigned int seed = 4541;
 
    // Берём стартовое число и, с его помощью, генерируем новое значение
    // Из-за использования очень больших чисел (и переполнения) угадать следующее число исходя из предыдущего - очень сложно
    seed = (8253729 * seed + 2396403);
 
    // Берём стартовое число и возвращаем значение в диапазоне от 0 до 32 767
    return seed  % 32768;
}

// Генерируем рандомное число между значениями min и max
// Предполагается, что функцию srand() уже вызывали
int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void randoms() {
    std::cout << "Custom random with start number 4541" << std::endl;
    // Выводим 100 случайных чисел
    for (int count=0; count < 100; ++count) {
        std::cout << PRNG() << "    ";
 
        // Если вывели 5 чисел, то вставляем символ новой строки
        if ((count+1) % 5 == 0)
            std::cout << std::endl;
	}

    std::cout << "Standart random with start number 4541" << std::endl;
    srand(4541); // устанавливаем стартовое значение - 4 541
    // Выводим 100 случайных чисел
    for (int count=0; count < 100; ++count) {
        std::cout << rand() << "    ";
 
        // Если вывели 5 чисел, то вставляем символ новой строки
        if ((count+1) % 5 == 0)
            std::cout << std::endl;
	}

    std::cout << "Standart random with start number use current seconds" << std::endl;
    srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа 
    for (int count=0; count < 100; ++count)
    {
        std::cout << rand() << "    ";
 
        // Если вывели 5 чисел, то вставляем символ новой строки
        if ((count+1) % 5 == 0)
            std::cout << std::endl;
	}

    auto rnd = getRandomNumber(1, 6);

    std::cout << "Mersenne Twister" << std::endl;
    std::random_device rd; 
    std::mt19937 mersenne(rd()); // инициализируем Вихрь Мерсенна(считается лучшим, но не криптостойким) случайным стартовым числом 
 
    // Примечание: Из-за одного бага в компиляторе Code::Blocks (если вы используете Code::Blocks в Windows) - удалите две строчки кода выше и раскомментируйте следующую строчку:
    // std::mt19937 mersenne(static_cast<unsigned int>(time(0))); // инициализируем Вихрь Мерсенна случайным стартовым числом
 
    // Выводим несколько случайных чисел
    for (int count = 0; count < 48; ++count) {
        std::cout << mersenne() << "    ";
 
        // Если вывели 5 чисел, то вставляем символ новой строки
        if ((count + 1) % 5 == 0)
            std::cout << std::endl;
    }
}

double getValue() {
    std::cout << "Enter a double value: ";
    double a;
    std::cin >> a;
    std::cin.clear(); // cin в 'обычный' режим работы
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // и удаляем значения предыдущего ввода из входного буфера
    return a;
}

char getOperator() {
    while (true) { // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char sm;
        std::cin >> sm;
 
        // Выполняем проверку значений
        if (sm == '+' || sm == '-' || sm == '*' || sm == '/')    
            return sm; // возвращаем данные в функцию main() 
        else // в противном случае, сообщаем пользователю, что что-то пошло не так
            std::cout << "Oops, that input is invalid.  Please try again." << std::endl;
    }
}

void printResult(double a, char sm, double b) {
    double result;
    switch (sm) {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    default:
        break;
    }

    std::cout << a << " " << sm << " " << b << " is " << result << std::endl;
}

void calculator() {
    double a = getValue();
    char sm = getOperator();
    double b = getValue();
 
    printResult(a, sm, b);
}

int main() {
    calculator();
    randoms();
    test4();
    structs();
    enums();
    strings();
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