#pragma once
#include <iostream>
#include "AutoShop.h"
using std::cin;

class Application
{
	enum {
		FIND_BY_BRAND = 1,
		FIND_BY_MODEL,
		FIND_BY_COLOR,
		FIND_BY_PRICE,
		FIND_BY_YEAR,
		FIND_BY_COUNTRY,
		FIND_CHEAPEST,
		FIND_EXPENSIVE,
		PRINT_BY_COLOR,
		PRINT_BY_YEAR,
		PRINT_BY_COUNTRY,
		PRINT_BY_PRICE,
		EXIT = 0
	};
	AutoShop* autoShop;
	void menu();
public:	
	Application(AutoShop* autoShop);
	void start();
};

