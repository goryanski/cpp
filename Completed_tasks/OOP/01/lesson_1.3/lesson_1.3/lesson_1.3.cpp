// задание 1, дз
#include<iostream>
#include <conio.h>
using std::cout;
using std::cin;

class fraction {
	int x; //numerator
	int y; //denominator
public:
	fraction() {
		x = y = 0;
	}
	fraction(int x, int y) {
		if (y == 0) {
			cout << "Error. Denominator cannot be equal to 0\n";
		}
		else {
			this->x = x;
			this->y = y;
		}
	}
	void print(char* name) {
		if (y == 0) {
			cout << "Error. Fraction " << name << " does not exist. Denominator cannot be equal to 0\n";
		}
		else {
			cout << name << " = " << x << "/" << y << "\n";
		}
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};
//numerator = num, denominator = denom
void add(int numA, int denomA, int numB, int denomB) {
	int numNew = numA * denomB + numB * denomA;
	int denomNew = denomA * denomB;
	cout << "\n\n Result: " << numNew << "/" << denomNew << "\n\n";
}
void sub(int numA, int denomA, int numB, int denomB) {
	int numNew = numA * denomB - numB * denomA;
	int denomNew = denomA * denomB;
	cout << "\n\n Result: " << numNew << "/" << denomNew << "\n\n";
}
void mul(int numA, int denomA, int numB, int denomB) {
	int numNew = numA * numB;
	int denomNew = denomA * denomB;
	cout << "\n\n Result: " << numNew << "/" << denomNew << "\n\n";
}
void div(int numA, int denomA, int numB, int denomB) {
	int numNew = numA * denomB;
	int denomNew = numB * denomA;
	cout << "\n\n Result: " << numNew << "/" << denomNew << "\n\n";
}
int main() {
	fraction A(1, 3);
	A.print((char*)"A");
	fraction B(3, 4);
	B.print((char*)"B");
	char ch;
	do
	{
		cout << " 1 - Add fractions\n"
			" 2 - Sub fractions\n"
			" 3 - Mul fractions\n"
			" 4 - Div fractions\n"
			" 0 - Exit\n"
			" Yuor choice: ";
		ch = _getch();
		system("cls");
		switch (ch) {
		case '1':
			add(A.getX(), A.getY(), B.getX(), B.getY());
			break;
		case '2':
			sub(A.getX(), A.getY(), B.getX(), B.getY());
			break;
		case '3':
			mul(A.getX(), A.getY(), B.getX(), B.getY());
			break;
		case '4':
			div(A.getX(), A.getY(), B.getX(), B.getY());
			break;
		}
	} while (ch != '0');

	system("pause");
	return 0;
}