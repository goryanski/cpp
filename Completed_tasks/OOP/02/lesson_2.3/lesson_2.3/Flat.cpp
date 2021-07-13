#include "Flat.h"
#include<iostream>
using std::cout;
using std::cin;
Flat::Flat()
{
	sizeArea = 0;
	countPeople = 2;
	arrPeople = new Person[countPeople];
}

Flat::Flat(int sizeArea, Person* arrPeople, int countPeople)

{
	setSizeArea(sizeArea);
	setarrPeople(arrPeople, countPeople);
}

Flat::Flat(const Flat& obj)
{
	setarrPeople(obj.arrPeople, obj.countPeople);
	setSizeArea(sizeArea);
}

Flat::~Flat()
{
	delete[]arrPeople;
}

void Flat::setarrPeople(Person* arrPeople, int countPeople)
{
	this->countPeople = countPeople;
	this->arrPeople = new Person[countPeople];
	for (int i = 0; i < countPeople; i++) {
		this->arrPeople[i] = arrPeople[i];
	}
}

void Flat::setSizeArea(int sizeArea)
{
	this->sizeArea = sizeArea;
}

void Flat::enter()
{
	cout << "Enter size of area: ";
	cin >> sizeArea;
	cout << "Enter amount of persons: ";
	cin >> countPeople;
	arrPeople = new Person[countPeople];
	for (int i = 0; i < countPeople; i++) {
		cout << "Person " << i + 1 << ":\n";
		arrPeople[i].enter();
	}
	cout << "\n";
}

void Flat::print()
{
	cout << "Size of area: " << sizeArea << "\t\tAmount of people:" << countPeople << "\n";
	for (int i = 0; i < countPeople; i++) {
		cout << "Person " << i + 1 << ":\n";
		arrPeople[i].print();
	}
	cout << "\n\n";
}
