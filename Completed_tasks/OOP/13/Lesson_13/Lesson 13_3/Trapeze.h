#pragma once
#include "Area.h"
#include <iostream>
using std::cout;

class Trapeze : public Area {
	double smallerWidth;
public:
	Trapeze();
	Trapeze(double width, double height, double smallerWidth);
	void getArea() override;
};
