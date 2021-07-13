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

		// переводит текущее время в строку
		// ток с #define _CRT_SECURE_NO_WARNINGS 
		time_t rawtime;
		struct tm* timeinfo;
		char buffer[30]; // строка, в которой будет храниться текущее время

		time(&rawtime); // текущая дата в секундах
		timeinfo = localtime(&rawtime); // текущее локальное время, представленное в структуре

		strftime(buffer, 30, "%X, %A", timeinfo); // форматируем строку времени. %X - полное время, %A - полн недь недели 

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


