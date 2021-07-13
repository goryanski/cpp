#include "fraction.h"
#include<iostream>
using std::cout;
using std::cin;

Fraction::Fraction()
{
	x = y = 0;
}

Fraction::Fraction(int x, int y)
{
	setFraction(x, y);
}

Fraction::Fraction(const Fraction& obj)
{
	setFraction(obj.x, obj.y);
}

void Fraction::setFraction(int x, int y)
{
	if (y == 0) {
		cout << "Error. Denominator cannot be equal to 0\n";
	}
	else {
		this->x = x;
		this->y = y;
	}
}

void Fraction::print(char* name)
{
	if (y == 0) {
		cout << "Error. Fraction " << name << " does not exist. Denominator cannot be equal to 0\n";
	}
	else {
		cout << name << " = " << x << "/" << y << "\n";
	}
}

Fraction Fraction::operator+(const Fraction& obj)
{
	Fraction fr;
	fr.x = x * obj.y + obj.x * y;
	fr.y = y * obj.y;
	return fr;
}

Fraction Fraction::operator-(const Fraction& obj)
{
	Fraction fr;
	fr.x = x * obj.y - obj.x * y;
	fr.y = y * obj.y;
	return fr;
}

Fraction Fraction::operator*(const Fraction& obj)
{
	Fraction fr;
	fr.x = x * obj.x;
	fr.y = y * obj.y;
	return fr;
}

Fraction Fraction::operator/(const Fraction& obj)
{
	Fraction fr;
	fr.x = x * obj.y;
	fr.y = obj.x * y;
	return fr;
}