#include <iostream>
#include "constants.h"
#include "../utils.h"

double calculateHeight(const double initialHeight, const int seconds) {
	// Используем формулу: [ s = u * t + (a * t^2) / 2 ], где u(начальная скорость) = 0
	double distanceFallen = (myConstants::gravity * seconds * seconds) / 2;
	return initialHeight - distanceFallen;
}

void startFreeFall() {
    print("Enter the initial height of the tower in meters: ");
    const double initialHeight  = getNumber();
    std::cout << "At 0 seconds, the ball is at height: " << initialHeight  << " meters" << std::endl;

    for (int i = 1; i <= 5; i++) {
        auto currentHeight = calculateHeight(initialHeight, i);
        if (currentHeight <= 0) {
            std::cout << "At " << i << " seconds, the ball is on the ground." << std::endl;
            break;
        }

        std::cout << "At " << i << " seconds, the ball is at height: " << currentHeight << " meters" << std::endl;
    }
}