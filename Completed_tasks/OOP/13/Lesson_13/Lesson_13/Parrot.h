#pragma once
#include "HomeAnimal.h"
using std::cout;

class Parrot : public HomeAnimal {
public:
	Parrot();
	Parrot(char* name, char* color, char* type, double weight);
	void sound() override;
	void show() override;
	void typeAnimal() override;
};