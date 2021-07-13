#include <iostream>
#include <vector>
#include <iomanip>
using std::vector;
using std::cout;
using std::setw;

int main() {

	vector<vector<int>> vv;

	// заполнение вектора векторов
	int multiplier = 1;
	for (int i = 0; i < 10; i++) {
		vector<int> tmp;		
		for (int j = 0; j < 10; j++) {
			tmp.push_back((j + 1) * multiplier);
		}
		multiplier += 1;
		vv.push_back(tmp);
	}

	// вывод вектора векторов
	cout << " ";
	for (int i = 1; i <= 10; i++) {
		cout << setw(6) << i;
	}
	cout << "\n\n";

	for (int i = 0; i < 10; i++) {
		cout << i + 1 << setw(6);
		for (int j = 0; j < 10; j++) {
			cout << vv[i][j] << setw(6);
		}
		cout << "\n";
	}

	return 0;
}