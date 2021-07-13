#pragma once
#include "HomeAnimal.h"
using std::cout;

class Humster : public HomeAnimal {
public:
	Humster();
	Humster(char* name, char* color, char* type, double weight);
	void sound() override;
	void show() override;
	void typeAnimal() override;
};

