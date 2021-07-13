#include "UserAlreadyExistsException.h"

UserAlreadyExistsException::UserAlreadyExistsException()
	: exception("User already exists")
{
}

UserAlreadyExistsException::UserAlreadyExistsException(const char* message)
	: exception(message)
{
}
