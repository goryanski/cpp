#pragma once
#include "Node.h"
#include <iostream>
using std::cout;

class List {
	Node* head;
	Node* tail;
public:
	List();	
	List(const List& obj);
	~List();

	bool isEmpty();

	void addToTail(int value);
	void addToHead(int value);
	void insert(int value, int num);

	void removeHead();
	void removeTail();
	void removePos(int num);
	void removeAll();

	List operator + (const List& obj);
	List& operator = (const List& obj);
	List operator - (const List& obj);

	void showList();
};
