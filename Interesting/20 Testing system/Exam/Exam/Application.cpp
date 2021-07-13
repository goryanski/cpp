#include "Application.h"

Application::Application()
{
	userStorage = UsersStorage::getInstance();
	utils = Utils::getInstance();
}

void Application::start()
{
	// ����� � ������ ������ �������� ��� ������ ����� � ��������� (�� ������� �������)
	if (!adminExist()) {
		adminRegistration();		
	}

	while (true) {
		system("cls");
		menu();

		int selection;
		cin >> selection;
		runAction(selection);

		system("pause");
	}
}

void Application::menu()
{
	cout << "[1] Login" << endl;
	cout << "[2] Registration" << endl;
	cout << "[0] Close application" << endl;
	cout << "Your choice: ";
}

void Application::runAction(int action)
{
	switch (action)
	{
	case LOGIN:
		login();
		break;
	case REGISTRATION:
		accountMaanagement.createUser();
		break;
	case EXIT:
		exit(EXIT_SUCCESS);
		break;
	}
}

void Application::adminRegistration()
{
	cout << "Registration for admin:" << endl;
	Account admin = accountMaanagement.inputAccount();

	try {
		adminLoginHelper.saveAdminAccount(admin);
		cout << "Registration complete." << endl;
		system("pause");
	}
	catch (IncorrectRegistrationInfoException & ex) {
		cout << ex.what() << endl;
		system("pause");
		system("cls");
		adminRegistration();
	}
}

void Application::login()
{
	system("cls");
	cin.ignore(32767, '\n');

	Account account = accountMaanagement.inputAccount();

	if (isAdminAccount(account)) {
		// ��������� ������ � ���� � ����� ������ 
		try {
			adminLoginHelper.isPasswordValid(account.getPassword());

			AdminPanelApplication app(account);
			app.start();
		}
		catch (IncorrectPasswordException & ex) {
			cout << ex.what() << endl;
		}
	}
	else {
		try {
			userStorage->checkUser(account.getLogin(), account.getPassword());

			// ��� ��������������� ������������
			UserPanelApplication app(account);
			app.start();
		}
		catch (UserNotFoundException & ex) {
			cout << ex.what() << endl;
		}
		catch (IncorrectPasswordException & ex) {
			cout << ex.what() << endl;
		}
	}	
}

bool Application::isAdminAccount(Account account)
{
	// ������� �����, ������� ������� � ����� ������ � ��������� �����
	string existlogin = adminLoginHelper.readAdminLogin();

	return account.getLogin() == existlogin;
}

bool Application::adminExist()
{
	// ���� ���� ��������� - ���� ���������� - ����� ����������, ����� - �� ����������
	ifstream is(utils->ADMIN_PATH);
	if (is.is_open()) {
		is.close();
		return true;
	}
	else {
		return false;
	}
}
