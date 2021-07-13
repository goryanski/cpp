#pragma once
#include <iostream>
#include <conio.h>
#include "PriorityQueue.h"
#include "Statistics.h"
using std::cout;
using std::cin;

class Printer
{
	enum { ENTER = 13, ESC = 27 };
	void addRequests();
public:
	void printMe();
};

