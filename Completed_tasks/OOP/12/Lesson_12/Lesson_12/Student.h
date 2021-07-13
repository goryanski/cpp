#pragma once
#include <iostream>
using std::cout;
using std::endl;

#define STR_LEN 30

class Student {
protected:
	char firstname[STR_LEN];
	char lastname[STR_LEN];
	int age;
	int course;
public:
	Student();
	Student(char* firstname, char* lastname, int age, int course);
	~Student();
	void show();
};

