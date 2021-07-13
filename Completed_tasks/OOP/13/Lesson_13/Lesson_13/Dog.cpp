#include "Dog.h"

Dog::Dog()
: HomeAnimal() {
}

Dog::Dog(char* name, char* color, char* type, double weight)
: HomeAnimal(name, color, type, weight) {
}

void Dog::sound()
{
	cout << "Says: gav gav\n";
}

void Dog::show()
{
	cout << "Name: " << name << "\n";
}

void Dog::typeAnimal()
{
	cout << "Type: " << type << "\n";
}
