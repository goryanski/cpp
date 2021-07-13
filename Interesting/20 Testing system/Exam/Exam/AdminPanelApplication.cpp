#include "AdminPanelApplication.h"

AdminPanelApplication::AdminPanelApplication(Account admin)
	: admin(admin)
{
	isAccessAllowed = true;
	utils = Utils::getInstance();
}

void AdminPanelApplication::menu()
{
	cout << "[1] Users management" << endl;
	cout << "[2] Tests management" << endl;
	cout << "[3] Show statistics" << endl;
	cout << "[4] Change account" << endl;
	cout << "[5] Export data to another folder" << endl;
	cout << "[0] Exit" << endl;
	cout << "Your choice: ";
}

void AdminPanelApplication::runAction(int action)
{
	switch (action)
	{
	case USERS_MANAGEMENT:
		usersMaanagement();
		break;
	case TESTS_MANAGEMENT:
		testsManagement();
		break;
	case SHOW_STATISTICS:
		showStatistics();
		break;
	case CHANGE_ACCOUNT:
		changeAccount();
		break;
	case COPY_FILES:
		DirectoryHelper::copyFiles();
		break;
	case EXIT:
		isAccessAllowed = false;
		break;
	}
}

void AdminPanelApplication::start()
{
	while (isAccessAllowed) {
		system("cls");
		cout << "Hello, " << admin.getLogin() << endl;
		menu();

		int selection;
		cin >> selection;
		runAction(selection);
	}
}

void AdminPanelApplication::usersMaanagement()
{
	UsersManagement usersMaanagement;
	bool comeBack = false;
	while (!comeBack) {
		system("cls");
		cout << "[1] Create user" << endl;
		cout << "[2] Delete user" << endl;
		cout << "[3] Change user" << endl;
		cout << "[0] To main menu" << endl;
		cout << "Your choice: ";

		int selection;
		cin >> selection;

		switch (selection)
		{
		case CREATE:
			usersMaanagement.createUser();
			break;
		case DELETE:
			cin.ignore(32767, '\n');
			usersMaanagement.deleteUser();
			break;
		case CHANGE:
			cin.ignore(32767, '\n');
			usersMaanagement.changeUser();
			break;
		case 0:
			comeBack = true;
			break;
		}
		system("pause");
	}
}

void AdminPanelApplication::testsManagement()
{
	TestsManagement testsManagement;
	bool comeBack = false;
	while (!comeBack) {
		system("cls");
		cout << "[1] Add a new test category" << endl;
		cout << "[2] Add new test" << endl;
		cout << "[3] Delete test" << endl;
		cout << "[4] Delete test category (with tests)" << endl;
		cout << "[5] Edit test" << endl;
		cout << "[0] To main menu" << endl;
		cout << "Your choice: ";

		int selection;
		cin >> selection;

		switch (selection)
		{
		case ADD_CATEGORY:
			testsManagement.addNewCategory();
			break;
		case ADD_TEST:
			testsManagement.addNewTest(testsManagement.selectCategory());
			break;
		case DEL_TEST:
			testsManagement.deleteTest();
			break;
		case DEL_CATEGORY:
			testsManagement.deleteCategory();
			break;
		case EDIT: {
			TestEditor editor;
			editor.testEdit();
			break;
		}
		case 0:
			comeBack = true;
			break;
		}
		system("pause");
	}
}

void AdminPanelApplication::showStatistics()
{
	TestsManagement testsManagement;
	bool comeBack = false;
	while (!comeBack) {
		system("cls");
		cout << "[1] Show statistics by category name" << endl;
		cout << "[2] Show statistics by test name" << endl;
		cout << "[3] Show statistics by user" << endl;
		cout << "[0] To main menu" << endl;
		cout << "Your choice: ";
	
		int selection;
		cin >> selection;

		switch (selection)
		{
		case SHOW_BY_CATEGORY:
			testsManagement.statisticsByCategory();
			break;
		case SHOW_BY_TEST:
			testsManagement.statisticsByTest();
			break;
		case SHOW_BY_USER:
			testsManagement.statisticsByUser();
			break;
		case 0:
			comeBack = true;
			break;
		}
	}	
}

void AdminPanelApplication::changeAccount()
{
	system("cls");
	cout << "Enter new info: " << endl;
	UsersManagement accountMaanagement;
	AdminLoginHelper adminLoginHelper;
	Account admin = accountMaanagement.inputAccount();

	try {
		adminLoginHelper.saveAdminAccount(admin);

		this->admin = admin;
		cout << "Complete." << endl;
		system("pause");
	}
	catch (IncorrectRegistrationInfoException& ex) {
		cout << ex.what() << endl;
		system("pause");
	}
}