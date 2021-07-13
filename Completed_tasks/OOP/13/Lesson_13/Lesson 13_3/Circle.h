#pragma once
#include "Area.h"
#include <iostream>
using std::cout;

class Circle : public Area {
public:
	Circle();
	Circle(double width, double height);
	void getArea() override;
};