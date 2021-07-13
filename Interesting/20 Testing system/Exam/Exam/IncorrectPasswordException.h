#pragma once
#include <iostream>

using std::exception;

class IncorrectPasswordException : public exception
{
public:
	IncorrectPasswordException();
	IncorrectPasswordException(const char*);
};

