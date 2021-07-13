#include "IncorrectPasswordException.h"

IncorrectPasswordException::IncorrectPasswordException()
	: exception("Incorrect password")
{
}

IncorrectPasswordException::IncorrectPasswordException(const char* message)
	: exception(message)
{
}
