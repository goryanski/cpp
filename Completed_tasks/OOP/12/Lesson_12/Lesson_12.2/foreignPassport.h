#pragma once
#include "Passport.h"

class foreignPassport : public Passport {
	char** vises;
	int countVises;
	// ����� ������� ����� ���������� flag ��� ������������ 
	static int flag;
public:
	foreignPassport();
	foreignPassport(char* firstname, char* lastname, char* number, char* adress, int age, char* visa);
};

