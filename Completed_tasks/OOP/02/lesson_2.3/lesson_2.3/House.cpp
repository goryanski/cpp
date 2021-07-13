#include "House.h"
#include<iostream>
using std::cout;
using std::cin;
House::House()
{
	floors = 0;
	countFlats = 2;
	arrFlats = new Flat[countFlats];
}

House::House(int floors, Flat* arrFlats, int countFlats)
{
	setFloors(floors);
	setArrFlats(arrFlats, countFlats);
}

House::House(const House& obj)
{
	setArrFlats(obj.arrFlats, obj.countFlats);
	setFloors(floors);
}

House::~House()
{
	delete[]arrFlats;
}

void House::setArrFlats(Flat* arrFlats, int countFlats)
{
	this->countFlats = countFlats;
	this->arrFlats = new Flat[countFlats];
	for (int i = 0; i < countFlats; i++) {
		this->arrFlats[i] = arrFlats[i];
	}
}

void House::setFloors(int floors)
{
	this->floors = floors;
}

void House::enter()
{
	cout << "Enter amount of floors: ";
	cin >> floors;
	cout << "Enter amount of flats: ";
	cin >> countFlats;
	arrFlats = new Flat[countFlats];
	for (int i = 0; i < countFlats; i++) {
		cout << "Flat " << i + 1 << ":\n";
		arrFlats[i].enter();
	}
}

void House::print()
{

	cout << "Amount of floors: " << floors << "\nAmount of flats:" << countFlats << "\n\n";
	for (int i = 0; i < countFlats; i++) {
		cout << "Flat " << i + 1 << ":\n";
		arrFlats[i].print();
	}
	cout << "\n\n";
}