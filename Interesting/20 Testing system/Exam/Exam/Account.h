#pragma once
#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::istream;

class UserInfo;

class Account
{
	string login;
	string password;
public:
	Account();
	Account(string, string);

	string getLogin() const;
	string getPassword() const;

	friend ostream& operator << (ostream&, const Account&);
	friend istream& operator >> (istream&, Account&);

	friend UserInfo;
};

