#include "Employee.h"

Employee::Employee()
{
	fio = nullptr;
	age = 0;
}

Employee::Employee(char* fio, int age)
{
	setFio(fio);
	this->age = age;
}

Employee::Employee(const Employee& obj)
{
	setFio(obj.fio);
	age = obj.age;
}

Employee::~Employee()
{
	delete[] fio;
}

Employee Employee::operator=(const Employee& obj)
{
	if (this == &obj) {
		return *this;
	}
	setFio(obj.fio);
	age = obj.age;
	return *this;
}

void Employee::setFio(char* fio)
{
	int len = strlen(fio) + 1;
	this->fio = new char[len];
	strcpy_s(this->fio, len, fio);
}

ostream& operator<<(ostream& os, const Employee& obj)
{
	os << obj.fio << " " << obj.age << "y.o.";
	return os;
}
