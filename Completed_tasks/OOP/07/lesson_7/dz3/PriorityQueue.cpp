#include "PriorityQueue.h"

PriorityQueue* PriorityQueue::instance = nullptr;

PriorityQueue::PriorityQueue()
{
	capacity = 5;
	count = 0;
	names = new String[capacity];
	priorities = new int[capacity];
}

PriorityQueue* PriorityQueue::getInstance()
{
	if (instance == nullptr) {
		instance = new PriorityQueue();
	}
	return instance;
}

PriorityQueue::~PriorityQueue()
{
	delete[] names;
	delete[] priorities;
}

void PriorityQueue::add(char* newName, int priority)
{
	String str(newName);
	if (isFull()) {
		resize(5);
	}
	names[count] = str;
	priorities[count] = priority;
	count++;
}

String PriorityQueue::extract()
{
	if (!isEmpty()) {
		int maxPriority = priorities[0];
		int maxPriorityIdx = 0;

		//поиск мксимального эл-а и его индекса
		for (int i = 1; i < count; i++) {
			if (maxPriority < priorities[i]) {
				maxPriority = priorities[i];
				maxPriorityIdx = i;
			}
		}

		//извлечение элемента с максимальным приоритетом
		String nameWithMaxPriority = names[maxPriorityIdx];

		//сдвиг элементов влево, которые находятся справа от извлеченного эл-а
		for (int i = maxPriorityIdx; i < count - 1; i++)
		{
			names[i] = names[i + 1];
			priorities[i] = priorities[i + 1];
		}

		count--;
		return nameWithMaxPriority;
	}
	return nullptr;
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
	String* tmp = new String[capacity + length];
	copy(names, names + count, tmp);
	delete[] names;
	names = tmp;

	int* tmp2 = new int[capacity + length];
	copy(priorities, priorities + count, tmp2);
	delete[] priorities;
	priorities = tmp2;

	capacity += length;
}
