#include "Printer.h"

void Printer::printMe()
{	
	addRequests();
	cout << "\nPrint complete.\n";
	Statistics* storage = Statistics::getInstance();
	storage->fillStatistics();	
	storage->showStatistics();
}

void Printer::addRequests()
{	
	cout << "Add your requests\n";
	char ch = 1;
	while (ch != ESC) {
		cout << "Printer is ready!\n";
		int priority;
		cout << "Choice priority:\n"
			"[1] No matter\n"
			"[2] Later\n"
			"[3] Now\n";
		cin >> priority;
		cin.ignore();

		cout << "Write your name: ";
		char name[20];
		gets_s(name);

		PriorityQueue* queue = PriorityQueue::getInstance();
		queue->add(name, priority);
		cout << "Do you want to add one more request?\n"
			"[ENTER] Yes\n"
			"[ESC] No\n";
		ch = _getch();
		if (ch == ESC) {
			break;
		}
		else {
			system("cls");
		}
	}
}


