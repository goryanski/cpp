#include<iostream>
#include "Person.h"
#include "Flat.h"
#include "House.h"
using std::cout;
int main()
{
	House house;
	house.enter();
	cout << "THE HOUSE:\n";
	house.print();

	// заполнение напрямую
	/*int countPeople = 1;
	Person* arrPeople = new Person[countPeople];
	Person person1(25, (char*)"Vacya Vaciliev Vasilievich");
	arrPeople[0] = person1;
	arrPeople[0].print();
	delete[] arrPeople;*/

	system("pause");
	return 0;
}