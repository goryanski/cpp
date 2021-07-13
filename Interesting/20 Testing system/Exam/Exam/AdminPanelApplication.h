#pragma once
#include <iostream>
#include "Account.h"
#include "UsersManagement.h"
#include "TestsManagement.h"
#include "Utils.h"
#include "AdminLoginHelper.h"
#include "testEditor.h"

class AdminPanelApplication
{
	enum {
		USERS_MANAGEMENT = 1,
		TESTS_MANAGEMENT,
		SHOW_STATISTICS,
		CHANGE_ACCOUNT,
		COPY_FILES,
		CREATE = 1,
		DELETE,
		CHANGE,
		ADD_CATEGORY = 1,
		ADD_TEST,
		DEL_TEST,
		DEL_CATEGORY,
		EDIT,
		SHOW_BY_CATEGORY = 1,
		SHOW_BY_TEST,
		SHOW_BY_USER,
		EXIT = 0
	};

	Utils* utils;
	bool isAccessAllowed;
	Account admin;

	void menu();
	void runAction(int);

	void usersMaanagement();
	void testsManagement();
	void showStatistics();
	void changeAccount();
public:
	AdminPanelApplication(Account);
	void start();
};
