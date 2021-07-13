#include "Queue.h"

Queue::Queue(int capacity)
{
	this->capacity = capacity;
	count = 0;
	queue = new char[capacity];
}

Queue::~Queue()
{
	delete[] queue;
}

void Queue::add(char value)
{
	if (isFull()) {
		resize(5);
	}
	queue[count++] = value;
}

char Queue::extract()
{
	if (!isEmpty()) {
		//запомнить первый элемент
		char first = queue[0];
		//сдвиг всех эл-ов влево на 1 €чейку влево
		for (int i = 1; i < count; i++)
		{
			queue[i - 1] = queue[i];
		}
		queue[count - 1] = first;
		return first;
	}
	return 0;
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
	char* tmp = new char[capacity + length];
	copy(queue, queue + count, tmp);
	delete[] queue;
	queue = tmp;
	capacity += length;
}