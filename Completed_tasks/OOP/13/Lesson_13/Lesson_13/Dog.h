#pragma once
#include "HomeAnimal.h"
using std::cout;

class Dog : public HomeAnimal {
public:
	Dog();
	Dog(char* name, char* color, char* type, double weight);
	void sound() override;
	void show() override;
	void typeAnimal() override;
};

