#include <iostream>
#include <time.h>
#include "function.h"
#include "MyArray.h"
using std::cout;
using std::endl;
using std::copy;
MyArray::MyArray()
{
	arr = nullptr;
	capacity = size = 0;
}

MyArray::MyArray(int capacity)
{
	size = 0;
	this->capacity = capacity;
	arr = (int*)calloc(capacity, sizeof(int));
}

MyArray::MyArray(const MyArray& obj)
{
	capacity = obj.capacity;
	size = obj.size;
	arr = (int*)calloc(capacity, sizeof(int));
	copy(obj.arr, obj.arr + size, arr);
}

MyArray::~MyArray()
{
	free(arr);
}

void MyArray::print()
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void MyArray::resize(int count)
{
	int newSize = capacity + count;
	arr = (int*)realloc(arr, sizeof(int) * newSize);
	capacity = newSize;
}

void MyArray::delEnd()
{
	arr = (int*)realloc(arr, (size - 1) * sizeof(int));
	size--;
}

int& MyArray::operator[](int index)
{
	return arr[index];
}

MyArray& MyArray::operator++()
{
	if (size == capacity) {
		resize(5);
	}
	arr[size++] = rand() % 10;
	return *this;
}
MyArray& MyArray::operator--()
{
	if (size > 0) {
		delEnd();
	}
	else {
		cout << "array too small\n";
	}
	return *this;
}
MyArray MyArray::operator+(const MyArray& obj)
{
	MyArray arrRes;
	// один массив в конец другого
	arrRes.size = obj.size + size;
	arrRes.arr = (int*)calloc(arrRes.size, sizeof(int));
	arrRes.capacity = capacity + obj.capacity;

	int i = 0;
	for (; i < size; i++) {
		arrRes.arr[i] = arr[i];
	}
	for (int j = 0; j < obj.size; j++) {
		arrRes.arr[i] = obj.arr[j];
		i++;
	}
	return arrRes;
}
MyArray MyArray::operator-(const MyArray& obj)
{
	MyArray arrRes;
	// уникальные элементы двух массивов без повторений
	arrRes.arr = unicue(arr, size, obj.arr, obj.size, arrRes.size);
	arrRes.capacity = arrRes.size;
	return arrRes;
}
MyArray& MyArray::operator=(const MyArray& obj)
{
	if (this == &obj) {
		return *this;
	}
	capacity = obj.capacity;
	size = obj.size;
	if (arr != nullptr) {
		free(arr);
	}
	arr = (int*)calloc(capacity, sizeof(int));
	copy(obj.arr, obj.arr + size, arr);
	return *this;
}
int MyArray::getSize()
{
	return size;
}

int MyArray::getCapacity()
{
	return capacity;
}
