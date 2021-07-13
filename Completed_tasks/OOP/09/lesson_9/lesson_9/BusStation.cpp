#include "BusStation.h"

BusStation::BusStation()
{
	storage = Tree::getInstance();
}

void BusStation::menu()
{
	system("cls");
	cout << " <<MENU>>\n"
		" [1] Add bus\n"
		" [2] Find by number\n"
		" [3] Remove bus\n"
		" [4] Show list on the screen\n"
		" [5] Write to file\n"
		" [0] Exit\n"
		" Your choose: ";
}

void BusStation::add()
{
	char number[10];
	cout << "\nEnter number: ";
	gets_s(number);
	char fio[30];
	cout << "Enter FIO: ";
	gets_s(fio);
	int route;
	cout << "Enter route: ";
	cin >> route;
	int countSeats;
	cout << "Enter count of seats: ";
	cin >> countSeats;
	cin.ignore();
	Bus bus(number, fio, route, countSeats);
	storage->add(bus);
	cout << "Added.\n";
	Sleep(1000);
}

Leaf* BusStation::findByNumber()
{
	char str[10];
	cout << "Enter number: ";
	gets_s(str);
	Leaf* srch = storage->search(storage->getRoot(), str);

	if (srch != nullptr) {
		cout << "Found item: " << srch->bus.getNum() << "\n";
	}
	else {
		cout << "Item not found\n";
	}
	system("pause");
	return srch;
}

void BusStation::removeBus()
{
	storage->delOneLeaf(findByNumber());	
	Sleep(1000);
}

void BusStation::showList()
{
	cout << "\n" << left << setw(15) << "Number" << setw(30) << "Name of driver" << setw(7)
		<< "Route\tCount seats" << "\n";

	storage->print(storage->getRoot());
	system("pause");
}

void BusStation::writeToFile()
{
	storage->writeBus(storage->getRoot());
	cout << "Written\n";
	Sleep(1000);
}

void BusStation::start()
{
	int choose = 1;
	while (choose != 0) {
		menu();
		cin >> choose;
		cin.ignore();
		switch (choose) {		
		case ADD:
			add();
			break;
		case FIND:			
			findByNumber();
			break;
		case REMOVE:
			removeBus();
			break;
		case SHOW:
			showList();
			break;
		case WRITE:
			writeToFile();
			break;
		case 0:
			exit(0);
			break;
		}
	}
}


