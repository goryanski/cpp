#pragma once
#include "Vehicle.h"

class Auto : public Vehicle
{
public:
	Auto();
	Auto(double speed, double priceOfHour, int capasityPeople, int capasityCargo);
	double getTime(double distance);
	double getPrice(double distance);
	int getCapasityPeople()const;
	int getCapasityCargo()const;
};

