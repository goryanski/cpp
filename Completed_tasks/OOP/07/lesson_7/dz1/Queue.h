#pragma once
#include <iostream>
using std::copy;

class Game;

class Queue
{
	char* queue;			
	int count;			
	int capacity;		
public:
	Queue(int capacity);
	~Queue();

	void add(char value);
	char extract();
	void clear();
	bool isEmpty();
	bool isFull();
	void resize(int length);

	friend Game;
};

