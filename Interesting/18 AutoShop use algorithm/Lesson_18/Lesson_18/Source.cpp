#include <iostream>
#include "Auto.h"
#include "Application.h"
#include "AutoShop.h"
#include <vector>
using std::vector;

int main() {

	vector<Auto> cars = {
		Auto("Lexus", "2320sa", "blue", 30000, 2011, "Ukraine"),
		Auto("Zhigul", "5", "red", 3000, 1990, "Russia"),
		Auto("Zaporozhec", "2120sT", "green", 4000, 1990, "Ukraine"),
		Auto("Ferrary", "hdhd11", "yellow", 80000, 2005, "Italy"),
		Auto("Audi", "55rr0sa", "black", 40000, 2015, "USA")
	};

	AutoShop autoShop(cars);

	Application app(&autoShop);
	app.start();
}