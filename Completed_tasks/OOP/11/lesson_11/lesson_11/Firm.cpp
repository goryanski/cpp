#include "firm.h"

Firm::Firm()
{
	setFirmName((char*)"");
	setManager((char*)"");
	setPhone((char*)"");
	setAddress((char*)"");
	setDirection((char*)"");
}

Firm::Firm(char* firmName, char* manager, char* phone, char* address, char* direction)
{
	setFirmName(firmName);
	setManager(manager);
	setPhone(phone);
	setAddress(address);
	setDirection(direction);
}

Firm::Firm(const Firm& obj) : Firm(obj.firmName, obj.manager, obj.phone, obj.address, obj.direction)
{
}

Firm::~Firm()
{
	delete[] firmName;
	delete[] manager;
	delete[] phone;
	delete[] address;
	delete[] direction;
}

Firm& Firm::operator=(const Firm& obj)
{
	if (this == &obj) {
		return *this;
	}
	this->setFirmName(obj.firmName);
	this->setManager(obj.manager);
	this->setPhone(obj.phone);
	this->setAddress(obj.address);
	this->setDirection(obj.direction);
	return *this;
}

void Firm::setFirmName(char* firmName)
{
	int length = strlen(firmName) + 1;
	this->firmName = new char[length];
	strcpy_s(this->firmName, length, firmName);
}

void Firm::setManager(char* manager)
{
	int length = strlen(manager) + 1;
	this->manager = new char[length];
	strcpy_s(this->manager, length, manager);
}

void Firm::setPhone(char* phone)
{
	int length = strlen(phone) + 1;
	this->phone = new char[length];
	strcpy_s(this->phone, length, phone);
}

void Firm::setAddress(char* address)
{
	int length = strlen(address) + 1;
	this->address = new char[length];
	strcpy_s(this->address, length, address);
}

void Firm::setDirection(char* direction)
{
	int length = strlen(direction) + 1;
	this->direction = new char[length];
	strcpy_s(this->direction, length, direction);
}

ostream& operator<<(ostream& os, const Firm& obj)
{
	os << obj.firmName << " " << obj.manager << " " << obj.phone << " " << obj.address << " " << obj.direction;
	return os;
}

istream& operator>>(istream& is, const Firm& obj)
{
	// убирает символ из потока (\n)
	//is.get();
	// что бы считывать до пробела
	is.getline(obj.firmName, 25, ' ');
	is.getline(obj.manager, 30, ' ');
	is.getline(obj.phone, 15, ' ');
	is.getline(obj.address, 40, ' ');
	is.getline(obj.direction, 20, '\n');
	return is;
}
