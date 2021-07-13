#pragma once
#include <iostream>
using std::ostream;
//прототип класса Game
class Game;
class Plain {
    int speed;
    int heightFlight;
public:
    Plain(int speed = 0, int heightFlight = 0);
    friend ostream& operator <<(ostream& os, const Plain& obj);
    friend Game;
};

ostream& operator <<(ostream& os, const Plain& obj);