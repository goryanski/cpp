#include "Array.h"
#include<iostream>
using std::cout;
using std::cin;
Array::Array()
{
	size = 0;
	arr = nullptr;
}

Array::Array(int size)
{
	arr = new int[size];
	this->size = size;
}

Array::Array(const Array& obj)
{
	setArray(obj.arr, obj.size);
}

Array::~Array()
{
	delete[] arr;
}

void Array::setArray(int* arr, int size)
{
	if (this->arr != nullptr) {
		delete[] this->arr;
	}
	this->size = size;
	this->arr = new int[this->size];
	for (int i = 0; i < this->size; i++) {
		this->arr[i] = arr[i];
	}
}

void Array::fillArr()
{
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10;
	}
}

void Array::printArr()
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
	cout << "\n";
}

void Array::addEnd(int value)
{
	int* tmp = new int[size + 1];
	for (int i = 0; i < size; i++) {
		tmp[i] = arr[i];
	}
	tmp[size] = value;
	size++;
	delete[] arr;
	arr = tmp;
}

void Array::delEnd()
{
	size--;
	int* tmp = new int[size];
	for (int i = 0; i < size; i++) {
		tmp[i] = arr[i];
	}
	delete[] arr;
	arr = tmp;
}

void Array::sortArr()
{
	for (int i = 0; i < size - 1; i++) {
		bool f = 0;
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				f = 1;
			}
		}
		if (f == 0)
			break;
	}
}

void Array::min_max()
{
	int max = arr[0], min = arr[0];
	int imax = 0, imin = 0;
	for (int i = 1; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
			imax = i;
		}
		if (arr[i] < min) {
			min = arr[i];
			imin = i;
		}
	}
	cout << " Min element of array is " << min << " (it's position " << imin + 1 << ")\n";
	cout << " Max element of array is " << max << " (it's position " << imax + 1 << ")\n";
}