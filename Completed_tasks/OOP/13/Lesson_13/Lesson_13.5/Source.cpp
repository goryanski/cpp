#include <iostream>
#include "rootsOfEquation.h"
#include "linearEquations.h"
#include "quadraticEquations.h"

// pdf zad 5
int main() {

	rootsOfEquation** root = new rootsOfEquation * [2];
	root[0] = new linearEquations(8, 16);
	root[1] = new quadraticEquations(1, -2, -3);

	for (int i = 0; i < 2; i++)
	{
		root[i]->getRoots();
	}

	return 0;
}