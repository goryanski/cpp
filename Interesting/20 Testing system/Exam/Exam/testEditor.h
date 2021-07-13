#pragma once
#include <iostream>
#include "TestsManagement.h"
#include "Utils.h"

class TestEditor
{
public:
	TestEditor();
	void testEdit();
private:
	Utils* utils;
	TestsManagement testsManagement;
	vector<int> answers;
	vector<Question> test;

	enum {	
		ADD_QUESTION = 1,
		DEL_QUESTION,
		ADD_VARIANT,
		DEL_VARIANT,
		EDIT_QUESTION,
		EDIT_VARIANT,
		EXIT = 0
	};
	void menu();
	void showTest();

	void addOuestion();
	void removeOuestion();

	void addVariant();
	int choiceOuestion();

	void removeVariant();
	void changeRightVariant(int);

	void editOuestion();
	void editVariant();
	string enterVariant();

	// �������� ����� �-��� ��� ������ � ����, ������� ����� ������� ������ � ������ ����� ������,
	// ��� �� �� ������ ������ �������� ����� � ��� ��������������
	void writeEditedTest(string);
	void writeEditedAnswers(string);

	void showEditedTest();
};

