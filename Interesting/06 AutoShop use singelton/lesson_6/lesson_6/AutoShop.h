#pragma once
#include <iostream>
#include "Employee.h"
#include "Car.h"
#include "EmployeesStorage.h"
#include "CarsStorage.h"
using std::cin;
using std::cout;

enum Actions {
	ADD_EMPLOYEE = 1,
	REMOVE_EMPLOYEE,
	EDIT_EMPLOYEE,
	SHOW_EMPLOYEES,

	ADD_CAR,
	REMOVE_CAR,
	EDIT_CAR,
	SHOW_CARS,

	EXIT = 0
};

class AutoShop
{
public:
	void start();
private:
	void menu();

	void addEmployee();
	void removeEmployee();
	void editEmployee();
	void showEmployees();
	
	void addCar();
	void removeCar();
	void editCar();
	void showCars();
};

