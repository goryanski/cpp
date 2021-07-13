#include "quadraticEquations.h"

quadraticEquations::quadraticEquations()
	: rootsOfEquation() {
	c = 0.0;
}

quadraticEquations::quadraticEquations(double a, double b, double c)
	: rootsOfEquation(a, b) {
	this->c = c;
}

void quadraticEquations::getRoots()
{
	double D = b * b - 4 * a * c;
	if (D < 0) {
		cout << "There're no roots\n";
	}
	else if (D == 0) {
		cout << "X = " << (sqrt(D) - b) / (2 * a) << "\n";
	}
	else {
		cout << "X1 = " << (sqrt(D) - b) / (2 * a) << "; ";
		cout << "X2 = " << (-sqrt(D) - b) / (2 * a) << "\n";
	}
}
