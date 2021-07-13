#pragma once
#include <iostream>
using std::ostream;
using std::istream;

class Catalog;

class Firm
{
	char* firmName;
	char* manager;
	char* phone;
	char* address;
	char* direction; // направление в бизнесе
public:
	Firm();
	Firm(char* firmName, char* manager, char* phone, char* address, char* direction);
	Firm(const Firm& obj);
	~Firm();
	Firm& operator =(const Firm& obj);
	
	void setFirmName(char* firmName);
	void setManager(char* manager);
	void setPhone(char* phone);
	void setAddress(char* address);
	void setDirection(char* direction);

	friend ostream& operator << (ostream& os, const Firm& obj);
	friend istream& operator >>(istream& is, const Firm& obj);

	friend Catalog;
};

