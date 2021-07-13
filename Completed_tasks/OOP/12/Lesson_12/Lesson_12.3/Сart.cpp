#include "�art.h"

�art::�art()
	: Vehicle() {
}

�art::�art(double speed, double priceOfHour, int capasityPeople, int capasityCargo)
	: Vehicle(speed, priceOfHour, capasityPeople, capasityCargo) {
}

double �art::getTime(double distance)
{
	double time = distance / speed;
	return time;
}

double �art::getPrice(double distance)
{
	double price = priceOfHour * getTime(distance);
	return price;
}

int �art::getCapasityPeople() const
{
	return capasityPeople;
}

int �art::getCapasityCargo() const
{
	return capasityCargo;
}