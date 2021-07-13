#include "TestPassing.h"

TestPassing::TestPassing()
{
	utils = Utils::getInstance();
}

TestPassing::TestPassing(Account user)
	: TestPassing() {
	this->user = user;
}

void TestPassing::runTest()
{
	// ��������� ������������� ���� � ������ ������� � ������ test	
	TestsManagement testsManagement;
	string directoryName = testsManagement.selectCategory();
	string testName = testsManagement.selectTest(directoryName);
	vector<Question> test = testsManagement.readTest(directoryName, testName);

	string userName = user.getLogin();
	// ��� ���������� ����� ���������� � ������ ������ �������� ������� �����
	int startQuestions = 0;
	// � ��� ���������� ����� ���������� ���-�� ���������� ������� �������������� ����� 
	// ����� (���� �� ����)
	int �ountExistsRightAnswers = 0;
	// ���-�� ������� �������������� ����� �����
	int countExistsAnswers = 0;
	vector<TestResult> newResults;
	bool isTestExistFinished = true;
	
	// ���� ����� ��� ��������� - ���� ���������� - �������� ��
	if (isResults()) {
		vector<TestResult> allResults = loadResults();

		// ��������, �������� �� ���� ������������ ��� ���� ����
		auto it = find_if(allResults.begin(), allResults.end(), [userName, testName](const TestResult& result) {
			return result.getUserName() == userName && result.getTestName() == testName;
		});

		if (it != allResults.end()) {
			countExistsAnswers = (*it).getCountAnswers();

			// ���� ���� ������������ ��� �������� � �� �������� ���� - ������ ���-�� ���������� 
			// ������� � ������� ���� (���� ���� ��� �������� - ������ ������� ���)
			if (countExistsAnswers < test.size()) {
				�ountExistsRightAnswers = (*it).getCountRightAnswers();
				// ���� ���� �� ��� ��������, �� ������ ��� ��������� � �����, ��� ������������
				startQuestions = countExistsAnswers;
				isTestExistFinished = false;
				system("cls");
				cout << "The test will continue where it finished" << endl;
				system("pause");
			}
			else {
				// ���� ���� ��� ��������, �� ��� ������ � ������� �����, ��� �� ����� ��������� ��� ������
				countExistsAnswers = 0;
			}
			// ������ ��������� � ������� � �������� ���� ������ ������� ������� ��� �� ��������� 
			// ��������� ��������� �������� 
			allResults.erase(it);
			newResults = allResults;
		}	
		else {
			// � ����� ���� ������������, ������ ��� ������ ����� ������������ ������ newResults
			newResults = allResults;
		}
		// � ���� ���� ������������ ��� �� �������� ���� ���� ����� - ������ �� ������
	}

	// ������ �������� ���� � �������� � ������ ������ ��������
	vector<int> studentAnswers = getAnswers(startQuestions, test);
	
	int mark = 0;
	// ��� ������ ���� ���� ��� ��� ������� � �� �������� - ����� �������� ���������� ���������� ������
	int countRightAnswers = �ountExistsRightAnswers;
	
	// ������� � ������ ���������� ������ �� ����� � ��������
	string answersPath = utils->ANSWERS_DIRECTORY_PATH + "\\" + directoryName + "\\" + testName;
	Answers answersStorage;
	vector<int> rightAnswers = answersStorage.readFromFile(answersPath);

	// ���� ������� ��� �������� ���� ���� � �� ��� �� ��������, �� � ������� ���������� �������
	// ������� ������ ������, ������� ������� ��� ��� �����. ��� �� ���������� ������ ������ 
	// ���������� ����������� �����
	if (!isTestExistFinished) {
		rightAnswers.erase(rightAnswers.begin(), rightAnswers.begin() + countExistsAnswers);
	}

	int countStudentAnswers = studentAnswers.size();

	// ���� ������� ���� ��������
	if (studentAnswers.size() == test.size()) {
		// ������� ������ �������� � ����������� �������� ����� 
		for (int i = 0; i < test.size(); i++) {
			if (studentAnswers[i] == rightAnswers[i]) {
				countRightAnswers++;
			}
		}
		// � ��������� �������� - ����� ����� ��������� ������. ���� ������� = 0 �� ���� �� ��������
		mark = calcMark(countRightAnswers, test.size());
	}
	else {
		// ���� ������� ���� �� ��������
		for (int i = 0; i < studentAnswers.size(); i++) {
			// ������� ������ ������ ����� ������� �������� � ����������� �������� ����� 
			if (studentAnswers[i] == rightAnswers[i]) {
				countRightAnswers++;
			}
		}
		// ���� ��� ��������� ����������� ����� ������� ��� �� �������� ���, �� ����� ��������� ������
		if (studentAnswers.size() + countExistsAnswers == test.size()) {
			mark = calcMark(countRightAnswers, test.size());
		}
		// � � ����� ������ �������� ���-�� ������� ��������
		countStudentAnswers += countExistsAnswers;
	}	
	TestResult result(userName, directoryName, testName, countStudentAnswers,
		countRightAnswers, mark);

	newResults.push_back(result);
	saveResults(newResults);

	showTestResult(test.size(), countRightAnswers, mark);
	system("pause");
}

