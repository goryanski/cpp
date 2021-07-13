#pragma once
#include "UserPanelApplication.h"
#include "AdminPanelApplication.h"

class Application
{
	enum {
		LOGIN = 1,
		REGISTRATION,
		EXIT = 0
	};
public: 
	Application(); 
	void start();
private:
	AdminLoginHelper adminLoginHelper;
	Utils* utils;
	UsersStorage* userStorage;
	UsersManagement accountMaanagement;
	
	void menu();
	void runAction(int);

	bool adminExist();
	bool isAdminAccount(Account);
	void adminRegistration();	
	void login();
};

