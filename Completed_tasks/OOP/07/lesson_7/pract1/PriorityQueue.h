#pragma once
#include <iostream>

using std::copy;
using std::cout;

class PriorityQueue
{
	int* queue;			
	int* priorities;	
	int count;			
	int capacity;		
public:
	PriorityQueue(int capacity);
	~PriorityQueue();
	void add(int value, int priority);
	int extract();
	void clear();
	bool isEmpty();
	bool isFull();
	void resize(int length);

	// возврат самого большого по приоритету элемента 
	int peek();
	void showWithPriority(int value, int priority);
	void showExtracted();
	void delAnyElement(int ind);
};


