#include "IncorrectRegistrationInfoException.h"

IncorrectRegistrationInfoException::IncorrectRegistrationInfoException()
	: exception("Incorrect registration info")
{
}

IncorrectRegistrationInfoException::IncorrectRegistrationInfoException(const char* message)
	: exception(message)
{
}