#include <iostream>
#include "Area.h"
#include "Rectangle.h"
#include "RightTriangle.h"
#include "Circle.h"
#include "Trapeze.h"

int main() {
	Area** area = new Area * [4];
	area[0] = new Rectangle(8, 15); 
	area[1] = new RightTriangle(5, 9);
	area[2] = new Circle(13, 13);
	area[3] = new Trapeze(8, 15, 4);

	for (int i = 0; i < 4; i++)
	{
		area[i]->getArea();
	}

	return 0;
}