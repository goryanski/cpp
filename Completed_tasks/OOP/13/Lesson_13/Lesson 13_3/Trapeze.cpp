#include "Trapeze.h"

Trapeze::Trapeze()
	: Area() {
	smallerWidth = 0.0;
}

Trapeze::Trapeze(double width, double height, double smallerWidth)
	: Area(width, height) {
	this->smallerWidth = smallerWidth;
}

void Trapeze::getArea()
{
	cout << "Area of the trapeze is " << 0.5 * (width + smallerWidth) * height << "\n";
}
