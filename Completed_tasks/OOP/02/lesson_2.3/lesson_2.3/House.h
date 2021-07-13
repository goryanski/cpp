#pragma once
#include "Flat.h"
class House {
	Flat* arrFlats;
	int countFlats;
	int floors;
public:
	House();
	House(int floors, Flat* arrFlats, int countFlats);
	House(const House& obj);
	~House();
	void setArrFlats(Flat* arrFlats, int countFlats);
	void setFloors(int floors);
	void enter();
	void print();
};