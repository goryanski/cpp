#pragma once
#include <iostream>
using std::ostream;

class Employee
{
	char* fio;
	int age;
public:
	Employee();
	Employee(char* fio, int age);
	Employee(const Employee& obj);
	~Employee();
	Employee operator = (const Employee& obj);
	void setFio(char* fio);
	friend ostream& operator << (ostream& os, const Employee& obj);
};

