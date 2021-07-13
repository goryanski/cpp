#pragma once
#include "Student.h"

class Aspirant : public Student {
	double salary;
	char themeOfWork[STR_LEN]; // тема кандидатской
public:
	Aspirant();
	Aspirant(char* firstname, char* lastname, int age, int course, double salary, char* themeOfWork);
	~Aspirant();
};
