#pragma once

class Vehicle
{
protected:
	double speed;
	double priceOfHour;
	int capasityPeople;
	int capasityCargo; // вместимость груза
public:
	Vehicle();
	Vehicle(double speed, double priceOfHour, int capasityPeople, int capasityCargo);
	~Vehicle();
};

