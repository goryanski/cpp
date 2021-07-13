#include<iostream>
using std::cout;
using std::cin;

class String {
	char* str;
	int size;
public:
	String() {
		size = 0;
		str = nullptr;
	}
	String(char* str) {
		setStr(str);
	}
	String(const String& obj) {
		setStr(obj.str);
	}
	~String() {
		delete[] str;
	}
	void setStr(char* str) {
		size = strlen(str) + 1;
		this->str = new char[size];
		strcpy_s(this->str, size, str);
	}
	void print() {
		cout << str << "\n";
	}
	String operator * (const String& obj) {
		int len;
		(strlen(str) > strlen(obj.str)) ? len = strlen(str) + 1 : len = strlen(obj.str) + 1;
		String newStr;
		newStr.str = new char[len];
		newStr.size = len;
		int k = 0;
		for (int i = 0; i < strlen(str) + 1; i++) {
			for (int j = 0; j < strlen(obj.str) + 1; j++) {
				if (str[i] == obj.str[j]) {
					newStr.str[k] = str[i];
					k++;
				}
			}
		}
		return newStr;
	}
};

int main() {
	String str1((char*)"sdqcg");
	str1.print();
	String str2((char*)"rgfas34");
	str2.print();
	cout << "str1 * str2 = ";
	String strRes = str1 * str2;
	strRes.print();
}