vector<int> TestPassing::getAnswers(int startQuestions, vector<Question> test)
{
	vector<int> studentAnswers;
	int answer;
	int counter = 1;
	for (int i = startQuestions; i < test.size(); i++) {
		system("cls");
		cout << "You can press [0] to exit" << endl << endl;
		cout << counter << ". ";
		counter++;
		test[i].showQuestion();
		cout << "Your answer: ";
		cin >> answer;
		if (answer == 0) {
			break;
		}
		studentAnswers.push_back(answer);
	}
	return studentAnswers;
}

int TestPassing::calcMark(int countRightAnswers, int countQuestions)
{
	int mark = 0;
	double percent = (double(countRightAnswers) * 100) / countQuestions;
	if (percent == 100) {
		mark = 12;
	}
	else if (percent >= 90 && percent < 100) {
		mark = 11;
	}
	else if (percent >= 85 && percent < 90) {
		mark = 10;
	}
	else if (percent >= 75 && percent < 85) {
		mark = 9;
	}
	else if (percent >= 70 && percent < 75) {
		mark = 8;
	}
	else if (percent >= 50 && percent < 70) {
		mark = 7;
	}
	else {
		mark = 1;
	}
	return mark;
}

vector<TestResult> TestPassing::loadResults()
{	
	ifstream is(utils->TEST_RESULTS, ios::out | ios::binary);
	if (is.is_open()) {

		//������� �������
		allResults.clear();

		int size;
		is >> size;
		// ��� �� ����� ��������� ��������� ��������
		is.ignore(32767, '\n');

		for (int i = 0; i < size; i++) {
			TestResult result;
			is >> result;
			is.ignore(32767, '\n');
			allResults.push_back(result);
		}
		is.close();
		return allResults;
	}
	return allResults;
}

void TestPassing::saveResults(vector<TestResult> allResults)
{
	//�������� ����� �� ������
	ofstream os(utils->TEST_RESULTS, ios::in | ios::binary | ios::trunc);
	if (os.is_open()) {
		os << allResults.size() << endl;

		for_each(allResults.begin(), allResults.end(), [&os](const TestResult& result) {
			os << result << endl;
		});

		os.close();
	}
}

bool TestPassing::isResults()
{
	// ���� ���� ��������� - ���� ���������� - ���������� ��� ����, ����� - ����� ��� �� ��������� �� ���
	ifstream is(utils->TEST_RESULTS);
	if (is.is_open()) {
		is.close();
		return true;
	}
	else {
		return false;
	}
}

void TestPassing::showTestResult(int countQuestions, int countRightAnswers, int mark)
{
	system("cls");
	cout << "Resut:" << endl;
	if (mark == 0) {
		cout << "Test isn't finished" << endl;
	}
	cout << "Amount of correct answers: " << countRightAnswers << endl;
	double percent = (double(countRightAnswers) * 100) / countQuestions;
	cout << "Percent of correct answers: " << percent << endl;
	cout << "Mark: " << mark << endl;
}

void TestPassing::showUserResults(string userName)
{
	system("cls");
	vector<TestResult> allResults = loadResults();

	int flag = 0;
	auto it = for_each(allResults.begin(), allResults.end(), [userName, &flag](const TestResult& result) {
		if (result.getUserName() == userName) {
			result.showResult();
			cout << endl;
			flag = 1;
		}
	});
	
	if (flag == 0) {
		cout << "There're no results yet" << endl;
	}
	else {
		TestsManagement testsManagement;
		if (testsManagement.canSaveStatistics()) {
			DirectoryHelper::createDirectory(utils->SAVED_STATISTICS);

			string fileName = utils->SAVED_STATISTICS + "//Statistics by user "
				+ userName + ".txt";
			ofstream os(fileName, ios::in | ios::binary | ios::trunc);
			if (os.is_open()) {

				for_each(allResults.begin(), allResults.end(), [&os, userName](const TestResult& result) {
					if (result.getUserName() == userName) {
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


