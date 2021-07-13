#pragma once
#include "rootsOfEquation.h"
#include <iostream>
using std::cout;

class quadraticEquations : public rootsOfEquation {
	double c;
public:
	quadraticEquations();
	quadraticEquations(double width, double height, double c);
	void getRoots() override;
};