#include "fileManipulation.h"

FileManipulation::FileManipulation(map<string, vector<string>> world)
{
	this->world = world;
}

void FileManipulation::writeToFile()
{
	ofstream os("World.txt", ios::out);
	
		if (os.is_open()) {
			os << world.size() << endl;
			for_each(world.begin(), world.end(), [&os](pair<string, vector<string>> pair) {
				os << pair.first << endl;
				os << pair.second.size() << endl;
				for_each(pair.second.begin(), pair.second.end(), [&os](string str) {
					os << str << " ";
					});
				os << endl;
				});
	
			cout << "File was changed.\n" << endl;
			os.close();
		}
		else {
			cout << "Error opening file\n";
		}
}

void FileManipulation::readFile()
{
	world.clear();

	ifstream is("World.txt", ios::in);

	if (is.is_open()) {
		int countCountries;
		is >> countCountries;

		for (int i = 0; i < countCountries; i++) {
			string country;
			is >> country;
			int countCities;

			is >> countCities;
			string city;
			vector<string> cities;
			for (int j = 0; j < countCities; j++) {
				is >> city;
				cities.push_back(city);
			}
			world.insert(make_pair(country, cities));
		}
		is.close();
	}
	else {
		cout << "Error opening file\n";
	}
}

void FileManipulation::addCountry()
{
	string country;
	cout << "Enter country: ";
	cin >> country;
	cout << "How many cities do you want to add? ";
	int count;
	cin >> count;
	string city;
	vector<string> cities;
	for (int i = 0; i < count; i++) {
		cout << "Enter city: ";
		cin >> city;
		cities.push_back(city);
	}
	world.insert(make_pair(country, cities));
	cout << "Added.\n";
}

void FileManipulation::delCountry()
{
	auto result = findCountry();
	
	if (result != world.end()) {
		// удаляем по итератору. удаляем все, потому что города не могут быть без страны, как и страна не 
		// может быть без городов
		world.erase(result);
		cout << "Deleted.\n";
		writeToFile();
	}
	else {
		cout << "Country not found" << endl;
	}
}

void FileManipulation::changeCity()
{
	auto result = findCities();

	if (result != world.end()) {
		string city;
		cout << "Enter name of city you want to change: ";
		cin >> city;
		string newCity;
		cout << "Enter new name: ";
		cin >> newCity;

		replace_if(result->second.begin(), result->second.end(), [city](string str) {
			return str == city;
		}, newCity);

		writeToFile();
	}
}

map<string, vector<string>>::iterator FileManipulation::findCities()
{	
	auto result = findCountry();

	if (result != world.end()) {
		for_each(result->second.begin(), result->second.end(), [](string str) {
			cout << str << " ";
		});
		cout << endl;
	}
	else {
		cout << "Country not found" << endl;
	}	
	return result;
}

void FileManipulation::getCountCities()
{
	auto result = findCountry();

	if (result != world.end()) {
		cout << "There're " << result->second.size() << " cities\n";
	}
	else {
		cout << "Country not found" << endl;
	}

	int count = 0;
	for_each(world.begin(), world.end(), [&count](pair<string, vector<string>> pair) {
		count += pair.second.size();
	});
	cout << "World has " << count << " cities\n";
}

void FileManipulation::printCountries()
{
	if (!world.empty()) {
		cout << "List of countries:\n";
		for_each(world.begin(), world.end(), [](pair<string, vector<string>> pair) {
			cout << pair.first << "\n";
		});
	}
	else {
		cout << "List is empty\n";
	}
}

void FileManipulation::printAllWorld()
{
	if (!world.empty()) {
		for_each(world.begin(), world.end(), [](pair<string, vector<string>> pair) {

			cout << pair.first << ":\n";
			for_each(pair.second.begin(), pair.second.end(), [](string str) {
				cout << "\t" << str << endl;
			});
		});
	}
	else {
		cout << "List is empty\n";
	}
}

map<string, vector<string>>::iterator FileManipulation::findCountry()
{
	string country;
	cout << "Enter country: ";
	cin >> country;
	auto result = find_if(world.begin(), world.end(), [country](pair<string, vector<string>> pair) {
		return pair.first == country;
	});

	return result;
}
