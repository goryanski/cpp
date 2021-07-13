#include "Answers.h"

Answers::Answers()
{
	utils = Utils::getInstance();
}

void Answers::writeToFile(string path)
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

vector<int> Answers::readFromFile(string answersPath)
{
	ifstream is(answersPath, ios::out | ios::binary);
	if (is.is_open()) {

		answers.clear();
		int size;
		is >> size;

		int answer;
		for (int i = 0; i < size; i++) {
			is >> answer;
			answers.push_back(answer);
		}
		is.close();
		return answers;
	}
}
