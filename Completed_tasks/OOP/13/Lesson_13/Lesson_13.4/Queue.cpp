#include "Queue.h"

Queue::Queue(int capacity)
{
	this->capacity = capacity;
	count = 0;
	queue = new int[capacity];
}

Queue::~Queue()
{
	delete[] queue;
}

void Queue::addToTail(int value)
{
	if (isFull()) {
		resize(5);
	}
	queue[count++] = value;
}

int Queue::removeTail()
{
	if (!isEmpty()) {
		int first = queue[0];
		for (int i = 1; i < count; i++)
		{
			queue[i - 1] = queue[i];
		}
		queue[count - 1] = first;
		return first;
	}
	return 0;
}

void Queue::showList()
{
	if (!isEmpty()) {
		cout << "Elements of queue:\n";
		for (int i = 0; i < count; i++) {
			cout << queue[i] << "\n";
		}		
	}
	else {
		cout << "Queue is empty\n";
	}
}

void Queue::clear()
{
	count = 0;
}

bool Queue::isEmpty()
{
	return count == 0;
}

bool Queue::isFull()
{
	return count == capacity;
}

void Queue::resize(int length)
{
	int* tmp = new int[capacity + length];
	copy(queue, queue + count, tmp);
	delete[] queue;
	queue = tmp;
	capacity += length;
}