#include "UsersStorage.h"

UsersStorage* UsersStorage::instance = nullptr;

UsersStorage::UsersStorage()
{
	utils = Utils::getInstance();
	load();
}

UsersStorage* UsersStorage::getInstance()
{
	if (instance == nullptr) {
		instance = new UsersStorage();
	}
	return instance;
}

void UsersStorage::load()
{
	AdminLoginHelper encryption;

	//открытие файла на чтение
	ifstream is(utils->USERS_STORAGE_PATH, ios::out | ios::binary);
	if (is.is_open()) {
		//очистка вектора
		users.clear();

		int size;
		is >> size;
		is.ignore(32767, '\n');

		for (int i = 0; i < size; i++) {
			UserInfo user;
			
			is >> user;

			// расшифруем и подменим пароль с логином
			string encryptedLogin = user.getUserAccount().getLogin();
			string decryptedLogin = encryption.decryptionString(encryptedLogin);

			string encryptedPassword = user.getUserAccount().getPassword();
			string decryptedPassword = encryption.decryptionString(encryptedPassword);

			Account  decryptedAccount(decryptedLogin, decryptedPassword);
			user.setUserAccount(decryptedAccount);

			users.push_back(user);
		}
		is.close();
	}
}

void UsersStorage::save()
{
	//открытие файла на запись
	AdminLoginHelper encryption;
	ofstream os(utils->USERS_STORAGE_PATH, ios::in | ios::binary | ios::trunc);
	if (os.is_open()) {
		os << users.size() << endl;
		for_each(users.begin(), users.end(), [&os, &encryption](UserInfo& user) {

			// зашифруем и подменим пароль с логином
			string existsLogin = user.getUserAccount().getLogin();
			string encryptionLogin = encryption.xor_crypt("abc", existsLogin);

			string existsPassword = user.getUserAccount().getPassword();
			string encryptionPassword = encryption.xor_crypt("abc", existsPassword);

			Account  encryptionAccount(encryptionLogin, encryptionPassword);
			user.setUserAccount(encryptionAccount);

			// запишем в файл юзера с зашифрованным аккаунтом
			os << user << endl;

			// обратно расшифруем и подменим пароль с логином для того что бы в векторе всегда 			
			// хранились расшифрованные, а в файле - зашифрованные
			string encryptedLogin = user.getUserAccount().getLogin();
			string decryptedLogin = encryption.decryptionString(encryptedLogin);

			string encryptedPassword = user.getUserAccount().getPassword();
			string decryptedPassword = encryption.decryptionString(encryptedPassword);

			Account  decryptedAccount(decryptedLogin, decryptedPassword);

			user.setUserAccount(decryptedAccount);
		});

		os.close();
	}
}

void UsersStorage::userValidation(UserInfo user)
{
	if (user.getName().length() < 2 || user.getName().length() > 30) {
		throw IncorrectRegistrationInfoException("Name must be 2-30 symbols");
	}
	if (user.getAddress().length() < 5 || user.getAddress().length() > 30) {
		throw IncorrectRegistrationInfoException("Address must be 5-30 symbols");
	}
	if (user.getPhone().length() < 10 || user.getPhone().length() > 13) {
		throw IncorrectRegistrationInfoException("Phone must be 10-13 symbols");
	}
	if (user.getUserAccount().getLogin().length() < 4 || user.getUserAccount().getLogin().length() > 15) {
		throw IncorrectRegistrationInfoException("Login must be 4-15 symbols");
	}
	if (user.getUserAccount().getPassword().length() < 5 || user.getUserAccount().getPassword().length() > 16) {
		throw IncorrectRegistrationInfoException("Password must be 5-16 symbols");
	}
}

vector<UserInfo>::iterator UsersStorage::findUser(string login)
{
	//поиск пользователя по логину
	auto it = find_if(users.begin(), users.end(), [&login](const UserInfo& user) {
		return user.getUserAccount().getLogin() == login;
	});

	//пользователь не был найден
	if (it == users.end()) {
		throw UserNotFoundException("Account not found");
	}
	return it;
}

void UsersStorage::removeUser(vector<UserInfo>::iterator it)
{
	users.erase(it);
	save();
}

void UsersStorage::changeUser(vector<UserInfo>::iterator it, UserInfo newUser)
{
	*it = newUser;
	save();
}

bool UsersStorage::checkUser(string login, string password)
{
	auto it = findUser(login);

	// разыменовываем итератор и получаем его адрес
	UserInfo* user = &*it;
	if (user->getUserAccount().getPassword() != password) {
		throw IncorrectPasswordException("Incorrect user password");
	}

	return true;
}

bool UsersStorage::createUser(UserInfo user)
{
	auto it = find_if(users.begin(), users.end(), [&user](const UserInfo& u) {
		return u.getUserAccount().getLogin() == user.getUserAccount().getLogin();
	});

	// пользователь существует
	if (it != users.end()) {
		throw UserAlreadyExistsException();
	}

	userValidation(user);

	users.push_back(user);
	save();

	return true;
}

void UsersStorage::showUsers()
{
	int counter = 1;
	for_each(users.begin(), users.end(), [&counter](const UserInfo& user) {
		cout << "[" << counter << "]:" << endl;
		user.showUser();
		counter++;
	});
}
