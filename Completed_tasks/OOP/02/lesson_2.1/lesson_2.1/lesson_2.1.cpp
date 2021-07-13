#include<iostream>
using namespace std;

class String {
	char* str;
	int size;
public:
	String() {
		size = 81;
		this->str = new char[size];
	}
	String(int length) {
		this->str = new char[length + 1];// для \0
		size = length + 1;
	}
	String(char* str) {
		setStr(str);
	}
	String(const String& obj) {
		int len = strlen(obj.str) + 1;
		this->str = new char[len];
		strcpy_s(str, len, obj.str);
	}
	~String() {
		delete[] str;
	}
	void setStr(char* str) {
		size = strlen(str) + 1;
		this->str = new char[size];
		strcpy_s(this->str, size, str);
	}
	void show() {
		cout << str << endl;
	}
	void showSize() {
		cout << size << endl;
	}
};

int main() {
	String str1; // по умолчанию
	cout << "size of str1: ";
	str1.showSize();

	int length;
	cout << "Enter length of string: ";
	cin >> length;
	String str2(length); // строка произвольного размера
	cout << "size of str2: ";
	str2.showSize();

	char myStr[100];
	cout << "Input string: ";
	cin.ignore();
	gets_s(myStr);
	String str3(myStr); // инициализированная строка
	str3.show();

	system("pause");
	return 0;
}