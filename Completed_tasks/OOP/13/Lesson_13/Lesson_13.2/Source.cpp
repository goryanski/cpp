#include <iostream>
#include "Employer.h"
#include "Manager.h"
#include "President.h"
#include "Worker.h"

using std::endl;
using std::cin;

int main() {
	enum Employers {
		PRESIDENT = 1,
		MANAGER,
		WORKER
	};

	Employer* employer = nullptr;	
	cout << "[1] President" << endl;
	cout << "[2] Manager" << endl;
	cout << "[3] Worker" << endl;
	int action;
	cin >> action;

	switch (action) {
	case PRESIDENT:
		employer = new President(90000, 20);
		break;
	case MANAGER:
		employer = new Manager(15, 3000);
		break;
	case WORKER:
		employer = new Worker(9, (char*)"Oldest salesman");
		break;
	}
	employer->print();

	return 0;
}