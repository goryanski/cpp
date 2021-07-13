#pragma once
class MyArray {
	int* arr;
	int capacity;
	int size;
public:
	MyArray();
	MyArray(int capacity);
	MyArray(const MyArray& obj);
	~MyArray();
	void print();
	void resize(int count);
	void delEnd();
	int getCapacity();
	int getSize();
	int& operator[](int index);
	MyArray& operator ++();
	MyArray& operator -- ();
	MyArray operator + (const MyArray& obj);
	MyArray operator - (const MyArray& obj);
	MyArray& operator = (const MyArray& obj);
};