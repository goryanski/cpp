#include "Figure.h"



Figure::Figure()
{
   corners = 0;
   color[0] = '\0';
}

void Figure::setFigure(char* color, int corners)
{
    //если углов меньше трех — это не фигура
    if (corners < 3) {
        exit(0);
    }
    strcpy_s(this->color, color);
    this->corners = corners;
    points = new Point[corners];
    if (!points) {
        exit(0);
    }
    int tmpX, tmpY;
    for (int i = 0; i < corners; i++) {
        cout << "Set X: ";
        cin >> tmpX;
        cout << "Set Y: ";
        cin >> tmpY;
        points[i].setPoint(tmpX, tmpY);        
    }
    cout << "\nIt's " << color << " " << corners << "-ugolnic\n";
}

Figure::~Figure()
{
    if (points != nullptr) {
        delete[] points;
    }
}
