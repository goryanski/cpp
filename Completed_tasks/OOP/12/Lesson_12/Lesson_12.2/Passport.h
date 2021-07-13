#pragma once
#include <iostream>
using std::cout;
using std::endl;

#define STR_LEN 30

class Passport
{
protected:
	char firstname[STR_LEN];
	char lastname[STR_LEN];
	char number[STR_LEN];
	char adress[STR_LEN];
	int age;
public:
	Passport();
	Passport(char* firstname, char* lastname, char* number, char* adress, int age);
	void show();
};

