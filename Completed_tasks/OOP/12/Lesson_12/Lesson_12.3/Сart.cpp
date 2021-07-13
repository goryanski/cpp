#include "Ñart.h"

Ñart::Ñart()
	: Vehicle() {
}

Ñart::Ñart(double speed, double priceOfHour, int capasityPeople, int capasityCargo)
	: Vehicle(speed, priceOfHour, capasityPeople, capasityCargo) {
}

double Ñart::getTime(double distance)
{
	double time = distance / speed;
	return time;
}

double Ñart::getPrice(double distance)
{
	double price = priceOfHour * getTime(distance);
	return price;
}

int Ñart::getCapasityPeople() const
{
	return capasityPeople;
}

int Ñart::getCapasityCargo() const
{
	return capasityCargo;
}