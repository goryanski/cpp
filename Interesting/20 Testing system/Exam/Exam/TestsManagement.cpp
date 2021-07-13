#include "TestsManagement.h"

TestsManagement::TestsManagement()
{
	utils = Utils::getInstance();
	usersStorage = UsersStorage::getInstance();
}

void TestsManagement::addNewCategory()
{
	system("cls");
	cout << "Enter name of new categoty: ";
	string nameCategory;
	// ����� ����� getline, ������ ��� ������ ������� �����
	cin.ignore(32767, '\n');
	getline(cin, nameCategory);

	// �������� ��� ���������� ����� � ��������� ��������� � ������ � ����� �� � �������
	// ��� �� � � ������ � ������� ���� ���������� ��������� ����� ��� �������� 
	string newTestCategory = utils->TESTS_DIRECTORY_PATH + "\\" + nameCategory;
	_mkdir(newTestCategory.c_str());

	string newAnswersCategory = utils->ANSWERS_DIRECTORY_PATH + "\\" + nameCategory;
	_mkdir(newAnswersCategory.c_str());

	cout << "Added." << endl;
}

void TestsManagement::addNewTest(string selPath)
{
	system("cls");
	// ��������� ����� ���� � ����� � ��������� ��������
	cout << "Enter test name: ";
	string testName;
	getline(cin, testName);

	// ������� ������� � �����, �������� ������� � ����� �� ������, ������� ������ �� �-���
	Answers testAnswers = fillTest();

	// ������� ���� � ����� ����� � ������� ���� ���� � ����
	string testPath = utils->TESTS_DIRECTORY_PATH + "\\" + selPath + "\\" + testName + ".txt";
	
	writeTestToFile(testPath);

	// � ������� ���� � ������� �� ���� ����, ������� ������� ��� �� � ����, �� � ����� � ��������
	string answersPath = utils->ANSWERS_DIRECTORY_PATH + "\\" + selPath + "\\" + testName + ".txt";
	testAnswers.writeToFile(answersPath);

	cout << "Added." << endl;
}

string TestsManagement::selectCategory()
{
	system("cls");
	// �������� ��� ���������, ��� �� ����� ���� ������� � ����� ��������� �����
	if (DirectoryHelper::showFolderContents(utils->TESTS_DIRECTORY_PATH)) {
		cout << "Select a category: ";
		int selection;
		cin >> selection;

		// ����� �������� ���������������, ��� �� ������������ ��������� ���� ����� ���������� 
		while (selection < 1 || selection > DirectoryHelper::readDirectory(utils->TESTS_DIRECTORY_PATH).size()) {
			cout << "Wrong number. Select a category: ";
			cin >> selection;
		}
		cin.ignore(32767, '\n'); 		

		// ������� ���� � �����, ������� ������ ������������
		string selPath = DirectoryHelper::readDirectory(utils->TESTS_DIRECTORY_PATH)[selection - 1];
		return selPath;
	}
	else {
		string empty = "";
		return empty;
	}
}

string TestsManagement::selectTest(string directoryName)
{
	cout << endl;
	string categoryPath = utils->TESTS_DIRECTORY_PATH + "\\" + directoryName;
	if (DirectoryHelper::showFolderContents(categoryPath)) {
		cout << "Select a test: ";
		int selection;
		cin >> selection;

		// ����� �������� ���������������, ��� �� ������������ ��������� ���� ����� ����� 
		while (selection < 1 || selection > DirectoryHelper::readDirectory(categoryPath).size()) {
			cout << "Wrong number. Select a test: ";
			cin >> selection;
		}

		string testName = DirectoryHelper::readDirectory(categoryPath)[selection - 1];
		return testName;
	}
	else {
		string empty = "";
		return empty;
	}
}

vector<Question> TestsManagement::readTest(string directoryName, string testName)
{
	string testPath = utils->TESTS_DIRECTORY_PATH + "\\" + directoryName + "\\" + testName;

	ifstream is(testPath, ios::out | ios::binary);
	if (is.is_open()) {

		int countQuestions;
		is >> countQuestions;

		vector<Question> test;

		for (int i = 0; i < countQuestions; i++) {
			
			// ��������� �� �� ����� ������� ���-�� ��������� ������, �� �����������
			// ��������������� �� ���������
			int countOptions;
			is >> countOptions;
			is.ignore(32767, '\n');

			string question;
			getline(is, question, '\n');
			
			vector<string> answerOptions(countOptions);
			for (int i = 0; i < countOptions; i++) {
				getline(is, answerOptions[i], '\n');
			}

			Question fullQuestion(question, answerOptions);

			test.push_back(fullQuestion);
		}
		is.close();
		return test;
	}

}

Answers TestsManagement::fillTest()
{
	cout << "Enter amount of test questions: ";
	int countQuestions;
	cin >> countQuestions;

	cin.ignore(32767, '\n');

	Answers testAnswers;
	for (int i = 0; i < countQuestions; i++) {
		string question = inputQuestion();
		vector<string> answerOptions = inputVariants();
		int rightAnswer = inputRightAnswer();

		cin.ignore(32767, '\n');
		cout << endl;

		Question fullQuestion(question, answerOptions);
		test.push_back(fullQuestion);

		testAnswers.answers.push_back(rightAnswer);
	}
	return testAnswers;
}

string TestsManagement::inputQuestion()
{
	cout << "Enter question: ";
	string question;
	getline(cin, question);
	return question;
}

