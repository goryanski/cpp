#include "Manager.h"

Manager::Manager(int experience, int salary)
{
	this->experience = experience;
	this->salary = salary;
}

void Manager::print()
{
	cout << "Experience (years): " << experience << "\n";
	cout << "Salary: " << salary << "\n";
}
