#pragma once
#include "Point.h"
#include <iostream>
using std::cout;
using std::cin;

class Figure
{
	Point* points;
	char color[15];
    int corners;
public:
    Figure();
    void setFigure(char* color, int corners);
    ~Figure();
};




