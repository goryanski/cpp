#include "Circle.h"

Circle::Circle()
: Area() {
}

Circle::Circle(double width, double height)
: Area(width, height) {
}

void Circle::getArea()
{
	cout << "Area of the circle is " << 3.14 * (width / 2) * (height / 2) << "\n";
}
