#include "Employer.h"
#include <iostream>
using std::cout;

class Worker : public Employer {
	int motivation;
	char positon[20];
public:
	Worker(int motivation, char* positon);
	void print() override;
};