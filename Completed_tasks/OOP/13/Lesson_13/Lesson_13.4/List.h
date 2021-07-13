#pragma once
#include "Node.h"
#include <iostream>
using std::cout;

class List {
protected:
	Node* head;
	Node* tail;
public:
	List();
	List(const List& obj);
	~List();

	bool isEmpty();

	// что бы не создавать новые ф-ции, добавления и извлечения, воспользуемся существующими addToTail() и removeTail()
	virtual void addToTail(int value);
	// void ф-ция не подойдет, по этому будем что-то возврящать
	virtual int removeTail();
	virtual void showList();

	void addToHead(int value);
	void insert(int value, int num);
	void removeHead();	
	void removePos(int num);
	void removeAll();

	List operator + (const List& obj);
	List& operator = (const List& obj);
	List operator - (const List& obj);
};

