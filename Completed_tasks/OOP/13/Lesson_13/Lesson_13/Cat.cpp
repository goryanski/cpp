#include "Cat.h"

Cat::Cat()
	: HomeAnimal() {
}

Cat::Cat(char* name, char* color, char* type, double weight)
	: HomeAnimal(name, color, type, weight) {
}

void Cat::sound()
{
	cout << "Says: may may\n";
}

void Cat::show()
{
	cout << "Name: " << name << "\n";
}

void Cat::typeAnimal()
{
	cout << "Type: " << type << "\n";
}
