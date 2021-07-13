#include <iostream>
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;
using std::cout;
using std::cin;
using std::string;

bool isTagValid(string str, string tag, int posTag) {
	if (str[posTag - 1] == '<' &&  str[posTag + tag.length()] == '>') {
		return true;
	}
	return false;
}

int main() {
	cout << "Enter path to file: ";
	string path;
	cin >> path;
	//string path = "html.txt";

	ifstream is(path);
	if (is.is_open()) {
		string str;
		char buff[200];
		while (!is.eof()) {
			is.getline(buff, 200, '\n');
			str.append(buff);
			str.append("\n");
		}
		is.close();

		// вывод всего файла
		cout << "Output file on display:\n" << str << "\n\n";

		// для оптимизации поиска , поскольку есть строгая последовательность тегов
		int startSrch = 0;

		string html1 = "html";
		int posHtml1 = str.find(html1, startSrch);
		if (!isTagValid(str, html1, posHtml1)) {
			cout << "File invalid\n";
			exit(0);
		}
		startSrch += html1.length();

		string body1 = "body";
		int posBody1 = str.find(body1, startSrch);
		if (!isTagValid(str, body1, posBody1)) {
			cout << "File invalid\n";
			exit(0);
		}
		startSrch = posBody1 + body1.length();

		string body2 = "/body";
		int posBody2 = str.find(body2, startSrch);
		if (!isTagValid(str, body2, posBody2)) {
			cout << "File invalid\n";
			exit(0);
		}
		startSrch = posBody2 + body2.length();

		string html2 = "/html";
		int posHtml2 = str.find(html2, startSrch);
		if (!isTagValid(str, html2, posHtml2)) {
			cout << "File invalid\n";
			exit(0);
		}

		cout << "File is valid\n";
	}
	else {
		cout << "Error opening file\n";
	}
	return 0;
}