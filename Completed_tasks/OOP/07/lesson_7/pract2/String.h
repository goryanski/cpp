#pragma once
#include <iostream>
using std::cout;

class Stack;

class String
{
	char* str;
	int length;
public:
	String();
	String(char* str);
	void showStr();
	friend Stack;
};

