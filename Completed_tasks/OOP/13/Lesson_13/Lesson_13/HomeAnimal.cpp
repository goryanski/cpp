#include "HomeAnimal.h"

HomeAnimal::HomeAnimal()
{
	name[0] = color[0] = type[0] = '\0';
	weight = 0.0;
}

HomeAnimal::HomeAnimal(char* name, char* color, char* type, double weight)
{
	strcpy_s(this->name, name);
	strcpy_s(this->color, color);
	strcpy_s(this->type, type);
	this->weight = weight;
}
