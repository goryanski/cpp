#include "Rectangle.h"

Rectangle::Rectangle()
	: Area() {
}

Rectangle::Rectangle(double width, double height)
	: Area(width, height) {
}

void Rectangle::getArea()
{
	cout << "Area of the rectangle is " << width * height << "\n";
}
