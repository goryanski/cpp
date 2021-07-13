#pragma once
#include <iostream>
#include "conio.h"
#include "Bus.h"
#include "Tree.h"
#include "Windows.h"
using std::cout;
using std::cin;

enum Actions {
	ADD = 1,
	FIND,
	REMOVE,
	SHOW,
	WRITE
};

class BusStation
{
	Tree* storage;
	void menu();
	void add();
	Leaf* findByNumber();
	void removeBus();
	void showList();
	void writeToFile();
public:
	BusStation();
	void start();
};

