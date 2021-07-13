#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::map;
using std::make_pair;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::for_each;
using std::pair;
using std::cin;
using std::find_if;
using std::replace_if;

class FileManipulation
{
	map<string, vector<string>> world;
public:
	void writeToFile();
	void readFile();

	void addCountry();
	void delCountry();
	void changeCity();
	map<string, vector<string>>::iterator findCities();
	void getCountCities();
	void printCountries();
	void printAllWorld();

	map<string, vector<string>>::iterator findCountry();

	FileManipulation(map<string, vector<string>> world);
};

