#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::ostream;
using std::istream;
using std::getline;
using std::endl;
using std::for_each;
using std::cout;

class TestResult
{
	string userName;
	string categoryName;
	string testName;
	int countAnswers;
	int countRightAnswers;
	int mark;
public:
	TestResult();
	TestResult(string, string, string, int, int, int);

	string getUserName()const;
	string getCategoryName()const;
	string getTestName()const;
	int getCountAnswers()const;
	int getCountRightAnswers()const;
	int getMark()const;

	void showResult()const;

	friend ostream& operator << (ostream&, const TestResult&);
	friend istream& operator >> (istream&, TestResult&);
};

