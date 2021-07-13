#pragma once
#include "rootsOfEquation.h"
#include <iostream>
using std::cout;

class linearEquations : public rootsOfEquation {
public:
	linearEquations();
	linearEquations(double width, double height);
	void getRoots() override;
};