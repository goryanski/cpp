#include "UserPanelApplication.h"

UserPanelApplication::UserPanelApplication(Account user)
	: user(user), testPassing(user)
{
	isAccessAllowed = true;
}

void UserPanelApplication::start()
{
	while (isAccessAllowed) {
		system("cls");
		cout << "Hello, " << user.getLogin() << endl;
		menu();

		int selection;
		cin >> selection;
		runAction(selection);
	}
}

void UserPanelApplication::menu()
{
	cout << "[1] Show your previous test results" << endl;
	cout << "[2] Run new test" << endl;
	cout << "[0] Exit" << endl;
	cout << "Your choice: ";
}

void UserPanelApplication::runAction(int action)
{
	switch (action)
	{
	case RESULTS:
		testPassing.showUserResults(user.getLogin());
		break;
	case RUN_TEST:
		testPassing.runTest();
		break;
	case EXIT:
		isAccessAllowed = false;
		break;
	}
}


