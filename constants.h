#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace myConstants {
    extern const double gravity;
}

namespace myOptions {
    extern const unsigned char option1; // шестнадцатеричный литерал для 0000 0001
    extern const unsigned char option2; // шестнадцатеричный литерал для 0000 0010
    extern const unsigned char option3; // шестнадцатеричный литерал для 0000 0100
    extern const unsigned char option4; // шестнадцатеричный литерал для 0000 1000
    extern const unsigned char option5; // шестнадцатеричный литерал для 0001 0000
    extern const unsigned char option6; // шестнадцатеричный литерал для 0010 0000
    extern const unsigned char option7; // шестнадцатеричный литерал для 0100 0000
    extern const unsigned char option8; // шестнадцатеричный литерал для 1000 0000
} // namespace myOptions

namespace emotionalState {
    extern const unsigned char isHungry; // шестнадцатеричный литерал для 0000 0001
	extern const unsigned char isSad; // шестнадцатеричный литерал для 0000 0010
	extern const unsigned char isMad; // шестнадцатеричный литерал для 0000 0100
	extern const unsigned char isHappy; // шестнадцатеричный литерал для 0000 1000
	extern const unsigned char isLaughing; // шестнадцатеричный литерал для 0001 0000
	extern const unsigned char isAsleep; // шестнадцатеричный литерал для 0010 0000
	extern const unsigned char isDead; // шестнадцатеричный литерал для 0100 0000
	extern const unsigned char isCrying; // шестнадцатеричный литерал для 1000 0000
}

#endif