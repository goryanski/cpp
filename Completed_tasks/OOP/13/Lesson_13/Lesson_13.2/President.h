#pragma once
#include "Employer.h"
#include <iostream>
using std::cout;

class President : public Employer {
	int countMoney;
	int countWorkers;
public:
	President(int countMoney, int countWorkers);
	void print() override;
};