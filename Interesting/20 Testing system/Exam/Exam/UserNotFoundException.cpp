#include "UserNotFoundException.h"

UserNotFoundException::UserNotFoundException()
	: exception("User not found")
{
}

UserNotFoundException::UserNotFoundException(const char* message)
	: exception(message)
{
}
