#pragma once
#include <iostream>
#include "String.h"

using std::copy;

class Stack
{
	enum { EMPTY = -1 };
	String* arr;
	int top;		
	int capacity;
public:
	Stack(int capacity);
	~Stack();

	void push(char* newStr);
	String pop();
	void clear();
	bool isEmpty();
	bool isFull();
	void resize(int length);

	void showStack();	
	void showExtracted();
	String getElement(int ind);
	int getTop();	
};
