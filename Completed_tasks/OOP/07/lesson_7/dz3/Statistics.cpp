#include "Statistics.h"

Statistics* Statistics::instance = nullptr;

Statistics::Statistics()
{
	queue = PriorityQueue::getInstance();
	int size = queue->capacity;
	namesForStatistics = new String[size];
	timePrint = new String[size];
	sizeArrStatistics = 0;
}

Statistics* Statistics::getInstance()
{
	if (instance == nullptr) {
		instance = new Statistics();
	}
	return instance;
}

Statistics::~Statistics()
{
	delete[] namesForStatistics;
	delete[] timePrint;
}

void Statistics::fillStatistics()
{
	sizeArrStatistics = queue->count;
	int i = 0;
	while (!queue->isEmpty()) {

		namesForStatistics[i] = queue->extract();

		// ��������� ������� ����� � ������
		// ��� � #define _CRT_SECURE_NO_WARNINGS 
		time_t rawtime;
		struct tm* timeinfo;
		char buffer[30]; // ������, � ������� ����� ��������� ������� �����

		time(&rawtime); // ������� ���� � ��������
		timeinfo = localtime(&rawtime); // ������� ��������� �����, �������������� � ���������

		strftime(buffer, 30, "%X, %A", timeinfo); // ����������� ������ �������. %X - ������ �����, %A - ���� ���� ������ 

		String str(buffer);
		timePrint[i] = str;

		i++;
	}
}

void Statistics::showStatistics()
{
	cout << "\nStatistics of print:\n\n";
	cout << left << setw(30) << "Name" << "Time\n";
	for (int i = 0; i < sizeArrStatistics; i++)
	{
		cout << left << setw(30);
		namesForStatistics[i].showStr();
		timePrint[i].showStr();
		cout << "\n";
	}
}


