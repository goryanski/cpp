#pragma once
#include "Car.h"
using std::copy;
using std::cout;
using std::cin;

class CarsStorage
{
	static CarsStorage* instance;

	Car* arrCars;
	int size;
	int capacity;
	CarsStorage();
public:
	static CarsStorage* getInstance();
	void add(Car car);
	void remove(int indexDel);
	void edit(int index);
	void resize(int count);
	Car* getCars();
	int getCountCars() const;
};

