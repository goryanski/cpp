#pragma once
#include "Employer.h"
#include <iostream>
using std::cout;

class Manager : public Employer {
	int experience;
	int salary;
public:
	Manager(int experience, int salary);
	void print() override;
};