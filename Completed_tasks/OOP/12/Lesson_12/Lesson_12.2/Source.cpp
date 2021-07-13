#include <iostream>
#include "Passport.h"
#include "foreignPassport.h"

int main() {
	Passport people[2];

	people[0] = Passport((char*)"Vasya", (char*)"Pupkin", (char*)"2323llkk", (char*)"ul.ololova", 29);
	people[1] = foreignPassport((char*)"Rita", (char*)"Luddss", (char*)"232llv", (char*)"ul.tyty", 20, (char*)"kfkf009");


	for (int i = 0; i < 2; i++) {
		people[i].show();
	}

	return 0;
}