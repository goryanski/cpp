#include <iostream>
#include"Functions.h"

int main() {
	string expression = "10+7-5*(((25-15*10+25)/2)+10)*3+11"; // ����� ������ ���� 628
	// ������� ��������� ��� ������
	string plainExpr = calcExpression<string>(expression);
	// ������� ������ ��� ��������� � ������, ��� �� ������������ ������������ �-��� � �� ������ ����� 
	plainExpr.insert(0, "(");
	plainExpr.append(")");
	// � ������� ������ �� �� �-���, �������� ��� ������ ���������
	string resultStr = calcExpression<string>(plainExpr);
	double resultDouble = atof(resultStr.c_str());
	cout << "Result: " << resultDouble << "\n";
	return 0;
}