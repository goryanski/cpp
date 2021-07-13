#include "TestResult.h"

TestResult::TestResult()
{
	userName = categoryName = testName = "";
	countAnswers = countRightAnswers = mark = 0;
}

TestResult::TestResult(string userName, string categoryName, string testName, int countAnswers, 
	int countRightAnswers, int mark)
	: userName(userName), categoryName(categoryName), testName(testName),  
	countAnswers(countAnswers), countRightAnswers(countRightAnswers), mark(mark)
{
}

string TestResult::getUserName() const
{
	return userName;
}

string TestResult::getCategoryName() const
{
	return categoryName;
}

string TestResult::getTestName() const
{
	return testName;
}

int TestResult::getCountAnswers() const
{
	return countAnswers;
}

int TestResult::getCountRightAnswers() const
{
	return countRightAnswers;
}

int TestResult::getMark() const
{
	return mark;
}

void TestResult::showResult() const
{
	cout << "Student name: " << userName << endl;
	cout << "Name of test category: " << categoryName << endl;
	cout << "Test name: " << testName << endl;
	cout << "Amount of answers: " << countAnswers << endl;
	cout << "Amount of correct answers: " << countRightAnswers << endl;
	cout << "Mark: " << mark;
	if (mark == 0) {
		cout << " (test isn't finished)";
	}
	cout << endl;
}

ostream& operator<<(ostream& os, const TestResult& obj)
{
	os << obj.userName << "\n" << obj.categoryName << "\n" << obj.testName << "\n" << 	
	obj.countAnswers << " " << obj.countRightAnswers << " " << obj.mark << " ";
	return os;
}

istream& operator>>(istream& is, TestResult& obj)
{
	getline(is, obj.userName, '\n');
	getline(is, obj.categoryName, '\n');
	getline(is, obj.testName, '\n');
	is >> obj.countAnswers >> obj.countRightAnswers >> obj.mark;
	return is;
}
