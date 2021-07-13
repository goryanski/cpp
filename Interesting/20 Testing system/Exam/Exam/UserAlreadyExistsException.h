#pragma once
#include <iostream>

using std::exception;

class UserAlreadyExistsException : public exception
{
public:
	UserAlreadyExistsException();
	UserAlreadyExistsException(const char*);
};
