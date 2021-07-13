#include "Bus.h"

Bus::Bus()
{
	number = fio = nullptr;
	route = countSeats = 0;
}

Bus::Bus(char* number, char* fio, int route, int countSeats)
{
	setNum(number);
	setFio(fio);
	setRoute(route);
	setCountSeats(countSeats);
}

Bus::Bus(const Bus& obj) : Bus(obj.number, obj.fio, obj.route, obj.countSeats)
{
}

void Bus::setNum(char* number)
{
	int len = strlen(number) + 1;
	this->number = new char[len];
	strcpy_s(this->number, len, number);
}

void Bus::setFio(char* fio)
{
	int len = strlen(fio) + 1;
	this->fio = new char[len];
	strcpy_s(this->fio, len, fio);
}

void Bus::setRoute(int route)
{
	this->route = route;
}

void Bus::setCountSeats(int countSeats)
{
	this->countSeats = countSeats;
}


char* Bus::getNum() const
{
	return number;
}

Bus& Bus::operator=(const Bus& obj)
{
	if (this == &obj) {

		return *this;
	}
	setNum(obj.number);
	setFio(obj.fio);
	setRoute(obj.route);
	setCountSeats(obj.countSeats);
	return *this;
}

void Bus::showBus()
{
	cout << left << setw(15) << number << setw(30) << fio << setw(7) << route << "\t" << countSeats << "\n";
}

ostream& operator<<(ostream& os, const Bus& obj)
{
	os << obj.number << " " << obj.fio << " " << obj.route << " " << obj.countSeats;
	return os;
}
