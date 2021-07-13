#include<iostream>
#include "fraction.h"

int main() {
	Fraction A(1, 3);
	A.print((char*)"A");
	Fraction B(3, 4);
	B.print((char*)"B");

	Fraction sum = A + B;
	sum.print((char*)"sum");
	Fraction sub = A - B;
	sub.print((char*)"sub");
	Fraction mul = A * B;
	mul.print((char*)"mul");
	Fraction div = A / B;
	div.print((char*)"div");

	system("pause");
	return 0;
}