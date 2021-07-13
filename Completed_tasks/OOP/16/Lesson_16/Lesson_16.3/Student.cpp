#include "Student.h"

Student::Student()
{
	firstName = "";
	secondName = "";
	course = 0;
}

Student::Student(string firstName, string secondName, int course)
{
	setStudent(firstName, secondName, course);
}

Student::Student(const Student& obj)
	: Student(obj.firstName, obj.secondName, obj.course) {
}

void Student::setStudent(string firstName, string secondName, int course)
{
	this->firstName = firstName;
	this->secondName = secondName;
	this->course = course;
}

Student Student::operator=(const Student& obj)
{
	if (this == &obj) {
		return *this;
	}
	setStudent(obj.firstName, obj.secondName, obj.course);
	return *this;
}

ostream& operator<<(ostream& os, const Student& obj)
{
	os << obj.firstName << " " << obj.secondName << " " << obj.course;
	return os;
}
