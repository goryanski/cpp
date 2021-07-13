#include "EmployeesStorage.h"

EmployeesStorage* EmployeesStorage::instance = nullptr;

EmployeesStorage::EmployeesStorage()
{
	size = 0;
	capacity = 2;
	arrEmployees = new Employee[capacity];
}

EmployeesStorage* EmployeesStorage::getInstance()
{
	if (instance == nullptr) {
		instance = new EmployeesStorage();
	}
	return instance;
}

void EmployeesStorage::add(Employee employee)
{
	if (size == capacity) {
		resize(5);
	}
	arrEmployees[size++] = employee; 
}
void EmployeesStorage::remove(int indexDel)
{	
	for (int i = indexDel; i < size - 1; i++) {
		arrEmployees[i] = arrEmployees[i + 1];
	}
	int newSize = size - 1;
	Employee* tmp = new Employee[newSize];
	copy(arrEmployees, arrEmployees + newSize, tmp);
	delete[] arrEmployees;
	arrEmployees = tmp;
	size--;
}

void EmployeesStorage::edit(int index)
{	
	cin.ignore();
	char fio[30];
	cout << "Enter new FIO: ";
	gets_s(fio);

	int age;
	cout << "Enter new age: ";
	cin >> age;

	Employee newEmployee(fio, age);
	arrEmployees[index] = newEmployee;
}

void EmployeesStorage::resize(int count)
{
	int newCapacity = capacity + count;
	Employee* tmp = new Employee[newCapacity];
	copy(arrEmployees, arrEmployees + size, tmp);
	delete[] arrEmployees;
	arrEmployees = tmp;
	capacity = newCapacity;
}

Employee* EmployeesStorage::getEmployees()
{
	return arrEmployees;
}

int EmployeesStorage::getCountEmployees() const
{
	return size;
}

