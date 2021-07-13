#pragma once
class Person {
	char* fio;
	int age;
	int size;
public:
	Person();
	Person(int age, char* fio);
	Person(const Person& tmp);
	~Person();
	void setfio(char* fio);
	void setAge(int age);
	void enter();
	void print();
	Person& operator = (const Person& obj);
};