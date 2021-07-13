#include "Catalog.h"

Catalog::Catalog()
{
	countFirms = 0;
	arrFirms = nullptr;
}

void Catalog::menu()
{
	system("cls");
	cout << " <<MENU>>\n"
		" [1] Add firm\n"
		" [2] Find by name of firm\n"
		" [3] Find by manager\n"
		" [4] Find by phone\n"
		" [5] Find by direction\n"
		" [6] Show list of firms\n"
		" [0] Exit\n"
		" Your choose: ";
}

void Catalog::addToFile()
{
	char firmName[25];
	cout << "\nEnter name of firm: ";
	gets_s(firmName);
	char fio[30];
	cout << "Enter FIO of manager: ";
	gets_s(fio);
	char phone[15];
	cout << "Enter number of phone: ";
	gets_s(phone);
	char address[40];
	cout << "Enter address: ";
	gets_s(address);
	char direction[20];
	cout << "Enter direction of business: ";
	gets_s(direction);
	Firm firm(firmName, fio, phone, address, direction);

	ofstream os("firms.txt", ios::out | ios::binary | ios::app);
	if (os.is_open()) {
		// firm попадает в перегрузку сиаута и выводится в файл
		os << firm << "\n";
		os.close();
		cout << "Added.\n";
		Sleep(1000);
	}
	else {
		cout << "Error opening file\n";
		system("pause");
	}
}

void Catalog::searchByName()
{
	readFile();
	if (countFirms > 0) {
		char firmName[25];
		cout << "\nEnter name of firm: ";
		gets_s(firmName);
		int flag = 0;
		for (int i = 0; i < countFirms; i++) {
			if (strcmp(firmName, arrFirms[i].firmName) == 0) {
				cout<< arrFirms[i] << "\n";
				flag = 1;
			}
		}
		if (flag == 0) {
			cout << "Not found\n";
		}
	}
	else {
		cout << "File is empty\n";
	}
	system("pause");
}

void Catalog::searchByManager()
{
	readFile();
	if (countFirms > 0) {
		char fio[30];
		cout << "Enter FIO of manager: ";
		gets_s(fio);
		int flag = 0;
		for (int i = 0; i < countFirms; i++) {
			if (strcmp(fio, arrFirms[i].manager) == 0) {
				cout << arrFirms[i] << "\n";
				flag = 1;
			}
		}
		if (flag == 0) {
			cout << "Not found\n";
		}
	}
	else {
		cout << "File is empty\n";
	}
	system("pause");
}

void Catalog::searchByPhone()
{
	readFile();
	if (countFirms > 0) {
		char phone[15];
		cout << "Enter number of phone: ";
		gets_s(phone);
		int flag = 0;
		for (int i = 0; i < countFirms; i++) {
			if (strcmp(phone, arrFirms[i].manager) == 0) {
				cout << arrFirms[i] << "\n";
				flag = 1;
			}
		}
		if (flag == 0) {
			cout << "Not found\n";
		}
	}
	else {
		cout << "File is empty\n";
	}
	system("pause");
}

void Catalog::searchByDirection()
{
	readFile();
	if (countFirms > 0) {
		char direction[20];
		cout << "Enter direction of business: ";
		gets_s(direction);
		int flag = 0;
		for (int i = 0; i < countFirms; i++) {
			if (strcmp(direction, arrFirms[i].manager) == 0) {
				cout << arrFirms[i] << "\n";
				flag = 1;
			}
		}
		if (flag == 0) {
			cout << "Not found\n";
		}
	}
	else {
		cout << "File is empty\n";
	}
	system("pause");
}

void Catalog::readFile()
{
	// что бы не создавать для записи в файл никаких массивов, будем считать строки в файле и потом уже формировать новый массив, так мы всегда сможем добавлять и считывать всю инфу при повторных запусках программы
	ifstream is("firms.txt");
	if (is.is_open()) {
		int sizeArr = 0;
		char ch;
		while (!is.eof()) {
			is.get(ch);
			if (ch == '\n') {
				sizeArr++;
			}			
		}
		// не считаем последний
		sizeArr--;
		// здесь сохраним массив и размер в поле класса что бы не передавать в параметрах
		countFirms = sizeArr; 
		is.close();
		if (sizeArr > 0) {
			ifstream is("firms.txt", ios::in | ios::binary);
			arrFirms = new Firm[sizeArr];
			for (int i = 0; i < sizeArr; i++) {
				is >> arrFirms[i];
			}
			is.close();			
		}
		else {
			cout << "File is empty\n";
		}
	}
	else {
		cout << "Error opening file\n";
	}
}

void Catalog::showOnDisplay()
{
	if (countFirms > 0) {
		for (int i = 0; i < countFirms; i++) {
			cout << arrFirms[i] << "\n";
		}
	}
	else {
		cout << "File is empty\n";
	}
	system("pause");
}

void Catalog::start()
{
	int choose = 1;
	while (choose != 0) {
		menu();
		cin >> choose;
		cin.ignore();
		switch (choose) {
		case ADD:
			addToFile();
			break;
		case SEARCH_BY_NAME:
			searchByName();
			break;
		case SEARCH_BY_MANAGER:
			searchByManager();
			break;
		case SEARCH_BY_PHONE:
			searchByPhone();
			break;
		case SEARCH_BY_DIRECTION:
			searchByDirection();
			break;
		case SHOW_ON_DISPLAY:			
			readFile();
			showOnDisplay();
			break;
		case 0:
			exit(0);
			break;
		}
	}
}
