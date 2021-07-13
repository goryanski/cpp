#pragma once
#include "TestPassing.h"

class UserPanelApplication
{
	enum {
		RESULTS = 1,
		RUN_TEST,
		EXIT = 0
	};
	Account user;			// авторизованный пользователь				
	bool isAccessAllowed;		// разрешен ли доступ
	
	TestPassing testPassing;

	void menu();
	void runAction(int);
public:
	UserPanelApplication(Account);
	void start();
};
