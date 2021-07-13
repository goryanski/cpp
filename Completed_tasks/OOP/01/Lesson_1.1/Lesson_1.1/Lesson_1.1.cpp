// задание 1, практика
#include<iostream>
using namespace std;
class StadyPlace {
	char name[20];
	char city[20];
	char country[20];
public:
	StadyPlace() {
		strcpy_s(name, "");
		strcpy_s(city, "");
		strcpy_s(country, "");
	}
	StadyPlace(char* name, char* city, char* country) {
		strcpy_s(this->name, name);
		strcpy_s(this->city, city);
		strcpy_s(this->country, country);
	}
	void print() {
		cout << name << " " << city << " " << country << endl;
	}

	//геттер
	char* getName() {
		return name;
	}
	char* getCity() {
		return city;
	}
	char* getCountry() {
		return country;
	}
};

class Student {
	char fio[30];
	char date[15];
	char phone[15];
	char city[20];
	char country[20];
	char group[10];
	StadyPlace* stadyPlace;
public:
	Student() {
		strcpy_s(fio, "");
		strcpy_s(date, "");
		strcpy_s(phone, "");
		strcpy_s(city, "");
		strcpy_s(country, "");
		strcpy_s(group, "");
		stadyPlace = nullptr;
	}
	Student(char* fio, char* date, char* phone, char* city, char* country, char* group, StadyPlace* stadyPlace) {
		strcpy_s(this->fio, fio);
		strcpy_s(this->date, date);
		strcpy_s(this->phone, phone);
		strcpy_s(this->city, city);
		strcpy_s(this->country, country);
		strcpy_s(this->group, group);
		this->stadyPlace = stadyPlace;
	}
	void show() {
		cout << fio << " " << date << " " << phone << " " << city << " " << country << " " << group << endl << endl;
		stadyPlace->print();
	}
	//геттер
	char* getFio() {
		return fio;
	}
	char* getDate() {
		return date;
	}
	char* getPhone() {
		return phone;
	}
	char* getCity() {
		return city;
	}
	char* getCountry() {
		return country;
	}
	char* getGroup() {
		return group;
	}
};
int main()
{
	//init
	char fio[30];
	cout << " Entrer fio: ";
	gets_s(fio);
	char date[15];
	cout << " Entrer date: ";
	gets_s(date);
	char phone[15];
	cout << " Entrer phone: ";
	gets_s(phone);
	char city[20];
	cout << " Entrer city: ";
	gets_s(city);
	char country[20];
	cout << " Entrer country: ";
	gets_s(country);
	char group[10];
	cout << " Entrer group: ";
	gets_s(group);
	char nameStudy[20];
	cout << " Entrer name of place of study: ";
	gets_s(nameStudy);
	char cityStudy[20];
	cout << " Entrer city of place of study: ";
	gets_s(cityStudy);
	char countryStudy[20];
	cout << " Entrer country of place of study: ";
	gets_s(countryStudy);

	StadyPlace stadyPlace(nameStudy, cityStudy, countryStudy);
	Student student(fio, date, phone, city, country, group, &stadyPlace);
	student.show();

	system("pause");
	return 0;
}
