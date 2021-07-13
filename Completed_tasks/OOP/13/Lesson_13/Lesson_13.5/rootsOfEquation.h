#pragma once

class rootsOfEquation
{
protected:
	double a;
	double b;
public:
	rootsOfEquation();
	rootsOfEquation(double width, double height);
	virtual void getRoots() = 0;
};
