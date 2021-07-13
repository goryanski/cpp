#include "String.h"

String::String()
{
	str = nullptr;
	length = 0;
}

String::String(char* str)
{
	this->length = strlen(str) + 1;
	this->str = new char[this->length];
	strcpy_s(this->str, this->length, str);
}

void String::showStr()
{
	cout << str << "\n";
}
