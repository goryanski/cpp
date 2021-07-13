#pragma once
class Fraction {
	int x; //numerator
	int y; //denominator
public:
	Fraction();
	Fraction(int x, int y);
	Fraction(const Fraction& obj);
	void setFraction(int x, int y);
	void print(char* name);
	Fraction operator + (const Fraction& obj);
	Fraction operator - (const Fraction& obj);
	Fraction operator * (const Fraction& obj);
	Fraction operator / (const Fraction& obj);
};