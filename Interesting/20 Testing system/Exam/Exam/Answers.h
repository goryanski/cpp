#pragma once
#include <iostream>
#include <vector>
#include "Utils.h"
#include <fstream>
#include <algorithm>
using std::vector;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::for_each;

class TestsManagement;

class Answers
{
	vector<int> answers;
	Utils* utils;
public:
	Answers();

	void writeToFile(string);
	vector<int> readFromFile(string);
	friend TestsManagement;
};
