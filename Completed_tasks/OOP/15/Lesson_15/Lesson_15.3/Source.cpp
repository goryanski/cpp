#include <iostream>
#include"Functions.h"

int main() {
	string expression = "10+7-5*(((25-15*10+25)/2)+10)*3+11"; // ответ должен быть 628
	// получим выражение без скобок
	string plainExpr = calcExpression<string>(expression);
	// обернем заново все выражение в скобки, что бы использовать существующие ф-ции и не писать новые 
	plainExpr.insert(0, "(");
	plainExpr.append(")");
	// и вызовем заново ту же ф-цию, кторорая уже вернет результат
	string resultStr = calcExpression<string>(plainExpr);
	double resultDouble = atof(resultStr.c_str());
	cout << "Result: " << resultDouble << "\n";
	return 0;
}