#pragma once
#include <iostream>
using std::ostream;

enum typePlane {
	UNDEFINED,
	FOR_PEOPLE,
	FOR_SOLDIERS,
	FOR_ANIMALS
};

class Airplane {
	typePlane type;
	int* arr;
	int capacity;    // макс кол-во пассажиров
	int size;       // фактическое кол-во пассажиров
public:
	Airplane();
	Airplane(int capacity, typePlane type);
	Airplane(const Airplane& obj);
	~Airplane();
	void print();
	void delEnd();
	int getCapacity() const;
	int getSize() const;

	Airplane& operator ++();
	Airplane& operator -- ();

	Airplane& operator == (const Airplane& obj);
	Airplane& operator > (const Airplane& obj);
	friend ostream& operator <<(ostream& os, const Airplane& obj);
};

ostream& operator <<(ostream& os, const Airplane& obj);