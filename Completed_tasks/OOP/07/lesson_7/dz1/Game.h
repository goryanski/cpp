#pragma once
#include "Queue.h"
#include <iostream>
#include "Windows.h"
#include "time.h"
#include "conio.h"
using std::cout;

class Game
{
public:
	void start();
private:
	enum { ENTER = 13, ESC = 27 };
	void menu();
	void game();
};

