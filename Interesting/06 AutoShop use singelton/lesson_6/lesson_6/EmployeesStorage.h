#pragma once
#include "Employee.h"
using std::copy;
using std::cout;
using std::cin;

class EmployeesStorage
{
	static EmployeesStorage* instance;

	Employee* arrEmployees;
	int size;
	int capacity; 
	EmployeesStorage();
public:
	static EmployeesStorage* getInstance();
	void add(Employee employee);
	void remove(int indexDel);
	void edit(int index);
	void resize(int count);
	Employee* getEmployees();
	int getCountEmployees() const;
};

