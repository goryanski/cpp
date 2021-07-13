#include "AutoShop.h"

AutoShop::AutoShop(vector<Auto> cars)
{
	this->cars = cars;
}

void AutoShop::findByBrand(string brand)
{
	auto result = find_if(cars.begin(), cars.end(), [brand](const Auto& car) {
		return car.getBrand() == brand;
	});

	(result != cars.end()) ? cout << *result << endl : cout << "Not found" << endl;
}

void AutoShop::findByModel(string model)
{
	auto result = find_if(cars.begin(), cars.end(), [model](const Auto& car) {
		return car.getModel() == model;
	});
	
	(result != cars.end()) ? cout << *result << endl : cout << "Not found" << endl;
}

void AutoShop::findByColor(string color)
{
	auto result = find_if(cars.begin(), cars.end(), [color](const Auto& car) {
		return car.getColor() == color;
	});

	(result != cars.end()) ? cout << *result << endl : cout << "Not found" << endl;
}

void AutoShop::findByPrice(double price)
{
	auto result = find_if(cars.begin(), cars.end(), [price](const Auto& car) {
		return car.getPrice() == price;
	});

	(result != cars.end()) ? cout << *result << endl : cout << "Not found" << endl;
}

void AutoShop::findByYear(int year)
{
	auto result = find_if(cars.begin(), cars.end(), [year](const Auto& car) {
		return car.getYear() == year;
	});

	(result != cars.end()) ? cout << *result << endl : cout << "Not found" << endl;
}

void AutoShop::findByCountry(string country)
{
	auto result = find_if(cars.begin(), cars.end(), [country](const Auto& car) {
		return car.getCountry() == country;
	});

	(result != cars.end()) ? cout << *result << endl : cout << "Not found" << endl;
}

void AutoShop::findCheapestCar()
{
	double price = cars[0].getPrice();
	for_each(cars.begin() + 1, cars.end(), [&price](const Auto& car) {
		if (car.getPrice() < price) {
			price = car.getPrice();
		}
	});
	findByPrice(price);
}

void AutoShop::findMostExpensiveCar()
{
	double price = cars[0].getPrice();
	for_each(cars.begin() + 1, cars.end(), [&price](const Auto& car) {
		if (car.getPrice() > price) {
			price = car.getPrice();
		}
	});
	findByPrice(price);
}

void AutoShop::printByColor(string color)
{
	int flag = 0;
	for_each(cars.begin(), cars.end(), [color, &flag](const Auto& car) {
		if (car.getColor() == color) {
			cout << car << "\n";
			flag = 1;
		}
	});
	if (flag == 0) {
		cout << "There're no " << color << " cars.\n";
	}
}

void AutoShop::printByYear(int year)
{
	int flag = 0;
	for_each(cars.begin(), cars.end(), [year, &flag](const Auto& car) {
		if (car.getYear() == year) {
			cout << car << "\n";
			flag = 1;
		}
		});
	if (flag == 0) {
		cout << "There're no cars " << year << " year of release.\n";
	}
}

void AutoShop::printByCountry(string country)
{
	int flag = 0;
	for_each(cars.begin(), cars.end(), [country, &flag](const Auto& car) {
		if (car.getCountry() == country) {
			cout << car << "\n";
			flag = 1;
		}
		});
	if (flag == 0) {
		cout << "There're no cars from " << country << "\n";
	}
}

void AutoShop::printByPrice(double price)
{
	int flag = 0;
	for_each(cars.begin(), cars.end(), [price, &flag](const Auto& car) {
		if (car.getPrice() <= price) {
			cout << car << "\n";
			flag = 1;
		}
		});
	if (flag == 0) {
		cout << "There're no cars that are so cheap\n";
	}
}

vector<Auto> AutoShop::getListCars()
{
	return cars;
}
