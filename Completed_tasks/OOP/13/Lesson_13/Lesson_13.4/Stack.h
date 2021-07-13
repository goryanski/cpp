#pragma once
#include <iostream>
#include "List.h"

using std::copy;
using std::cout;

class Stack : public List
{
	enum { EMPTY = -1 };
	int* arr;
	int top;
	int capacity;
public:
	Stack(int capacity);
	~Stack();

	// גלוסעמ push ט pop
	void addToTail(int value) override;
	int removeTail() override;
	void showList() override;

	void clear();
	bool isEmpty();
	bool isFull();
	void resize(int length);
	void showExtracted();
	int getElement(int ind);
	int getTop();
};
