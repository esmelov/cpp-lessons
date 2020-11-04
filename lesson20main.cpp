#include <iostream>

int getInteger();

void multipleFilesProgram() {
    int x = getInteger();
	int y = getInteger();
 
	std::cout << x << " + " << y << " is " << x + y << std::endl;
}