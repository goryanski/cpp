#include <iostream>
#include "Airplane.h"
using std::cout;

int main() {
	// 1-й самолет
	int countPassengers1 = 25;	
	Airplane plane1(50, FOR_SOLDIERS);
	for (int i = 0; i < countPassengers1; i++) {
		++plane1;
	}
	plane1.print();
	cout << "Capacity plane1: " << plane1.getCapacity() << "\n";

	// 2-й самолет
	int countPassengers2 = 32;
	Airplane plane2(40, FOR_PEOPLE);
	for (int i = 0; i < countPassengers2; i++) {
		++plane2;
	}
	plane2.print();
	cout << "Capacity plane2: " << plane2.getCapacity() << "\n";

	// сравнения
	cout << "\n\nAre the types the same?\n";
	cout << (plane1 == plane2);

	cout << "\n\nDoes plane #1 has more seats for passengers?\n";
	cout << (plane1 > plane2);

	return 0;
}