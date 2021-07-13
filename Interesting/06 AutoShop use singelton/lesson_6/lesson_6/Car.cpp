#include "Car.h"

Car::Car()
{
	model = nullptr;
	price = 0;
}

Car::Car(char* model, int price)
{
	setModel(model);
	this->price = price;
}

Car::Car(const Car& obj)
{
	setModel(obj.model);
	price = obj.price;
}

Car::~Car()
{
	delete[] model;
}

Car Car::operator=(const Car& obj)
{
	if (this == &obj) {
		return *this;
	}
	setModel(obj.model);
	price = obj.price;
	return *this;
}

void Car::setModel(char* model)
{
	int len = strlen(model) + 1;
	this->model = new char[len];
	strcpy_s(this->model, len, model);
}

ostream& operator<<(ostream& os, const Car& obj)
{
	os << obj.model << " " << obj.price << "$";
	return os;
}