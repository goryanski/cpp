#pragma once
#include <iostream>
#include "Utils.h"
#include "DirectoryHelper.h"
#include <algorithm>
#include "TestPassing.h"
#include "UsersStorage.h"
#include "Question.h"
#include "Answers.h"
using std::cin;
using std::getline;

class TestsManagement
{
	Utils* utils;
	UsersStorage* usersStorage;
	vector<Question> test;
public:
	TestsManagement();

	void addNewCategory();
	void addNewTest(string);

	string selectCategory();
	string selectTest(string);

	Answers fillTest();
	string inputQuestion();
	vector<string> inputVariants();
	int inputRightAnswer();
	void deleteTest();
	void deleteCategory();

	vector<Question> readTest(string, string);	
	void writeTestToFile(string);

	void statisticsByCategory();
	void statisticsByTest();
	void statisticsByUser();	
	bool canSaveStatistics();	
};

