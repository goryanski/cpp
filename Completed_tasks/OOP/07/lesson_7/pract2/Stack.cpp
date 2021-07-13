#include "Stack.h"

Stack::Stack(int capacity)
{
	top = EMPTY;
	this->capacity = capacity;
	arr = new String[capacity];
}

Stack::~Stack()
{
	delete[] arr;
}

void Stack::push(char* newStr)
{
	String str(newStr);
	if (isFull()) {
		resize(5);
	}
	// ++top потому что top изначально -1 
	arr[++top] = str;
}

String Stack::pop()
{
	if (!isEmpty()) {
		// то возвращаем эл-т с вершины стека. top-- это будет индекс массива - обращаемся - уменьшили 
		return arr[top--];

	}
	return nullptr;
}

void Stack::clear()
{
	// только сбрасываем на -1 вершину стека (что бы не перераспределять память, а прост перезаписывать существующие эл-ты)
	top = EMPTY;
}

bool Stack::isEmpty()
{
	return top == EMPTY;
}

bool Stack::isFull()
{
	// top + 1 это будет фактическое кол-во эл-тов в массиве
	return top + 1 == capacity;
}

void Stack::resize(int length)
{
	String* tmp = new String[capacity + length];
	// top начинается с нуля, по этому +1
	copy(arr, arr + top + 1, tmp);
	delete[] arr;
	arr = tmp;
	capacity += length;
}

void Stack::showStack()
{
	int i = 0;
	while (i != top + 1) {
		cout << i + 1 << ". " << arr[i].str << "\n";
		i++;
	}
	cout << "\n";
}

void Stack::showExtracted()
{
	// что бы для вывода на экран не менять top
	int tmp = top;
	while (!isEmpty()) {
		cout << pop().str << "\n";
	}
	top = tmp;
}

String Stack::getElement(int ind)
{
	return arr[ind-1];
}

int Stack::getTop()
{
	return top;
}
