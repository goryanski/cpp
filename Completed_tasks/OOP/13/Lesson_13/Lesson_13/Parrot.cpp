#include "Parrot.h"

Parrot::Parrot()
	: HomeAnimal() {
}

Parrot::Parrot(char* name, char* color, char* type, double weight)
	: HomeAnimal(name, color, type, weight) {
}

void Parrot::sound()
{
	cout << "Says: popka durak\n";
}

void Parrot::show()
{
	cout << "Name: " << name << "\n";
}

void Parrot::typeAnimal()
{
	cout << "Type: " << type << "\n";
}
