#include "foreignPassport.h"

// flag нужен что бы определить, впервые мы добавляем визу или нет
int foreignPassport::flag = 0;

foreignPassport::foreignPassport()
{
	vises = nullptr;
	countVises = flag = 0;
}

foreignPassport::foreignPassport(char* firstname, char* lastname, char* number, char* adress, int age, char* visa)
	: Passport(firstname, lastname, number, adress, age) {
	if (flag == 0) {
		countVises = 1;
		vises = new char* [countVises];
		vises[0] = visa;
		flag = 1;
	}
	// если не впервые, то перераспределяем память что бы заполнять массив виз
	else {
		char** tmp = new char* [countVises + 1];
		for (int i = 0; i < countVises; i++) {
			tmp[i] = vises[i];
		}
		tmp[countVises] = visa;
		countVises++;
		delete[] vises;
		vises = tmp;
	}
}

