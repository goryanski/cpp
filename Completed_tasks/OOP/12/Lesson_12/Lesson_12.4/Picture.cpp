#include "Picture.h"

Picture::Picture()
{
	figures = nullptr;
}

void Picture::addFigure(int countFigures)
{
	if (countFigures < 1) {
		cout << "Picture is empty\n";
	}
	else {
		this->countFigures = countFigures;
		figures = new Figure[countFigures];
		for (int i = 0; i < countFigures; i++) {
			char color[15];
			cout << "Set color\n";
			gets_s(color);
			int corners;
			cout << "Set count corners\n";
			cin >> corners;
			cin.ignore();
			figures[i].setFigure(color, corners);
		}
	}
}
Picture::~Picture()
{
	if (figures != nullptr) {
		delete[] figures;
	}
}

