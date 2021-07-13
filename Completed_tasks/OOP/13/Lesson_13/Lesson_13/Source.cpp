#include <iostream>
#include "HomeAnimal.h"
#include "Dog.h"
#include "Cat.h"
#include "Parrot.h"
#include "Humster.h"

int main() {
	HomeAnimal** animal = new HomeAnimal * [4];
	animal[0] = new Dog((char*)"Bobic", (char*)"Black", (char*)"Mammal", 15);
	animal[1] = new Cat((char*)"Murzik", (char*)"Ginger", (char*)"Mammal", 3);
	animal[2] = new Parrot((char*)"Kesha", (char*)"Red", (char*)"Burd", 0.3);
	animal[3] = new Humster((char*)"Noric", (char*)"Grey", (char*)"Rodents", 0.1);

	for (int i = 0; i < 4; i++)
	{
		animal[i]->sound();
		animal[i]->show();
		animal[i]->typeAnimal();
		cout << "\n";
	}

	return 0;
}