vector<string> TestsManagement::inputVariants()
{
	cout << "Enter amount of answer options for this question: ";
	int countOptions;
	cin >> countOptions;
	cin.ignore(32767, '\n');

	vector<string> answerOptions;
	for (int i = 0; i < countOptions; i++) {
		cout << "Enter variant of answer: ";
		string variant;
		getline(cin, variant);
		answerOptions.push_back(variant);
	}
	return answerOptions;
}

int TestsManagement::inputRightAnswer()
{
	cout << "Enter number of right variant: ";
	int rightAnswer;
	cin >> rightAnswer;
	return rightAnswer;
}

void TestsManagement::deleteTest()
{
	string categoryName = selectCategory();
	string testName = selectTest(categoryName);
	string testPath = utils->TESTS_DIRECTORY_PATH + "//" + categoryName + "//" + testName;
	remove(testPath.c_str());
	if (testName != "") {
		cout << "Success." << endl;
	}
}

void TestsManagement::deleteCategory()
{
	string categoryName = selectCategory();
	if (categoryName != "") {
		string categoryPath = utils->TESTS_DIRECTORY_PATH + "//" + categoryName;
		char* pathDel = const_cast<char*>(categoryPath.c_str());

		// ������� ������ ��� ���������� �����
		DirectoryHelper::removeDirectory(pathDel, true);
		// � ����� � ���� �����
		_rmdir(pathDel);

		cout << "Success." << endl;
	}
}

void TestsManagement::writeTestToFile(string path)
{
	ofstream os(path, ios::in | ios::binary | ios::trunc);
	if (os.is_open()) {
		os << test.size() << endl;

		for_each(test.begin(), test.end(), [&os](const Question& question) {
			os << question.getAnswerOptions().size() << endl;
			os << question;
		});

		os.close();
	}
}

void TestsManagement::statisticsByCategory()
{
	system("cls");
	TestPassing userPanel;
	vector<TestResult> allResults = userPanel.loadResults();

	string categoryName = selectCategory();

	int flag = 0;
	system("cls");
	auto it = for_each(allResults.begin(), allResults.end(), [categoryName, &flag](const TestResult& result) {
		if (result.getCategoryName() == categoryName) {
			result.showResult();
			cout << endl;
			flag = 1;
		}
	});

	int a = 0;

	if (flag == 0) {
		cout << "There're no results by this category" << endl;
	}
	// ����� ��������� ��������� ���������� � ����
	else {
		if (canSaveStatistics()) {

			// ���� ����� � ����������� ����������� ��� ��� - �������� ��
			DirectoryHelper::createDirectory(utils->SAVED_STATISTICS);

			// ������� ���, ��� �� � ����� ��������� ������ ���������� ���������� �� ����������,
			// �� ����� ���������� ����� �������
			string fileName = utils->SAVED_STATISTICS + "//Statistics by category "
				+ categoryName + ".txt";
			ofstream os(fileName, ios::in | ios::binary | ios::trunc);
			if (os.is_open()) {

				for_each(allResults.begin(), allResults.end(), [&os, categoryName](const TestResult& result) {
					if (result.getCategoryName() == categoryName) {
						os << result << "(Amount of answers, Amount of correct answers, Mark)"
							<< endl;
						if (result.getMark() == 0) {
							os << "(test isn't finished)" << endl;
							}
						os << endl;
					}
				});

				os.close();
			}
			cout << "Success." << endl;
		}
	}
	system("pause");
}

void TestsManagement::statisticsByTest()
{
	system("cls");
	TestPassing userPanel;
	vector<TestResult> allResults = userPanel.loadResults();

	string testName = selectTest(selectCategory());

	int flag = 0;
	system("cls");
	auto it = for_each(allResults.begin(), allResults.end(), [testName, &flag](const TestResult& result) {
		if (result.getTestName() == testName) {
			result.showResult();
			cout << endl;
			flag = 1;
		}
		});

	if (flag == 0) {
		cout << "There're no results by this test" << endl;
	}
	else {
		if (canSaveStatistics()) {
			DirectoryHelper::createDirectory(utils->SAVED_STATISTICS);

			string fileName = utils->SAVED_STATISTICS + "//Statistics by test " + testName;
			ofstream os(fileName, ios::in | ios::binary | ios::trunc);
			if (os.is_open()) {

				for_each(allResults.begin(), allResults.end(), [&os, testName](const TestResult& result) {
					if (result.getTestName() == testName) {
						os << result << "(Amount of answers, Amount of correct answers, Mark)"
							<< endl;
						if (result.getMark() == 0) {
							os << "(test isn't finished)" << endl;
						}
						os << endl;
					}
					});

				os.close();
			}
			cout << "Success." << endl;
		}
	}
	system("pause");
}

void TestsManagement::statisticsByUser()
{
	system("cls");
	cout << "List of users:" << endl;
	usersStorage->showUsers();

	cout << endl << "Enter user login: ";
	string userName;
	cin >> userName;
	
	// �������� ���� �� ����� ������������ �����
	try {
		usersStorage->findUser(userName);

		TestPassing userPanel;
		userPanel.showUserResults(userName);
	}
	catch (UserNotFoundException& ex) {
		cout << ex.what() << endl;
		system("pause");
	}
}

bool TestsManagement::canSaveStatistics()
{
	cout << "Do you want to save statistics?" << endl;
	cout << "[1] - yes" << endl;
	cout << "[0] - no" << endl;
	int select;
	cin >> select;
	while (select < 0 || select > 1) {
		cout << "Wrong number, try again: ";
		cin >> select;
	}
	return select;
}
