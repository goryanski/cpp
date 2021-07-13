#include "linearEquations.h"

linearEquations::linearEquations()
	: rootsOfEquation() {
}

linearEquations::linearEquations(double a, double b)
	: rootsOfEquation(a, b) {
}

void linearEquations::getRoots()
{
	if (a != 0) {
		cout << "X = " << b / a << "\n";
	}
	else if (a == 0 && b != 0) {
		cout << "There're no roots\n";
	}
	else if (a == 0 && b == 0) {
		cout << "Infinite set of roots\n";
	}
}
