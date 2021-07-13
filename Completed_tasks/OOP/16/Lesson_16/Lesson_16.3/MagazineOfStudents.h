#pragma once
#include <iostream>
#include "Student.h"
#include <vector>
using std::vector;
using std::cout;
using std::cin;

enum Action {
	ADD = 1,
	PRINT,
	SORT_BY_FIRSTNAME,
	SORT_BY_SECONDNAME,
	SORT_BY_COURSE,
	EXIT
};

class MagazineOfStudents
{
	vector<Student> students;
	void add();
	void print();
	void sortByFirstname();
	void sortBySecondname();	
	// Поставить в первые три элемента вектора студентов самых младших курсов по возрастанию
	void sortByCourse();
	void menu();
public:
	void start();
};

