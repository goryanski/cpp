#include<iostream>
#include<iomanip>
#include "Person.h"
using std::cout;
using std::cin;
using std::setw;
using std::left;

Person::Person()
{
	age = 0;
	size = 30;
	fio = new char[size];
	strcpy_s(fio, size, "default");
}

Person::Person(int age, char* fio)
{
	setAge(age);
	setfio(fio);
}

Person::Person(const Person& tmp)
{
	setAge(age);
	setfio(tmp.fio);
}

Person::~Person()
{
	delete[]fio;
}

void Person::setfio(char* fio)
{
	size = strlen(fio) + 1;
	this->fio = new char[size];
	strcpy_s(this->fio, size, fio);
}

void Person::setAge(int age)
{
	this->age = age;
}

void Person::enter()
{
	cout << "Enter age: ";
	cin >> age;
	cin.ignore();
	cout << "Enter FIO: ";
	gets_s(fio, size);
	cout << "\n";
}

void Person::print()
{
	cout << left << setw(35) << fio << "\t" << age << "\n";
}

Person& Person::operator=(const Person& obj)
{
	if (this == &obj) {
		return *this;
	}
	if (this->fio != nullptr) {
		delete[] this->fio;
	}
	this->age = obj.age;
	this->size = obj.size + 1;
	fio = new char[size];
	strcpy_s(this->fio, size, obj.fio);
	return *this;
}
