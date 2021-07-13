#pragma once
#include "Vehicle.h"

class Bicycle : public Vehicle
{
public:
	Bicycle();
	Bicycle(double speed, double priceOfHour, int capasityPeople, int capasityCargo);
	double getTime(double distance);
	double getPrice(double distance);
	int getCapasityPeople()const;
	int getCapasityCargo()const;
};


