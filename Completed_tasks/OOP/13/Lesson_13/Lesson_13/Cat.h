#pragma once
#include "HomeAnimal.h"
using std::cout;

class Cat : public HomeAnimal {
public:
	Cat();
	Cat(char* name, char* color, char* type, double weight);
	void sound() override;
	void show() override;
	void typeAnimal() override;
};