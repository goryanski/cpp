#include "UsersManagement.h"

UsersManagement::UsersManagement()
{
	usersStorage = UsersStorage::getInstance();
}

void UsersManagement::createUser()
{
	cin.ignore(32767, '\n');
	system("cls");
	cout << "Registration:" << endl;

	UserInfo user = inputUserInfo();

	try {
		usersStorage->createUser(user);
		cout << "Registration complete." << endl;
	}
	catch (UserAlreadyExistsException& ex) {
		cout << ex.what() << endl;
		system("pause");
		createUser();
	}
	catch (IncorrectRegistrationInfoException& ex) {
		cout << ex.what() << endl;
		system("pause");
		createUser();
	}
}

Account UsersManagement::inputAccount()
{
	string login = enterLogin();

	string password;
	cout << "Password: ";
	getline(cin, password);

	Account account(login, password);
	return account;
}

UserInfo UsersManagement::inputUserInfo()
{
	string name;
	string address;
	string phone;
	Account account;

	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter address: ";
	getline(cin, address);
	cout << "Enter phone: ";
	getline(cin, phone);

	UserInfo user(name, address, phone);
	user.setUserAccount(inputAccount());

	return user;
}

void UsersManagement::deleteUser()
{
	system("cls");
	cout << "List of users:" << endl;
	usersStorage->showUsers();
	cout << endl << "Which user to change?" << endl << "Enter user ";

	try {
		auto it = usersStorage->findUser(enterLogin());

		usersStorage->removeUser(it);
		cout << "User deleted." << endl;
	}
	catch (UserNotFoundException& ex) {
		cout << ex.what() << endl;
	}
}

void UsersManagement::changeUser()
{
	usersStorage->load();
	system("cls");
	cout << "List of users:" << endl;
	usersStorage->showUsers();
	cout << endl << "Which user to change?" << endl << "Enter user ";
	
	try {
		auto it = usersStorage->findUser(enterLogin());

		// далее будем работать с пользователем только через итератор
		system("cls");
		cout << "User information:" << endl;
		(*it).showUser();

		int select = changeMenu();
		runAction(it, select);

		try {
			usersStorage->userValidation(*it);

			usersStorage->save();
			cout << "User changed." << endl;
		}
		catch (IncorrectRegistrationInfoException& ex) {
			cout << ex.what() << endl;
			system("pause");
			changeUser();
		}		
	}
	catch (UserNotFoundException& ex) {
		cout << ex.what() << endl;
	}
}

int UsersManagement::changeMenu()
{
	cout << endl << "What do you want to change?" << endl;
	cout << "[1] User name" << endl;
	cout << "[2] User address" << endl;
	cout << "[3] User phone" << endl;
	cout << "[4] User login" << endl;
	cout << "[5] User password" << endl;
	cout << "[6] All info" << endl;
	cout << "Your choice: ";

	int select;
	cin >> select;

	while (select < 1 || select > 6) {
		cout << "Wrong number, try again: ";
		cin >> select;
	}

	return select;
}

void UsersManagement::runAction(vector<UserInfo>::iterator it, int select)
{
	string str;
	cin.ignore(32767, '\n');
	switch (select) {
	case CHANGE_NAME: {
		cout << "Enter new name: ";
		getline(cin, str);
		(*it).setUserName(str);
	}
		break;
	case CHANGE_ADDRESS: {
		cout << "Enter new address: ";
		getline(cin, str);
		(*it).setUserAddress(str);
	}
		break;
	case CHANGE_PHONE: {
		cout << "Enter new phone: ";
		getline(cin, str);
		(*it).setUserPhone(str);
	}		
		break;
	case CHANGE_LOGIN: {
		cout << "Enter new login: ";
		getline(cin, str);
		(*it).setUserLogin(str);
	}	
		break;
	case CHANGE_PASSWORD: {
		cout << "Enter new password: ";
		getline(cin, str);
		(*it).setUserPassword(str);
	}	
		break;
	case CHANGE_ALL: {
		cout << endl << "Enter new info:" << endl << endl;
		usersStorage->changeUser(it, inputUserInfo());
	}
		break;
	}
}

string UsersManagement::enterLogin()
{
	cout << "login: ";
	string login;
	getline(cin, login);

	return login;
}
