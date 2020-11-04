#include <iostream>
#include <cmath> // для функции fabs()

bool isAlmostEqual(double a, double b, double epsilon) {
    // Если разница между a и b меньше значения эпсилона, то тогда a и b - "достаточно близки"
    return fabs(a - b) <= epsilon;
}

// Дональд Кнут, известный учёный, предложил следующий способ в своей книге «Искусство программирования, том 2: Получисленные алгоритмы» (1968)
// Возвращаем true, если разница между a и b в пределах процента эпсилона 
bool approximatelyEqual(double a, double b, double epsilon) {
    return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

// Возвращаем true, если разница между a и b меньше absEpsilon или в пределах relEpsilon 
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon) {
    // Проверяем числа на их близость - это нужно в тех случаях, когда сравниваемые числа являются нулевыми или "около нуля"
    double diff = fabs(a - b);
    if (diff <= absEpsilon)
        return true;
 
    // В противном случае, возвращаемся к алгоритму Кнута
    return diff <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * relEpsilon);
}

void compare() {
    double d1(100 - 99.99); // должно быть 0.01
    double d2(10 - 9.99); // должно быть 0.01
 
    if (d1 == d2)
        std::cout << "d1 == d2" << "\n";
    else if (d1 > d2)
        std::cout << "d1 > d2" << "\n";
    else if (d1 < d2)
        std::cout << "d1 < d2" << "\n";

    if (!approximatelyEqual(d1, d2, 0.001))
        std::cout << d1 << " is not equal to " << d2 << "\n";
    else
        std::cout << d1 << " is equal to " << d2 << "\n";

    // Значение a очень близкое к 1.0, но, из-за ошибок округления, чуть меньше 1.0
	double a = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;
 
	// Во-первых, давайте сравним значение a (почти 1.0) с 1.0
	std::cout << approximatelyEqual(a, 1.0, 1e-8) << "\n";
 
	// Во-вторых, давайте сравним значение a - 1.0 (почти 0.0) с 0.0
	std::cout << approximatelyEqual(a - 1.0, 0.0, 1e-8) << "\n";

    // сравниваем "почти 0.0" с 0.0
	std::cout << approximatelyEqualAbsRel(a - 1.0, 0.0, 1e-12, 1e-8) << "\n";
    auto b = 13;
    auto c = 6;
    auto d = b ^ c;
}