#pragma once
#include "Vehicle.h"

class �art : public Vehicle
{
public:
	�art();
	�art(double speed, double priceOfHour, int capasityPeople, int capasityCargo);
	double getTime(double distance);
	double getPrice(double distance);
	int getCapasityPeople()const;
	int getCapasityCargo()const;
};

