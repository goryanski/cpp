#include "TestEditor.h"

TestEditor::TestEditor()
{
	utils = Utils::getInstance();
}

void TestEditor::testEdit()
{
	// выбор теста для редактирования
	string directoryName = testsManagement.selectCategory();
	string testName = testsManagement.selectTest(directoryName);

	// путь к тестам и ответам 
	string testPath = utils->TESTS_DIRECTORY_PATH + "\\" + directoryName + "\\" + testName;
	string answersPath = utils->ANSWERS_DIRECTORY_PATH + "\\" + directoryName + "\\" + testName;

	// запишем в вектор тесты из файла с тестами
	test.clear();
	test = testsManagement.readTest(directoryName, testName);

	// запишем в вектор правильные ответы из файла с ответами
	Answers answersStorage;
	answers.clear();
	answers = answersStorage.readFromFile(answersPath);

	// вывод теста на экран для пользователя
	system("cls");
	cout << "Look at the test and select option to edit:" << endl << endl;
	showTest();

	bool comeBack = false;
	while (!comeBack) {
		menu();

		int selection;
		cin >> selection;
		cout << endl;

		switch (selection)
		{
		case ADD_QUESTION:
			addOuestion();			
			break;
		case DEL_QUESTION:
			removeOuestion();
			break;
		case ADD_VARIANT:
			addVariant();
			break;
		case DEL_VARIANT:
			removeVariant();
			break;
		case EDIT_QUESTION:
			editOuestion();
			break;
		case EDIT_VARIANT:
			editVariant();
			break;
		case EXIT:
			comeBack = true;
			break;
		}

		// заменим старые файлы на новые
		writeEditedTest(testPath);
		writeEditedAnswers(answersPath);

		showEditedTest();
	}
}


void TestEditor::menu()
{
	cout << endl << "What do you want to do?" << endl;
	cout << "[1] Add another question" << endl;
	cout << "[2] Delete some question" << endl;
	cout << "[3] Add another variant to question" << endl;
	cout << "[4] Delete some variant" << endl;
	cout << "[5] Edit some question" << endl;
	cout << "[6] Edit some variant" << endl;
	cout << "[0] To the previous menu" << endl;
	cout << "Your choice: ";
}

void TestEditor::showTest()
{
	int counter = 1;
	for_each(test.begin(), test.end(), [&counter](const Question& question) {
		cout << counter << ". ";
		question.showQuestion();
		counter++;
	});
	cout << endl;
}

void TestEditor::addOuestion()
{
	cin.ignore(32767, '\n');
	string question = testsManagement.inputQuestion();
	vector<string> answerOptions = testsManagement.inputVariants();
	int rightAnswer = testsManagement.inputRightAnswer();

	// добавим в конец вектора с тестами новый вопрос 
	Question fullQuestion(question, answerOptions);
	test.push_back(fullQuestion);

	// добавим еще новый ответ
	answers.push_back(rightAnswer);
}

void TestEditor::removeOuestion()
{
	int select = choiceOuestion();

	test.erase(test.begin() + (select - 1));
	answers.erase(answers.begin() + (select - 1));
}

void TestEditor::addVariant()
{
	int select = choiceOuestion();
	string variant = enterVariant();

	vector<string> newOptions = test[select - 1].getAnswerOptions();
	newOptions.push_back(variant);
	test[select - 1].setAnswerOptions(newOptions);

	changeRightVariant(select);
}

int TestEditor::choiceOuestion()
{
	cout << "Enter number of question: ";
	int select;
	cin >> select;

	while (select < 1 || select > test.size()) {
		cout << "Wrong number, try again: ";
		cin >> select;
	}
	return select;
}

void TestEditor::removeVariant()
{
	int select = choiceOuestion();
	vector<string> newOptions = test[select - 1].getAnswerOptions();

	cout << "Enter number of variant to remove: ";
	int number;
	cin >> number;
	while (number < 1 || number > newOptions.size()) {
		cout << "Wrong number, try again: ";
		cin >> number;
	}

	newOptions.erase(newOptions.begin() + (number - 1));
	test[select - 1].setAnswerOptions(newOptions);

	changeRightVariant(select);
}

void TestEditor::changeRightVariant(int select)
{
	cout << "Do you want to change a right variant of answer for this question?" << endl;
	cout << "[1] - yes" << endl;
	cout << "[0] - no" << endl;
	int chioce;
	cin >> chioce;

	while (chioce < 0 || chioce > 1) {
		cout << "Wrong number, try again: ";
		cin >> chioce;
	}

	if (chioce == 1) {
		cout << "Enter new right variant: ";
		int newRightVariant;
		cin >> newRightVariant;

		answers[select - 1] = newRightVariant;
	}
}

void TestEditor::editOuestion()
{
	int select = choiceOuestion();

	cout << "New question:" << endl;
	cin.ignore(32767, '\n');
	string newQuestion = testsManagement.inputQuestion();

	test[select - 1].setQuestion(newQuestion);

	changeRightVariant(select);
}

void TestEditor::editVariant()
{
	int select = choiceOuestion();
	vector<string> newOptions = test[select - 1].getAnswerOptions();

	cout << "Enter number of variant to edit: ";
	int number;
	cin >> number;
	while (number < 1 || number > newOptions.size()) {
		cout << "Wrong number, try again: ";
		cin >> number;
	}

	string newVariant = enterVariant();
	newOptions[number - 1] = newVariant;
	test[select - 1].setAnswerOptions(newOptions);

	changeRightVariant(select);
}

string TestEditor::enterVariant()
{
	cout << "Write new variant: ";
	string variant;
	cin.ignore(32767, '\n');
	getline(cin, variant);
	return variant;
}

void TestEditor::writeEditedTest(string path)
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

void TestEditor::writeEditedAnswers(string path)
{
	ofstream os(path, ios::in | ios::binary | ios::trunc);
	if (os.is_open()) {
		os << answers.size() << endl;

		for_each(answers.begin(), answers.end(), [&os](const int& answer) {
			os << answer << endl;
		});

		os.close();
	}
}

void TestEditor::showEditedTest()
{
	system("cls");
	cout << endl << "Edited test:" << endl;
	showTest();
}

