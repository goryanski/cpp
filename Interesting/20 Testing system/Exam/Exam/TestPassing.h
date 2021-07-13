#pragma once
#include "Utils.h"
#include "Account.h"
#include "TestsManagement.h"
#include "TestResult.h"
#include "Question.h"

class TestPassing
{
	Utils* utils;
	Account user;
	vector<TestResult> allResults;
public:
	TestPassing();
	TestPassing(Account);

	void runTest();
	vector<int> getAnswers(int, vector<Question>);
	int calcMark(int, int);
	vector<TestResult> loadResults();
	void saveResults(vector<TestResult>);
	bool isResults();

	void showTestResult(int, int, int);
	void showUserResults(string);
};

