#include "../../utils.h"

uint getPositiveByteNumber() {
    while (true) {
        print("Enter positive number from 0 to 255: ");
        const uint number = getUIntNumber();
        if (number < 256)
            return number;

        printLn("Wrong number. Try again.");
    }
}

uint printAndDecrement(uint number, const uint pow) {
    return number >= pow
        ? (print("1"), (number - pow))
        : (print("0"), number);
}

void convertAndPrint(uint number) {
    uint point = 128;
    while (point > 0) {
        number = printAndDecrement(number, point);
        
        if (point == 16)
            print(" ");

        point /= 2;
    }
}

void convertToBinary() {
    const uint number = getPositiveByteNumber();
    convertAndPrint(number);
}

