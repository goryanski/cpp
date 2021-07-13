#pragma once
#include "Area.h"
#include <iostream>
using std::cout;

class RightTriangle : public Area {
public:
	RightTriangle();
	RightTriangle(double width, double height);
	void getArea() override;
};