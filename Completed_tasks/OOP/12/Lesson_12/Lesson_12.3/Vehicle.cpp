#include "Vehicle.h"

Vehicle::Vehicle()
{
	speed = priceOfHour = 0.0;
	capasityPeople = capasityCargo = 0;
}

Vehicle::Vehicle(double speed, double priceOfHour, int capasityPeople, int capasityCargo)
{
	this->speed = speed;
	this->priceOfHour = priceOfHour;
	this->capasityPeople = capasityPeople;
	this->capasityCargo = capasityCargo;
}

Vehicle::~Vehicle()
{
}

