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
	// выбранный пользователем файл с тестом считаем в вектор test	
	TestsManagement testsManagement;
	string directoryName = testsManagement.selectCategory();
	string testName = testsManagement.selectTest(directoryName);
	vector<Question> test = testsManagement.readTest(directoryName, testName);

	string userName = user.getLogin();
	// эта переменная будет определять с какого номера начнутся вопросы теста
	int startQuestions = 0;
	// а эта переменная будет определять кол-во правильных ответов незавершенного ранее 
	// теста (если он есть)
	int сountExistsRightAnswers = 0;
	// кол-во ответов незавершенного ранее теста
	int countExistsAnswers = 0;
	vector<TestResult> newResults;
	bool isTestExistFinished = true;
	
	// если тесты уже проходили - есть результаты - загрузим их
	if (isResults()) {
		vector<TestResult> allResults = loadResults();

		// проверим, проходил ли этот пользователь уже этот тест
		auto it = find_if(allResults.begin(), allResults.end(), [userName, testName](const TestResult& result) {
			return result.getUserName() == userName && result.getTestName() == testName;
		});

		if (it != allResults.end()) {
			countExistsAnswers = (*it).getCountAnswers();

			// если этот пользователь уже проходил и не завершил тест - узнаем кол-во правильных 
			// ответов и удаляем тест (если тест был завершен - просто удаляем его)
			if (countExistsAnswers < test.size()) {
				сountExistsRightAnswers = (*it).getCountRightAnswers();
				// если тест не был завершен, то начнем его проходить с места, где остановились
				startQuestions = countExistsAnswers;
				isTestExistFinished = false;
				system("cls");
				cout << "The test will continue where it finished" << endl;
				system("pause");
			}
			else {
				// если тест был завершен, мы его удалим и запишем новый, нам не нужно учитывать эти ответы
				countExistsAnswers = 0;
			}
			// удалим результат с вектора и присвоим этот вектор другому вектору что бы корректно 
			// сохранить результат удаления 
			allResults.erase(it);
			newResults = allResults;
		}	
		else {
			// и здесь тоже переприсвоим, потому что дальше будем использовать только newResults
			newResults = allResults;
		}
		// а если этот пользователь еще не проходил этот тест ранее - ничего не делаем
	}

	// теперь запустим тест и сохраним в вектор ответы студента
	vector<int> studentAnswers = getAnswers(startQuestions, test);
	
	int mark = 0;
	// для случая если тест уже был пройден и не завершен - сразу сохраним предыдущие правильные ответы
	int countRightAnswers = сountExistsRightAnswers;
	
	// запишем в вектор правильные ответы из файла с ответами
	string answersPath = utils->ANSWERS_DIRECTORY_PATH + "\\" + directoryName + "\\" + testName;
	Answers answersStorage;
	vector<int> rightAnswers = answersStorage.readFromFile(answersPath);

	// если студент уже проходил этот тест и он был не завершен, то с вектора правильных ответов
	// вырежем первые ответы, которые студент уже дал ранее. что бы сравнивать только ответы 
	// повторного прохождения теста
	if (!isTestExistFinished) {
		rightAnswers.erase(rightAnswers.begin(), rightAnswers.begin() + countExistsAnswers);
	}

	int countStudentAnswers = studentAnswers.size();

	// если текущий тест завершен
	if (studentAnswers.size() == test.size()) {
		// сравним ответы студента с правильными ответами теста 
		for (int i = 0; i < test.size(); i++) {
			if (studentAnswers[i] == rightAnswers[i]) {
				countRightAnswers++;
			}
		}
		// и поскольку завершен - можно сразу выставить оценку. Если оцкенка = 0 то тест не завершен
		mark = calcMark(countRightAnswers, test.size());
	}
	else {
		// если текущий тест не завершен
		for (int i = 0; i < studentAnswers.size(); i++) {
			// сравним только нужную часть ответов студента с правильными ответами теста 
			if (studentAnswers[i] == rightAnswers[i]) {
				countRightAnswers++;
			}
		}
		// если при повторном прохождении теста студент все же завершил его, то нужно выставить оценку
		if (studentAnswers.size() + countExistsAnswers == test.size()) {
			mark = calcMark(countRightAnswers, test.size());
		}
		// и в любом случае изменить кол-во ответов студента
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

		//очистка вектора
		allResults.clear();

		int size;
		is >> size;
		// что бы потом нормально считывать строками
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
	//открытие файла на запись
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
	// если файл откроется - файл существует - результаты уже есть, иначе - тесты еще не прорходил ни кто
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


