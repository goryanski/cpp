#pragma once
#include <iostream>
using std::string;
using std::ostream;
class Auto
{
	string brand;
	string model;
	string color;
	double price;
	int year;
	string country;
public:
	Auto();
	Auto(string brand, string model, string color, double price, int year, string country);

	string getBrand() const;
	string getModel() const;
	string getColor() const;
	double getPrice() const;
	int getYear() const;
	string getCountry() const;
	friend ostream& operator << (ostream& os, const Auto& obj);
};
