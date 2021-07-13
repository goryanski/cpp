#include <iostream>
#include "List.h"
#include "Stack.h"
#include "Queue.h"
using std::cout;
using std::endl;
using std::cin;

// pdf задача 2
int main() {

	enum Way {
		LIST = 1,
		STACK,
		QUEUE
	};

	List* way = nullptr;

	cout << "What do you want to use?\n";

	int action;
	cout << "[1] List" << endl;
	cout << "[2] Stack" << endl;
	cout << "[3] Queue" << endl;
	cin >> action;

	switch (action) {
	case LIST:
		way = new List();
		break;
	case STACK:
		way = new Stack(3);
		break;
	case QUEUE:
		way = new Queue(3);
		break;
	}

	way->addToTail(10);

	//  для очереди remove будет работать по другом, она циклическая
	//way->removeTail();

	way->showList();




	// try, catch  for list

	//List list1;
	//try {
	//	list1.removeHead();
	//	cout << "Success\n";
	//}
	//catch (const char* error) {
	//	cout << error << endl;
	//}
	//try {
	//	list1.removeTail();
	//	cout << "Success\n";
	//}
	//catch (const char* error) {
	//	cout << error << endl;
	//}
	//try {
	//	list1.removePos(2);
	//	cout << "Success\n";
	//}
	//catch (const char* error) {
	//	cout << error << endl;
	//}
	//try {
	//	list1.insert(22, 1);
	//	cout << "Success\n";
	//}
	//catch (const char* error) {
	//	cout << error << endl;
	//}
	return 0;
}
