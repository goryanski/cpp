#include "RightTriangle.h"

RightTriangle::RightTriangle()
	: Area() {
}

RightTriangle::RightTriangle(double width, double height)
	: Area(width, height) {
}

void RightTriangle::getArea()
{
	cout << "Area of the right triangle is " << 0.5 * width  * height << "\n";
}
