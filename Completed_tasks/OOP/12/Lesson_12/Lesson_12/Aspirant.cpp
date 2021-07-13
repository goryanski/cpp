#include "Aspirant.h"

Aspirant::Aspirant()
{
	themeOfWork[0] = '\0';
	salary = 0.0;
}

Aspirant::Aspirant(char* firstname, char* lastname, int age, int course, double salary, char* themeOfWork)
	: Student(firstname, lastname, age, course) {
	strcpy_s(this->themeOfWork, themeOfWork);
	this->salary = salary;
}

Aspirant::~Aspirant()
{
}
