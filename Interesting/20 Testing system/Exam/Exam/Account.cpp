#include "Account.h"

Account::Account()
{
	login = password = "";
}

Account::Account(string login, string password)
	: login(login), password(password)
{
}

string Account::getLogin() const
{
	return login;
}

string Account::getPassword() const
{
	return password;
}

ostream& operator << (ostream& os, const Account& obj) {
	os << obj.login << " " << obj.password;
	return os;
}
istream& operator >> (istream& is, Account& obj) {
	getline(is, obj.login, ' ');
	getline(is, obj.password, '\n');
	return is;
}