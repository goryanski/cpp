#pragma once
#include <iostream>
#include "String.h"
using std::copy;

class Statistics;

class PriorityQueue
{
	static PriorityQueue* instance;
	String* names;
	int* priorities;
	int count;
	int capacity;
	PriorityQueue();
public:	
	static PriorityQueue* getInstance();
	~PriorityQueue();

	void add(char* newName, int priority);
	String extract();
	void clear();
	bool isEmpty();
	bool isFull();
	void resize(int length);

	friend Statistics;
};

