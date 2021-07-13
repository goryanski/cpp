#pragma once
#include "Player.h"
#include "Plain.h"
class Game {
    Player player;
    Plain plain;
public:
    void start();

    void game();

    void restart();
};
