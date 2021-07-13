#pragma once
#include <iostream>
#include <iomanip>
using std::ostream;
using std::cout;
using std::setw;
using std::left;

class Bus {
	char* number;
	char* fio;
	int route;
	int countSeats;
public:
	Bus();
	Bus(char* number, char* fio, int route, int countSeats);
	Bus(const Bus& obj);

	void setNum(char* number);
	void setFio(char* fio);
	void setRoute(int route);
	void setCountSeats(int countSeats);

	char* getNum() const;
	Bus& operator=(const Bus& obj);
	void showBus();

	friend ostream& operator << (ostream& os, const Bus& obj);
};