#include "AutoShop.h"
void AutoShop::start()
{
	int action;
	while (true) {
		menu();
		cin >> action;
		cin.ignore();

		switch (action) {
		case ADD_EMPLOYEE:
			addEmployee();
			break;
		case REMOVE_EMPLOYEE:
			showEmployees();
			removeEmployee();
			break;
		case EDIT_EMPLOYEE:
			showEmployees();
			editEmployee();
			break;
		case SHOW_EMPLOYEES:
			showEmployees();
			break;
		case ADD_CAR:
			addCar();
			break;
		case REMOVE_CAR:
			showCars();
			removeCar();
			break;
		case EDIT_CAR:
			showCars();
			editCar();
			break;
		case SHOW_CARS:
			showCars();
			break;
		case EXIT:
			exit(0);
			break;
		}
	}
}

void AutoShop::menu()
{
	cout << "\n[1] Add employee\n";
	cout << "[2] Remove employee\n";
	cout << "[3] Edit employee\n";
	cout << "[4] Show employees\n\n";

	cout << "[5] Add car\n";
	cout << "[6] Remove car\n";
	cout << "[7] Edit car\n";
	cout << "[8] Show cars\n\n";

	cout << "[0] Exit\n";
	cout << "\nYour choice: ";
}

void AutoShop::addEmployee()
{
	system("cls");
	char fio[30];
	cout << "Enter FIO: ";
	gets_s(fio);

	int age;
	cout << "Enter age: ";
	cin >> age;

	Employee employee(fio, age);
	
	EmployeesStorage* storage = EmployeesStorage::getInstance();
	storage->add(employee);
	cout << "Added.\n";
}

void AutoShop::removeEmployee()
{
	int index;
	cout << "\n Enter number of employee to delete: ";
	cin >> index;

	EmployeesStorage* storage = EmployeesStorage::getInstance();
	if (index <= storage->getCountEmployees() && index > 0) {
		storage->remove(index - 1);
		cout << "Deleted.\n";
	}
	else {
		cout << "Wrong number\n";
	}
}

void AutoShop::editEmployee()
{
	int index;
	cout << "\n Enter number of employee to edit: ";
	cin >> index;

	EmployeesStorage* storage = EmployeesStorage::getInstance();
	if (index <= storage->getCountEmployees() && index > 0) {
		storage->edit(index - 1);
		cout << "Edited.\n";
	}
	else {
		cout << "Wrong number\n";
	}
}

void AutoShop::showEmployees()
{
	system("cls");
	EmployeesStorage* storage = EmployeesStorage::getInstance();
	Employee* employees = storage->getEmployees();

	for (int i = 0; i < storage->getCountEmployees(); i++) {
		cout << i + 1 << ". " << employees[i] << "\n";
	}
}



// for cars
void AutoShop::addCar()
{
	system("cls");
	char model[15];
	cout << "Enter model: ";
	gets_s(model);

	int price;
	cout << "Enter price: ";
	cin >> price;

	Car car(model, price);

	CarsStorage* storage = CarsStorage::getInstance();
	storage->add(car);
	cout << "Added.\n";
}

void AutoShop::removeCar()
{
	int index;
	cout << "\n Enter number of car to delete: ";
	cin >> index;

	CarsStorage* storage = CarsStorage::getInstance();
	if (index <= storage->getCountCars() && index > 0) {
		storage->remove(index - 1);
		cout << "Deleted.\n";
	}
	else {
		cout << "Wrong number\n";
	}
}

void AutoShop::editCar()
{
	int index;
	cout << "\n Enter number of car to edit: ";
	cin >> index;

	CarsStorage* storage = CarsStorage::getInstance();
	if (index <= storage->getCountCars() && index > 0) {
		storage->edit(index - 1);
		cout << "Edited.\n";
	}
	else {
		cout << "Wrong number\n";
	}
}

void AutoShop::showCars()
{
	system("cls");
	CarsStorage* storage = CarsStorage::getInstance();
	Car* cars = storage->getCars();

	for (int i = 0; i < storage->getCountCars(); i++) {
		cout << i + 1 << ". " << cars[i] << "\n";
	}
}
