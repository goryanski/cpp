#include <iostream>
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios;
using std::cout;
using std::cin;
using std::string;

int main() {
	cout << "Enter word to find: ";
	string srhWord;
	cin >> srhWord;

	cout<< "Enter a new word to change found: ";
	string changeWord;
	cin >> changeWord;

	ifstream is("myFile.txt");
	if (is.is_open()) {
		string str;
		char buff[200];
		while (!is.eof()) {
			is.getline(buff, 200, '\n');
			str.append(buff);
		}
		// вывод всего файла
		cout << "\n1. Output file on display:\n";
		cout << str << "\n\n";

		// поиск заданного слова
		int pos = str.find(srhWord, 0);
		if (pos != -1) {
			cout << "Word \"" << srhWord << "\" started from "<< pos <<" position\n";

			// замена заданного слова
			str.replace(pos, srhWord.length(), changeWord);

			cout << "\n\nOutput Changed file:\n";
			cout << str << "\n\n";
		}
		else {
			cout << "This word not found\n";
		}

		is.close();

		// переворот
		ofstream os("myNewFile.txt", ios::binary | ios::app);
		if (os.is_open()) {
			cout << "\n\nReverse file:\n";
			int length = str.length() - 1;
			for (int i = length; i >= 0; i--) {
				cout << str[i];
				os << str[i];
			}
			cout << "\n";
			os.close();
		}
		else {
			cout << "Error opening file\n";
		}
	}
	else {
		cout << "Error opening file\n";
	}
	return 0;
}