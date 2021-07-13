#pragma once
#include "Expression.h"
#include <iostream>
using std::cout;
using std::string;

char operations[] = { '/', '*', '+', '-' };

string reverseStr(string s) {
	string res;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		res += s[i];
	}
	return res;
}

template<typename T>
T runOperation(Expression<T> expression) {
	T result;
	switch (expression.operation) {
	case '+':
		result = expression.first + expression.second;
		break;
	case '-':
		result = expression.first - expression.second;
		break;
	case '*':
		result = expression.first * expression.second;
		break;
	case '/':
		result = expression.first / expression.second;
		break;
	}

	return result;
}

template<typename T>
void calcSubExpression(string& str, int pos) {
	Expression<T> expr;

	string leftOperand;
	string rightOperand;
	char operation = str[pos];

	int firstPosStart = -1;
	int secondPosEnd = -1;
	int tmp = pos - 1;
	int tmp2 = tmp;
	// идем влево
	while (tmp >= 0 && (isdigit(str[tmp]) || str[tmp2] == '-')) {
		leftOperand += str[tmp];
		tmp--;
	}
	if (tmp - 2 >= 0) {
		if (str[tmp - 1] == '-' && !isdigit(str[tmp - 2])) {
			leftOperand += '-';
			tmp--;
		}
	}
	else if (tmp == 0 && str[0] == '-') {
		leftOperand += '-';
		tmp--;
	}
	leftOperand = reverseStr(leftOperand);
	firstPosStart = tmp + 1;

	tmp = pos + 1;
	tmp2 = tmp;
	// идем вправо 
	while (tmp < str.length() && (isdigit(str[tmp]) || str[tmp2] == '-')) {
		if (str[tmp2] == '-') {
			// когда tmp2 минус, то мы из этого цикла не сможем выйти, пока не закончится строка справа, и в правый операнд
			// запишется все что стоит справа до конца строки, тем самым пропадет пол выражения, а кол-во операций
			// останется прежним, т.к. мы его посчитали раньше, чем зашли и этот цикл
			// поэтому сбросим tmp2 на 0, т.к. на -1 не можем 
			tmp2 = 0;
		}
		rightOperand += str[tmp];
		tmp++;
	}
	secondPosEnd = tmp - 1;

	expr.first = atoi(leftOperand.c_str());
	expr.second = atoi(rightOperand.c_str());
	expr.operation = operation;
	T result = runOperation(expr);

	char tmpBuff[10];
	_itoa_s(result, tmpBuff, 10);

	str.replace(firstPosStart, secondPosEnd - firstPosStart + 1, tmpBuff);
}

int getOperationPos(string str) {
	int posMult = str.find('*', 1);
	int posDiv = str.find('/', 1);
	int posPlus = str.find('+', 1);
	int posMinus = str.find('-', 1);
	int pos = -1;

	if (posMult != -1 && (posMult < posDiv || posDiv == -1)) {
		pos = posMult;
	}
	else if (posDiv != -1) {
		pos = posDiv;
	}
	else if (posPlus != -1 && (posPlus < posMinus || posMinus == -1)) {
		pos = posPlus;
	}
	else if (posMinus != -1) {
		pos = posMinus;
	}
	return pos;
}

bool canCalc(string str) {
	int pos = getOperationPos(str);
	return pos != 0;
}

bool isOperation(char symb) {
	for (int i = 0; i < strlen(operations); i++)
	{
		if (symb == operations[i]) {
			return true;
		}
	}
	return false;
}

int calcOperations(string str) {
	int counter = 0;
	int pos = -1;
	for (int i = 1; i < str.length(); i++) {
		if (isOperation(str[i])) {
			if (i < strlen(str.c_str()) - 1 && str[i + 1] == '-') {
				continue;
			}
			counter++;
		}
	}
	return counter;
}

template<typename T>
T calcExpression(string expr) {

	while (canCalc(expr)) {

		int posFirst = expr.rfind('(');
		// если скобок больше нет - выходим из цикла
		// благодаря брейку, при первом вызове ф-ции нам вернется выражение без скобок, а при втором - результат всего 
		// выражения в виде строки
		if (posFirst == -1) {
			break;
		}
		int posSecond = expr.find(')', posFirst);
		string subExpr = expr.substr(posFirst + 1, posSecond - posFirst - 1);

		int countOperations = calcOperations(subExpr);

		while (countOperations != 0) {
			int pos = getOperationPos(subExpr);
			calcSubExpression<int>(subExpr, pos);
			countOperations--;
		}
		expr.replace(posFirst, posSecond - posFirst + 1, subExpr.c_str());
	}
	return expr;
}