namespace myConstants {
    extern const double gravity(9.8);
}

namespace myOptions {
    extern const unsigned char option1 = 0x01; // шестнадцатеричный литерал для 0000 0001
    extern const unsigned char option2 = 0x02; // шестнадцатеричный литерал для 0000 0010
    extern const unsigned char option3 = 0x04; // шестнадцатеричный литерал для 0000 0100
    extern const unsigned char option4 = 0x08; // шестнадцатеричный литерал для 0000 1000
    extern const unsigned char option5 = 0x10; // шестнадцатеричный литерал для 0001 0000
    extern const unsigned char option6 = 0x20; // шестнадцатеричный литерал для 0010 0000
    extern const unsigned char option7 = 0x40; // шестнадцатеричный литерал для 0100 0000
    extern const unsigned char option8 = 0x80; // шестнадцатеричный литерал для 1000 0000
} // namespace myOptions

namespace emotionalState {
    extern const unsigned char isHungry = 0x01; // шестнадцатеричный литерал для 0000 0001
	extern const unsigned char isSad = 0x02; // шестнадцатеричный литерал для 0000 0010
	extern const unsigned char isMad = 0x04; // шестнадцатеричный литерал для 0000 0100
	extern const unsigned char isHappy = 0x08; // шестнадцатеричный литерал для 0000 1000
	extern const unsigned char isLaughing = 0x10; // шестнадцатеричный литерал для 0001 0000
	extern const unsigned char isAsleep = 0x20; // шестнадцатеричный литерал для 0010 0000
	extern const unsigned char isDead = 0x40; // шестнадцатеричный литерал для 0100 0000
	extern const unsigned char isCrying = 0x80; // шестнадцатеричный литерал для 1000 0000
}