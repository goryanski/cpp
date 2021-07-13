#include "Stack.h"

Stack::Stack(int capacity)
{
	top = EMPTY;
	this->capacity = capacity;
	arr = new int[capacity];
}

Stack::~Stack()
{
	delete[] arr;
}

void Stack::addToTail(int value)
{
	if (isFull()) {
		resize(5);
	}
	arr[++top] = value;
}

int Stack::removeTail()
{
	if (!isEmpty()) {
		return arr[top--];
	}
	return EMPTY;
}

void Stack::showList()
{
	if (!isEmpty()) {
		int i = 0;
		cout << "Elements of stack:\n";
		while (i != top + 1) {
			cout << i + 1 << ". " << arr[i] << "\n";
			i++;
		}
		cout << "\n";
	}
	else {
		cout << "Stack is empty\n";
	}
}

void Stack::clear()
{
	top = EMPTY;
}

bool Stack::isEmpty()
{
	return top == EMPTY;
}

bool Stack::isFull()
{
	return top + 1 == capacity;
}

void Stack::resize(int length)
{
	int* tmp = new int[capacity + length];
	// top начинается с нуля, по этому +1
	copy(arr, arr + top + 1, tmp);
	delete[] arr;
	arr = tmp;
	capacity += length;
}

void Stack::showExtracted()
{
	// что бы для вывода на экран не менять top
	int tmp = top;
	while (!isEmpty()) {
		cout << removeTail() << "\n";
	}
	top = tmp;
}

int Stack::getElement(int ind)
{
	return arr[ind - 1];
}

int Stack::getTop()
{
	return top;
}
