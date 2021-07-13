#pragma once
#include <iostream>
#include "Account.h"
using std::cout;
using std::endl;

class UserInfo
{
	string name;
	string address;
	string phone;
	Account account;
public:
	UserInfo();

	UserInfo(string, string, string);

	void setUserAccount(Account);
	void setUserName(string);
	void setUserAddress(string);
	void setUserPhone(string phone);
	void setUserLogin(string login);
	void setUserPassword(string password);

	Account getUserAccount() const;
	string getName();
	string getAddress();
	string getPhone();

	void showUser()const;

	friend ostream& operator << (ostream&, const UserInfo&);
	friend istream& operator >> (istream&, UserInfo&);
};

