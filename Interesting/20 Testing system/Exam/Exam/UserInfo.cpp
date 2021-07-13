#include "UserInfo.h"

UserInfo::UserInfo()
{
	name = address = phone = "";
}

UserInfo::UserInfo(string name, string address, string phone)
	: name(name), address(address), phone(phone)
{
}

void UserInfo::setUserAccount(Account obj)
{
	account.login = obj.login;
	account.password = obj.password;
}

void UserInfo::setUserName(string name)
{
	this->name = name;
}

void UserInfo::setUserAddress(string address)
{
	this->address = address;
}

void UserInfo::setUserPhone(string phone)
{
	this->phone = phone;
}

void UserInfo::setUserLogin(string login)
{
	account.login = login;
}

void UserInfo::setUserPassword(string password)
{
	account.password = password;
}

Account UserInfo::getUserAccount() const
{
	return account;
}

string UserInfo::getName()
{
	return name;
}

string UserInfo::getAddress()
{
	return address;
}

string UserInfo::getPhone()
{
	return phone;
}

void UserInfo::showUser()const
{
	cout << "User name: " << name << endl;
	cout << "User address: " << address << endl;
	cout << "User phone: " << phone << endl;
	cout << "User login: " << account.login << endl;
	cout << "User password: " << account.password << endl << endl;
}

ostream& operator<<(ostream& os, const UserInfo& obj)
{
	os << obj.name << "\n" << obj.address << "\n" << obj.phone << "\n" << obj.account;
	return os;
}

istream& operator>>(istream& is, UserInfo& obj)
{
	getline(is, obj.name, '\n');
	getline(is, obj.address, '\n');
	getline(is, obj.phone, '\n');
	is >> obj.account;
	return is;
}