#include "Point.h"

Point::Point()
{
	x = y = 0;
}

Point::Point(int x, int y)
{
	setPoint(x, y);
}

void Point::setPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}
