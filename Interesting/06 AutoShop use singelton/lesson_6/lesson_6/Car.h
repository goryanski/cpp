#pragma once
#include <iostream>
using std::ostream;

class Car
{
	char* model;
	int price;
public:
	Car();
	Car(char* model, int price);
	Car(const Car& obj);
	~Car();
	Car operator = (const Car& obj);
	void setModel(char* model);
	friend ostream& operator << (ostream& os, const Car& obj);
};

