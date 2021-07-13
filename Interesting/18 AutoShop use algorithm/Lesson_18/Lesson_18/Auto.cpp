#include "Auto.h"

Auto::Auto()
{
	price = 0.0;
	year = 0;
}

Auto::Auto(string brand, string model, string color, double price, int year, string country)
: brand(brand), model(model), color(color), price(price), year(year), country(country) {
}

string Auto::getBrand() const
{
	return brand;
}

string Auto::getModel() const
{
	return model;
}

string Auto::getColor() const
{
	return color;
}

double Auto::getPrice() const
{
	return price;
}

int Auto::getYear() const
{
	return year;
}

string Auto::getCountry() const
{
	return country;
}

ostream& operator<<(ostream& os, const Auto& obj)
{
	os << obj.brand << " " << obj.model << " " << obj.color << " " << obj.price << " "
		<< obj.year << " " << obj.country;
	return os;
}
