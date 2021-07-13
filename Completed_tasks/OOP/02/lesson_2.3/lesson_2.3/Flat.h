#pragma once
#include "Person.h"
class Flat {
	int sizeArea;
	Person* arrPeople;
	int countPeople;
public:
	Flat();
	Flat(int sizeArea, Person* arrPeople, int countPeople);
	Flat(const Flat& obj);
	~Flat();
	void setarrPeople(Person* arrPeople, int countPeople);
	void setSizeArea(int sizeArea);
	void enter();
	void print();
};