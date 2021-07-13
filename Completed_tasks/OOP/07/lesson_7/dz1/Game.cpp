#include "Game.h"

void Game::start()
{
	char ch = 1;
	while (ch != ESC) {		
		menu();
		cout << "\t\t";
		ch = _getch();
		if (ch == ENTER) {
			game();
			cout << "\n\n\n";
		}
		else if(ch == ESC) {
			exit(0);
		}
		else {
			cout << "\n\t\tInvalid Button\n\n";
		}
	}
}

void Game::menu()
{
	cout << "\n\t\tONE-ARMED BULLY\n";
	cout << "\t\t[Enter] start\n";
	cout << "\t\t[Esc] exit\n";
}

void Game::game()
{
	Queue drum(3);
	drum.add(char(1));
	drum.add(char(2));
	drum.add(char(55));

	char tmpSign1 = drum.queue[0];
	char tmpSign2 = drum.queue[0];
	char tmpSign3 = drum.queue[0];

	int i = 7 + rand() % 4;
	while (i != 0) {
		system("cls");
		drum.extract();
		cout << "\n\n\t\t" << drum.queue[0] << "\t" << drum.queue[0] << "\t" << drum.queue[0];
		Sleep(150);
		if (i == 1) {
			system("cls");
			tmpSign1 = drum.extract();
			cout << "\n\n\t\t" << tmpSign1 << "\t" << drum.queue[0] << "\t" << drum.queue[0];
		}
		i--;
	}

	i = 7 + rand() % 4;
	while (i != 0) {
		system("cls");
		drum.extract();
		cout << "\n\n\t\t" << tmpSign1 << "\t" << drum.queue[0] << "\t" << drum.queue[0];
		Sleep(150);
		if (i == 1) {
			system("cls");
			tmpSign2 = drum.extract();
			cout << "\n\n\t\t" << tmpSign1 << "\t" << tmpSign2 << "\t" << drum.queue[0];
		}
		i--;
	}

	i = 7 + rand() % 4;
	while (i != 0) {
		system("cls");
		drum.extract();
		cout << "\n\n\t\t" << tmpSign1 << "\t" << tmpSign2 << "\t" << drum.queue[0];
		Sleep(150);
		if (i == 1) {
			system("cls");
			tmpSign3 = drum.extract();
			cout << "\n\n\t\t" << tmpSign1 << "\t" << tmpSign2 << "\t" << tmpSign3;
		}
		i--;
	}

	if (tmpSign1 == tmpSign2 && tmpSign1 == tmpSign3) {
		cout << "\n\n\t\t  You are WIN\n";
	}
	else {
		cout << "\n\n\t\t  You are LOSE\n";
	}
}

