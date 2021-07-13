#include <iostream>
#include "List.h"
using std::cout;


int main() {
	List list1;
	list1.addToTail(10);
	list1.addToTail(20);
	list1.addToTail(30);

	//list1.addToHead(100);
	//list1.insert(77, 3);
	//list1.removeHead();
	//list1.removeTail();
	//list1.removePos(2);
	//list1.removeAll();

	List list2;
	list2.addToTail(30);
	list2.addToTail(77);
	list2.addToTail(99);

	cout << "List1: ";
	list1.showList();
	cout << "List2: ";
	list2.showList();

	cout << "list1 + list2: ";
	List list3;
	list3 = list1 + list2;
	list3.showList();

	cout << "list1 - list2: ";
	list3 = list1 - list2;
	list3.showList();
	return 0;
}
