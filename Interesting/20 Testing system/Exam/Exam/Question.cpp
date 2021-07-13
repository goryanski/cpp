#include "Question.h"

Question::Question()
{
	question = "";
}

Question::Question(string question, vector<string> answerOptions)
	: question(question), answerOptions(answerOptions)
{
}

string Question::getQuestion() const
{
	return question;
}

vector<string> Question::getAnswerOptions()const
{
	return answerOptions;
}

void Question::setQuestion(string question)
{
	this->question = question;
}

void Question::setAnswerOptions(vector<string> answerOptions)
{
	this->answerOptions = answerOptions;
}

void Question::showQuestion() const
{
	cout << question << endl;
	for (int i = 0; i < answerOptions.size(); i++) {
		cout << "[" << i+1 << "] " << answerOptions[i] << endl;
	}
	cout << endl;
}

ostream& operator<<(ostream& os, const Question& obj)
{
	os << obj.question << "\n";
	for (int i = 0; i < obj.answerOptions.size(); i++) {
		os << obj.answerOptions[i] << "\n";
	}
	return os;
}
