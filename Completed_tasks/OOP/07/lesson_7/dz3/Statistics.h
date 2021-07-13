#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <ctime>
#include <iomanip>
#include "PriorityQueue.h"
using std::cout;
using std::setw;
using std::left;

class Statistics
{
	static Statistics* instance;
	PriorityQueue* queue;
	String* namesForStatistics;
	String* timePrint;
	int sizeArrStatistics;
	Statistics();
public:	
	static Statistics* getInstance();
	~Statistics();
	void fillStatistics();
	void showStatistics();
};

