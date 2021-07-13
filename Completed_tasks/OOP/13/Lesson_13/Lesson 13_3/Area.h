#pragma once

class Area
{
protected:
	double width;
	double height;
public:
	Area();
	Area(double width, double height);
	virtual void getArea() = 0;
};

