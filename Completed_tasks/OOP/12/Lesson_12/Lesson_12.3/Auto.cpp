#include "Auto.h"

Auto::Auto()
	: Vehicle() {
}

Auto::Auto(double speed, double priceOfHour, int capasityPeople, int capasityCargo)
	: Vehicle(speed, priceOfHour, capasityPeople, capasityCargo) {
}

double Auto::getTime(double distance)
{
	double time = distance / speed;
	return time;
}

double Auto::getPrice(double distance)
{
	double price = priceOfHour * getTime(distance);
	return price;
}

int Auto::getCapasityPeople() const
{
	return capasityPeople;
}

int Auto::getCapasityCargo() const
{
	return capasityCargo;
}
