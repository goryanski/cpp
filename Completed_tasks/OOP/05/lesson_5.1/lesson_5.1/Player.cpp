#include "Player.h"

Player::Player()
{
    name = nullptr;
    score = 100;
}

Player::Player(char* name)
{
    setName(name);
    score = 100;
}

Player::Player(const Player& obj)
{
    setName(obj.name);
    score = obj.score;
}

Player::~Player()
{
    delete[] name;
}

void Player::setName(char* name)
{
    int len = strlen(name) + 1;
    this->name = new char[len];
    strcpy_s(this->name, len, name);
}

ostream& operator<<(ostream& os, const Player& obj)
{
    os << obj.name << ", you have " << obj.score << " points\n";
    return os;
}