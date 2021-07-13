#include "Airplane.h"
#include <iostream>
using std::ostream;
using std::cout;
using std::copy;

Airplane::Airplane()
{
	arr = nullptr;
	capacity = size = 0;
	type = UNDEFINED;
}

Airplane::Airplane(int capacity, typePlane type)
{
	size = 0;
	this->capacity = capacity;
	arr = new int[capacity];
	this->type = type;
}

Airplane::Airplane(const Airplane& obj)
{
	type = obj.type;
	capacity = obj.capacity;
	size = obj.size;
	arr = (int*)calloc(capacity, sizeof(int));
	copy(obj.arr, obj.arr + size, arr);
}

Airplane::~Airplane()
{
	delete[] arr;
}

void Airplane::print()
{
	switch (type) {
	case FOR_PEOPLE:
		cout << "\n Airplane for people\n";
		break;
	case FOR_SOLDIERS:
		cout << "\n Airplane for soldiers\n";
		break;
	case FOR_ANIMALS:
		cout << "\n Airplane for animals\n";
		break;
	default:
		cout << "\n Undefined\n";
		break;
	}
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void Airplane::delEnd()
{
	arr = (int*)realloc(arr, (size - 1) * sizeof(int));
	size--;
}

int Airplane::getCapacity() const
{
	return capacity;
}

int Airplane::getSize() const
{
	return size;
}

Airplane& Airplane::operator++()
{
	arr[size++] = 1;
	return *this;
}

Airplane& Airplane::operator--()
{
	if (size > 0) {
		delEnd();
	}
	else {
		cout << "array too small\n";
	}
	return *this;
}

Airplane& Airplane::operator==(const Airplane& obj)
{

	if (type != obj.type) {
		cout << "\n Planes aren't the same type\n";
	}
	else {
		cout << "\n Planes are the same type\n";
	}
	return *this;
}

Airplane& Airplane::operator>(const Airplane& obj)
{

	if (capacity > obj.capacity) {
		cout << "\n Plane #1 has more seats for passengers\n";
	}
	else if (capacity < obj.capacity) {
		cout << "\n Plane #2 has more seats for passengers\n";
	}
	else {
		cout << "\n Planes have the same number of seats for passengers\n";
	}
	return *this;
}

// делаем перегрузку без функционала, просто для красоты кода при сравнениях
ostream& operator<<(ostream& os, const Airplane& obj)
{
	return os;
}
