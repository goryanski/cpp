#include <iostream>
#include "PriorityQueue.h"

using std::cout;
using std::endl;


int main() {

	PriorityQueue queue(10);

	for (int i = 0; i < 10; i++)
	{
		int value = rand() % 101;
		int priority = 1 + rand() % 5;
		queue.add(value, priority);
		queue.showWithPriority(value, priority);
	}

	cout << "\n\n Max priority element is " << queue.peek() << "\n\n";

	cout << endl << endl;

	// если хотим удалить любой другой элемент 
	//queue.delAnyElement(2);

	queue.showExtracted();

	return 0;
}