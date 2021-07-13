#pragma once
#include <iostream>
#include "Utils.h"
#include "UserInfo.h"
#include "Account.h"
#include "UsersStorage.h"
using std::cin;

// управление пользовател€ми Ц создание, удаление, модификаци€
class UsersManagement
{
	UsersStorage* usersStorage;

	enum {
		CHANGE_NAME = 1,
		CHANGE_ADDRESS,
		CHANGE_PHONE,
		CHANGE_LOGIN,
		CHANGE_PASSWORD,
		CHANGE_ALL
	};
public:
	UsersManagement();

	void createUser();
	UserInfo inputUserInfo();
	Account inputAccount();

	void deleteUser();

	void changeUser();
	int changeMenu();
	void runAction(vector<UserInfo>::iterator, int);

	string enterLogin();
};

