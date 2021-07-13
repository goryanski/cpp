#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include "Firm.h"
using std::cout;
using std::cin;
using std::ofstream;
using std::ifstream;
using std::ios;

enum Actions {
	ADD = 1,
	SEARCH_BY_NAME,
	SEARCH_BY_MANAGER,
	SEARCH_BY_PHONE,
	SEARCH_BY_DIRECTION,
	SHOW_ON_DISPLAY
};

class Catalog
{
	// будем хранить здесь массив фирм и его размер что бы не передавать постоянно в параметрах 
	Firm* arrFirms;
	int countFirms;
	void menu();
	void addToFile();
	void searchByName();
	void searchByManager();
	void searchByPhone();
	void searchByDirection();

	void readFile();
	void showOnDisplay();
public:
	Catalog();
	void start();
};

