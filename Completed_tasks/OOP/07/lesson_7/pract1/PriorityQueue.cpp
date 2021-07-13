#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int capacity)
{
	this->capacity = capacity;
	count = 0;
	queue = new int[capacity];
	priorities = new int[capacity];
}

PriorityQueue::~PriorityQueue()
{
	delete[] queue;
	delete[] priorities;
}

void PriorityQueue::add(int value, int priority)
{
	if (isFull()) {
		resize(5);
	}
	queue[count] = value;
	priorities[count] = priority;
	count++;
}

int PriorityQueue::extract()
{
	if (!isEmpty()) {
		int maxPriority = priorities[0];
		int maxPriorityIdx = 0;

		for (int i = 1; i < count; i++) {
			if (maxPriority < priorities[i]) {
				maxPriority = priorities[i];
				maxPriorityIdx = i;
			}
		}

		int valueWithMaxPriority = queue[maxPriorityIdx];


		for (int i = maxPriorityIdx; i < count - 1; i++)
		{
			queue[i] = queue[i + 1];
			priorities[i] = priorities[i + 1];
		}

		count--;
		return valueWithMaxPriority;
	}
	return 0;
}

void PriorityQueue::clear()
{
	count = 0;
}

bool PriorityQueue::isEmpty()
{
	return count == 0;
}

bool PriorityQueue::isFull()
{
	return count == capacity;
}

void PriorityQueue::resize(int length)
{
	int* tmp = new int[capacity + length];
	copy(queue, queue + count, tmp);
	delete[] queue;
	queue = tmp;

	int* tmp2 = new int[capacity + length];
	copy(priorities, priorities + count, tmp2);
	delete[] priorities;
	priorities = tmp2;

	capacity += length;
}

int PriorityQueue::peek()
{
	if (!isEmpty()) {
		int maxPriority = priorities[0];
		int maxPriorityIdx = 0;

		for (int i = 1; i < count; i++) {
			if (maxPriority < priorities[i]) {
				maxPriority = priorities[i];
				maxPriorityIdx = i;
			}
		}
		return queue[maxPriorityIdx];
	}
	cout << "Queue is empty.\n";
	return 0;
}


void PriorityQueue::showWithPriority(int value, int priority)
{
	cout << value << " - (" << priority << ")" << "\n";
}

void PriorityQueue::showExtracted()
{
	while (!isEmpty()) {
		cout << extract() << "\n";
	}
}

void PriorityQueue::delAnyElement(int ind)
{
	int newSize = count - 1;
	for (int i = ind; i < newSize; i++) {
		queue[i] = queue[i + 1];
	}	
	int* tmp = new int[newSize];
	copy(queue, queue + newSize, tmp);
	delete[] queue;
	queue = tmp;


	for (int i = ind; i < newSize; i++) {
		priorities[i] = priorities[i + 1];
	}
	int* tmp2 = new int [newSize];
	copy(priorities, priorities + newSize, tmp2);
	delete[] priorities;
	priorities = tmp2;
	count = newSize;
}