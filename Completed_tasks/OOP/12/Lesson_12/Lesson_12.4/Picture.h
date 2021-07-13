#pragma once
#include "Figure.h"
class Picture
{
	Figure* figures;
	int countFigures;
public:
	Picture();
	void addFigure(int countFigures);
	~Picture();
};

