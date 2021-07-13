#pragma once
#include <iostream>
using std::string;
using std::ostream;

class MagazineOfStudents;

class Student
{
	string firstName;
	string secondName;
	int course;
public:
	Student();
	Student(string firstName, string secondName, int course);
	Student(const Student& obj);
	void setStudent(string firstName, string secondName, int course);
	Student operator = (const Student& obj);
	friend ostream& operator <<(ostream& os, const Student& obj);
	friend MagazineOfStudents;
};

