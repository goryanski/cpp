#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Utils.h"
#include "Account.h"
#include "IncorrectRegistrationInfoException.h"
#include "IncorrectPasswordException.h"
#include <string>
using std::ofstream;
using std::ifstream;
using std::ios;
using std::endl;

class AdminLoginHelper
{
	Utils* utils;
	string encryptionKey;

public:
	AdminLoginHelper();

	void saveAdminAccount(Account);
	string readAdminLogin();
	bool isPasswordValid(string);
	void accountValidation(Account);

	string xor_crypt(const string, string);
	string decryptionString(string);
};
