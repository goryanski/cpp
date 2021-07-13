#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::ostream;
using std::istream;
using std::getline;
using std::vector;
using std::endl;
using std::cout;

// тест = вектор из вопросов. класс Question - один вопрос
class Question
{
	string question;
	vector<string> answerOptions;
public:
	Question();
	Question(string, vector<string>);

	string getQuestion()const;
	vector<string> getAnswerOptions()const;
	void setQuestion(string);
	void setAnswerOptions(vector<string>);

	void showQuestion()const;

	friend ostream& operator << (ostream&, const Question&);
};

