#pragma once
#include <iostream>

using std::exception;

class IncorrectRegistrationInfoException : public exception
{
public:
	IncorrectRegistrationInfoException();
	IncorrectRegistrationInfoException(const char*);
};