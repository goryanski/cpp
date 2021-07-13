#pragma once
#include <iostream>
using std::ostream;
//прототип класса Game
class Game;
class Player {
    char* name;
    int score;
public:
    Player();
    Player(char* name);
    Player(const Player& obj);
    ~Player();
    void setName(char* name);
    friend ostream& operator <<(ostream& os, const Player& obj);
    friend Game;
};

ostream& operator <<(ostream& os, const Player& obj);
