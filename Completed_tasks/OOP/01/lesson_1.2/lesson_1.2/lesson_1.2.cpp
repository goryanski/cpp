// задание 2, практика
#include<iostream>
using namespace std;
class Point {
	int x;
	int y;
	int z;
public:
	Point() {
		x = 0;
		y = 0;
		z = 0;
	}
	FILE* pf = nullptr;
	Point(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
		fopen_s(&pf, "Doc2.txt", "wt");
		if (pf != nullptr) {
			char strX[5] = "";
			_itoa_s(x, strX, 10);
			fputs(strX, pf);
			fputc('\t', pf);

			char strY[5] = "";
			_itoa_s(y, strY, 10);
			fputs(strY, pf);
			fputc('\t', pf);

			char strZ[5] = "";
			_itoa_s(z, strZ, 10);
			fputs(strZ, pf);
		}
		else {
			cout << " Error.\n";
		}
	}
	~Point() {
		fclose(pf);
	}

	void print() {
		cout << endl << x << "\t" << y << "\t" << z << endl;
	}

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getZ() {
		return z;
	}
};

int main() {
	int x, y, z;
	x = y = z = 0;
	FILE* pf = nullptr;
	// проверим, не пустой ли файл
	fopen_s(&pf, "Doc1.txt", "rt");
	int count = 0;
	if (pf != nullptr) {
		char ch;
		while ((ch = fgetc(pf)) != EOF) {
			count++;
		}
		fclose(pf);
	}
	else {
		cout << " Error.\n";
	}
	// если не пустой - берем данные из него, иначе - вводим с клавиатуры
	if (count > 0) {
		fopen_s(&pf, "Doc1.txt", "rt");
		char strX[5] = "";
		char strY[5] = "";
		char strZ[5] = "";
		fscanf_s(pf, "%s", strX, 5);
		x = atoi(strX);
		fscanf_s(pf, "%s", strY, 5);
		y = atoi(strY);
		fscanf_s(pf, "%s", strZ, 5);
		z = atoi(strZ);
		fclose(pf);
	}
	else {
		cout << " Entrer x: ";
		cin >> x;
		cout << " Entrer y: ";
		cin >> y;
		cout << " Entrer z: ";
		cin >> z;
	}

	Point point(x, y, z);
	point.print();

	system("pause");
	return 0;
}