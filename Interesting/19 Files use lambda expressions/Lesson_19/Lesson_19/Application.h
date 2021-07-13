#pragma once
#include <iostream>
#include <io.h>
#include "FileManipulation.h"

class Application
{
	enum {
		ADD = 1,
		DELETE,
		CHANGE_CITY,
		FIND_CITIES,
		COUNT_CITIES,
		PRINT_COUNTRIES,
		PRINT_ALL,
		EXIT = 0
	};
	FileManipulation* fileManipulation;
	void menu();
	void checkFile();
public:
	Application(FileManipulation* fileManipulation);
	void start();
};

