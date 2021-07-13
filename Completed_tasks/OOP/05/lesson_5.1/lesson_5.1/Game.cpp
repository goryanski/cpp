#include "Game.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using std::cout;
using std::cin;
enum Directions {
    UP = 72,
    DOWN = 80,
    LEFT = 75,
    RIGHT = 77
};
void Game::start()
{
    char name[20];
    cout << "Enter name: ";
    gets_s(name);
    player.setName(name);
    cout << " Up / Down - to flight up or down,  Left / Right - speed up or down.\n"
        "Exit - 0\n GO!!!\n";
    game();
}

void Game::game()
{
    int stepHeight = 24;
    int stepSpeed = 50;
    int stepScore = 1;
    int countLoop = 0;
    int Exit = 0;
    while (true) {
        cout << player;
        cout << plain;

        int key = _getch();

        switch (key) {
        case DOWN:
            plain.heightFlight -= stepHeight;
            break;
        case UP:
            plain.heightFlight += stepHeight;
            break;
        case LEFT:
            plain.speed -= stepSpeed / 2;
            break;
        case RIGHT:
            plain.speed += stepSpeed;
            break;
        case '0':
            Exit = 1;
            break;
        }

        if (Exit == 1) {
            cout << " You pressed exit. Game over\n";
            break;
        }

        int f = 0; // флагом будем влиять на счет игрока
        countLoop++;
        if (countLoop > 5) {
            // со временем самолет будет терять немного скорости и высоты
            plain.speed -= stepSpeed / 10;
            plain.heightFlight -= stepHeight / 8;
        }
        if ((plain.heightFlight < 10 && plain.speed < 20 || plain.heightFlight < 0)
            && countLoop > 6) {
            cout << " You crashed. Game over\n";
            Sleep(2000);
            system("pause");
            int choice;
            cout << " You want to restart?\n 1 - yes, 2 - no ";
            cin >> choice;
            if (choice == 1) {
                restart();
                countLoop = 0;
            }
            else {
                break;
            }
        }
        if (plain.speed <= 300) {
            cout << " Speed isn't enough to fly\n";
            f = 1;
        }
        if (plain.speed > 600) {
            cout << " You fly too fast\n";
            f = 1;
            player.score -= stepScore;
        }
        if (plain.speed < 0) {
            cout << " You flight down\n";
            f = 1;
            player.score -= stepScore;
            plain.heightFlight -= stepHeight * 2;
        }
        if (plain.heightFlight < 30 && countLoop > 3) {
            cout << " Height isn't enough to fly, you may crash\n";
            f = 1;
            player.score -= stepScore;
        }
        if (plain.heightFlight > 200) {
            cout << " You fly too height, you must come down\n";
            f = 1;
            player.score -= stepScore;
        }
        if (f == 0) {
            player.score += stepScore * 10;
        }
        Sleep(100);
        system("cls");
    }
}

void Game::restart()
{
    player.score = 100;
    plain.heightFlight = 0;
    plain.speed = 0;
}
