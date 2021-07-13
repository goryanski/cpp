#pragma once
class Array {
	int* arr;
	int size;
public:
	Array();
	Array(int size);
	Array(const Array& obj);
	~Array();
	void setArray(int* arr, int size);
	void fillArr();
	void printArr();
	void addEnd(int value);
	void delEnd();
	void sortArr();
	void min_max();
};