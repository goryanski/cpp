#pragma once
#include <iostream>

using std::exception;

class UserNotFoundException : public exception
{
public:
	UserNotFoundException();
	UserNotFoundException(const char*);
};
