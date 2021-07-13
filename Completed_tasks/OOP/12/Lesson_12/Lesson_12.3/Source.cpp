#include <iostream>
#include "Vehicle.h"
#include "Auto.h"
#include "Bicycle.h"
#include "Ñart.h"
using std::cout;
using std::cin;

int main() {
	//machine(double speed, double priceOfHour, int capasityPeople, int capasityCargo)
	Auto machine(150, 150, 4, 300);
	Bicycle bicycle(25, 50, 2, 60);
	Ñart cart(15, 30, 10, 700);
	int ch;
	cout << "[1] - Auto\n[2] - Bicycle\n[3] - Cart\n"
		"Enter choice: ";
	cin >> ch;
	int distance;
	switch (ch) {
	case 1:
		cout << "\nMax count peple: " << machine.getCapasityPeople() << "\n";
		cout << "Max count cargo: " << machine.getCapasityCargo() << "kg\n";
		cout << "\nEnter distance: "; 
		cin >> distance;
		cout << "\nTime: " << machine.getTime(distance) << "\n";
		cout << "Price: " << machine.getPrice(distance) << "\n";
		break;
	case 2:
		cout << "\nMax count peple: " << bicycle.getCapasityPeople() << "\n";
		cout << "Max count cargo: " << bicycle.getCapasityCargo() << "kg\n";
		cout << "\nEnter distance: ";
		cin >> distance;
		cout << "\nTime: " << bicycle.getTime(distance) << "\n";
		cout << "Price: " << bicycle.getPrice(distance) << "\n";
		break;
	case 3:
		cout << "\nMax count peple: " << cart.getCapasityPeople() << "\n";
		cout << "Max count cargo: " << cart.getCapasityCargo() << "kg\n";
		cout << "\nEnter distance: ";
		cin >> distance;
		cout << "\nTime: " << cart.getTime(distance) << "\n";
		cout << "Price: " << cart.getPrice(distance) << "\n";
		break;
	}
	return 0;
}