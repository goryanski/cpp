#include <iostream>
#include "Student.h"
#include "Aspirant.h"

int main() {
	Student people[2];

	people[0] = Student((char*)"Vasya", (char*)"Pupkin", 29, 3);
	people[1] = Aspirant((char*)"Petya", (char*)"Sidorov", 29, 6, 5500, (char*)"About monkey");
	

	for (int i = 0; i < 2; i++)
	{
		people[i].show();
	}

	return 0;
}