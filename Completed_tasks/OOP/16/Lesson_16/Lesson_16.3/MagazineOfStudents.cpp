#include "MagazineOfStudents.h"

void MagazineOfStudents::add()
{
	system("cls");
	cout << "Enter firstname: ";
	string firstname;
	cin >> firstname;
	cout << "Enter secondname: ";
	string secondname;
	cin >> secondname;
	cout << "Enter course: ";
	int course;
	cin >> course;

	Student student(firstname, secondname, course);
	students.push_back(student);
	cout << "Added.\n";
}

void MagazineOfStudents::print()
{
	system("cls");
	for (Student val : students) {
		cout << val << "\n";
	}
	system("pause");
}

void MagazineOfStudents::sortByFirstname()
{
	if (!students.empty()) {
		for (int i = 0; i < students.size() - 1; i++) {
			int f = 0;
			for (int j = 0; j < students.size() - 1 - i; j++) {
				if (students[j].firstName > students[j + 1].firstName) {
					auto tmp = students[j];
					students[j] = students[j + 1];
					students[j + 1] = tmp;
					f = 1;
				}
			}
			if (f == 0) {
				break;
			}
		}
	}
	else {
		cout << "Magazine is empty\n";
	}
}

void MagazineOfStudents::sortBySecondname()
{
	if (!students.empty()) {
		for (int i = 0; i < students.size() - 1; i++) {
			int f = 0;
			for (int j = 0; j < students.size() - 1 - i; j++) {
				if (students[j].secondName > students[j + 1].secondName) {
					auto tmp = students[j];
					students[j] = students[j + 1];
					students[j + 1] = tmp;
					f = 1;
				}
			}
			if (f == 0) {
				break;
			}
		}
	}
	else {
		cout << "Magazine is empty\n";
	}
}

void MagazineOfStudents::sortByCourse()
{
	if (!students.empty()) {
		cout << "Before sort:\n";
		for (Student val : students) {
			cout << val << "\n";
		}
		cout << "\n\n";

		int minCourse;
		Student minStudent;
		int tmpDel = -1;
		for (int i = 0; i < 3; i++) {
			// пусть минимальный курс у нулевого элемента. с последующими итерациями будем увеличивать индекс на 1
			minCourse = students[i].course;
			// j = i + 1 - начинаем проверку со следующего, с каждым разом увеличивая на 1
			for (int j = i + 1; j < students.size(); j++) {
				if (students[j].course < minCourse) {
					// запоминаем минимальный курс, объект с мин курсом и индекс этого объекта что бы его потом удалить
					minCourse = students[j].course;
					minStudent = students[j];
					tmpDel = j;
				}
			}
			// если минимальный был не нулевым 
			if (tmpDel != -1) {
				students.erase(students.begin() + tmpDel);
				students.insert(students.begin() + i, minStudent);
			}
		}

		cout << "After sort:\n";
		for (Student val : students) {
			cout << val << "\n";
		}
		system("pause");
	}
	else {
		cout << "Magazine is empty\n";
	}
}

void MagazineOfStudents::menu()
{
	cout << "\nMENU" << "\n";
	cout << "[1] Add" << "\n";
	cout << "[2] Print" << "\n";
	cout << "[3] Sort by firstname" << "\n";
	cout << "[4] Sort by secondname" << "\n";
	cout << "[5] At first to show tree younger" << "\n";
	cout << "[6] Exit" << "\n";
	cout << "Your choice: ";
}

void MagazineOfStudents::start()
{
	int action;
	while (true) {
		menu();
		cin >> action;

		switch (action) {
		case ADD:
			add();
			break;
		case PRINT:
			print();
			break;
		case SORT_BY_FIRSTNAME:
			sortByFirstname();
			print();
			break;
		case SORT_BY_SECONDNAME:
			sortBySecondname();
			print();
			break;
		case SORT_BY_COURSE:
			sortByCourse();
			break;
		case EXIT:
			exit(0);
			break;
		}
	}
}
