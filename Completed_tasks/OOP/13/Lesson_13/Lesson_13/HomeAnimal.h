#pragma once
#include <iostream>
#define STR_LEN 30

class HomeAnimal
{
protected:
	char name[STR_LEN];
	char color[STR_LEN];
	char type[STR_LEN];
	double weight;
public:
	HomeAnimal();
	HomeAnimal(char* name, char* color, char* type, double weight);
	virtual void sound() = 0;
	virtual void show() = 0;
	virtual void typeAnimal() = 0;
};

