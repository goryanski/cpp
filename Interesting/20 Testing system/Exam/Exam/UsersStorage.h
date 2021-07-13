#pragma once
#include <iostream>
#include "UserInfo.h"
#include <vector>
#include <fstream>
#include "Utils.h"
#include <algorithm>
#include "IncorrectPasswordException.h"
#include "UserNotFoundException.h"
#include "UserAlreadyExistsException.h"
#include "IncorrectRegistrationInfoException.h"
#include "Account.h"
#include "AdminLoginHelper.h"
using std::vector;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::endl;
using std::cout;

class UsersStorage
{
	static UsersStorage* instance;
	vector<UserInfo> users;
	Utils* utils;

	UsersStorage();
public:
	static UsersStorage* getInstance();
	void load();
	void save();

	void userValidation(UserInfo);
	vector<UserInfo>::iterator findUser(string);
	void removeUser(vector<UserInfo>::iterator);
	void changeUser(vector<UserInfo>::iterator, UserInfo);
	bool checkUser(string, string);
	bool createUser(UserInfo);
	void showUsers();
};