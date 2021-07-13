#include "CarsStorage.h"

CarsStorage* CarsStorage::instance = nullptr;

CarsStorage::CarsStorage()
{
	size = 0;
	capacity = 2;
	arrCars = new Car[capacity];
}

CarsStorage* CarsStorage::getInstance()
{
	if (instance == nullptr) {
		instance = new CarsStorage();
	}
	return instance;
}

void CarsStorage::add(Car car)
{
	if (size == capacity) {
		resize(5);
	}
	arrCars[size++] = car;
}

void CarsStorage::remove(int indexDel)
{
	for (int i = indexDel; i < size - 1; i++) {
		arrCars[i] = arrCars[i + 1];
	}
	int newSize = size - 1;
	Car* tmp = new Car[newSize];
	copy(arrCars, arrCars + newSize, tmp);
	delete[] arrCars;
	arrCars = tmp;
	size--;
}

void CarsStorage::edit(int index)
{
	cin.ignore();
	char model[15];
	cout << "Enter new model: ";
	gets_s(model);

	int price;
	cout << "Enter new price: ";
	cin >> price;

	Car newCar(model, price);
	arrCars[index] = newCar;
}

void CarsStorage::resize(int count)
{
	int newCapacity = capacity + count;
	Car* tmp = new Car[newCapacity];
	copy(arrCars, arrCars + size, tmp);
	delete[] arrCars;
	arrCars = tmp;
	capacity = newCapacity;
}

Car* CarsStorage::getCars()
{
	return arrCars;
}

int CarsStorage::getCountCars() const
{
	return size;
}
