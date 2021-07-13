#include "Student.h"

Student::Student()
{
	firstname[0] = lastname[0] = '\0';
	age = course = 0;
}

Student::Student(char* firstname, char* lastname, int age, int course)
	: Student() {
	strcpy_s(this->firstname, firstname);
	strcpy_s(this->lastname, lastname);
	this->age = age;
	this->course = course;
}

Student::~Student()
{
}

void Student::show()
{
	cout << lastname << " "
		<< firstname << " "
		<< age << "y.o. "
		<< course << "course" << endl;
}