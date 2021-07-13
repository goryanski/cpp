#pragma once
#include "Vehicle.h"

class Ñart : public Vehicle
{
public:
	Ñart();
	Ñart(double speed, double priceOfHour, int capasityPeople, int capasityCargo);
	double getTime(double distance);
	double getPrice(double distance);
	int getCapasityPeople()const;
	int getCapasityCargo()const;
};

