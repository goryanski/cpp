#pragma once
#include "Auto.h"
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;

class Application;

class AutoShop
{
	vector<Auto> cars;
public:
	AutoShop(vector<Auto> cars);

	void findByBrand(string brand);
	void findByModel(string model);
	void findByColor(string color);
	void findByPrice(double price);
	void findByYear(int year);
	void findByCountry(string country);
	void findCheapestCar();
	void findMostExpensiveCar();

	void printByColor(string color);
	void printByYear(int year);
	void printByCountry(string country);
	void printByPrice(double price);

	vector<Auto> getListCars();
	friend Application;
};
