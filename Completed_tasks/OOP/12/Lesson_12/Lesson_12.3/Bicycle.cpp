#include "Bicycle.h"

Bicycle::Bicycle()
	: Vehicle() {
}

Bicycle::Bicycle(double speed, double priceOfHour, int capasityPeople, int capasityCargo)
	: Vehicle(speed, priceOfHour, capasityPeople, capasityCargo) {
}


double Bicycle::getTime(double distance)
{
	double time = distance / speed;
	return time;
}

double Bicycle::getPrice(double distance)
{
	double price = priceOfHour * getTime(distance);
	return price;
}

int Bicycle::getCapasityPeople() const
{
	return capasityPeople;
}

int Bicycle::getCapasityCargo() const
{
	return capasityCargo;
}