#include <iostream>
#include "Application.h"
#include "FileManipulation.h"

int main() {
	map<string, vector<string>> world;
	
	vector<string> ukraineCities = { "Dnipro", "Kiev", "Charkov" };
	world.insert(make_pair("Ukraine", ukraineCities));

	vector<string> PolandCities = { "Krakov", "Poznan", "Warzhava" };
	world.insert(make_pair("Poland", PolandCities));

	vector<string> usaStates = { "Vegas", "Florida", "California" };
	world.insert(make_pair("USA", usaStates));


	FileManipulation manipulation(world);

	Application app(&manipulation);
	app.start();

	return 0;
}