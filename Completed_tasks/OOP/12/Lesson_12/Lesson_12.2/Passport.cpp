#include "Passport.h"

Passport::Passport()
{
	firstname[0] = lastname[0] = adress[0] = number[0] = '\0';
	age = 0;
}

Passport::Passport(char* firstname, char* lastname, char* number, char* adress, int age)
{
	strcpy_s(this->firstname, firstname);
	strcpy_s(this->lastname, lastname);
	strcpy_s(this->number, number);
	strcpy_s(this->adress, adress);
	this->age = age;
}

void Passport::show()
{
	cout << lastname << " "
		<< firstname << " "
		<< number << " "
		<< adress << " "
		<< age << "y.o. " << endl;
}
