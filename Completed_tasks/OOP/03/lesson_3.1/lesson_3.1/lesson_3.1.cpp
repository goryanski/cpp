#include<iostream>
using std::cout;
using std::cin;

class Date {
	int day;
	int month;
	int year;
public:
	Date() {
		day = month = year = 0;
	}
	Date(int day, int month, int year) {
		setDate(day, month, year);
	}
	Date(const Date& obj) {
		setDate(obj.day, obj.month, obj.year);
	}
	void print() {
		cout << day << "." << month << "." << year << "\n";
	}
	void setDate(int day, int month, int year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
	//перегрузка оператора '-'
	Date operator - (const Date& obj) {
		int dataTmp1 = day + month * 30 + year * 365;
		int dataTmp2 = obj.day + obj.month * 30 + obj.year * 365;
		int res = abs(dataTmp1 - dataTmp2);	
		Date data;
		data.day = (res % 365) % 30;
		data.month = (res % 365) / 30;
		data.year = res / 365;
		return data;
	}
};
int main() {
	Date date1(11, 3, 2000);
	date1.print();
	Date date2(22, 8, 2011);
	date2.print();
	Date date3;
	date3 = date1 - date2;
	cout << "date1 - date2 = ";
	date3.print();

	system("pause");
	return 0;
}