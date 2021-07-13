#pragma once
#include <iostream>
using std::cout;

class String
{
	char* str;
	int length;
public:
	String();
	String(char* str);
	String(const String& obj);
	~String();
	void setStr(char* name);
	void showStr();
	String& operator = (const String& obj);
};

