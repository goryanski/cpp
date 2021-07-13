#pragma once
#include "Area.h"
#include <iostream>
using std::cout;

class Rectangle : public Area {
public:
	Rectangle();
	Rectangle(double width, double height);
	void getArea() override;
};