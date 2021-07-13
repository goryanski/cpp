#pragma once
#include <iostream>
#include "List.h"
using std::copy;

class Queue : public List
{
	int* queue;
	int count;
	int capacity;
public:
	Queue(int capacity);
	~Queue();

	// גלוסעמ add ט extract
	void addToTail(int value) override;
	int removeTail() override;
	void showList() override;

	void clear();
	bool isEmpty();
	bool isFull();
	void resize(int length);
};
