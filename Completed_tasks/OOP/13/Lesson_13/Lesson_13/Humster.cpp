#include "Humster.h"

Humster::Humster()
	: HomeAnimal() {
}

Humster::Humster(char* name, char* color, char* type, double weight)
	: HomeAnimal(name, color, type, weight) {
}

void Humster::sound()
{
	cout << "Says: xrxrxr\n";
}

void Humster::show()
{
	cout << "Name: " << name << "\n";
}

void Humster::typeAnimal()
{
	cout << "Type: " << type << "\n";
}
