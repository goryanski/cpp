#include "String.h"

String::String()
{
	str = nullptr;
	length = 0;
}

String::String(char* str)
{
	setStr(str);
}

String::String(const String& obj)
{
	setStr(obj.str);
}

String::~String()
{
	delete[] str;
}

void String::setStr(char* str)
{
	int newLen = strlen(str) + 1;
	this->str = new char[newLen];
	strcpy_s(this->str, newLen, str);
	length = newLen;
}

void String::showStr()
{
	cout << str;
}

String& String::operator=(const String& obj)
{
	if (this == &obj) {

		return *this;
	}
	setStr(obj.str);
	return *this;		
}
