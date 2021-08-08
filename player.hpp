#ifndef PLAYER_H
#define PLAYER_H
#include <cstring>
#include <string>
#include "point.hpp"
#include "Sky.hpp"
#include "enemy.hpp"
#include "plane.hpp"


class Player : public Plane
{
private:
    Enemy* enemy[50];
    int life;
    char *lifeChar;
public:
    Player();
    Player (Point location  , int width, int height, int dx, int dy, int _life);
    Player (int x, int y, int width, int height, int dx, int dy, int _life);

    int getLife();

    void setLife(int _life);
    void setEnemy(Enemy e[]);

    void convertToChar();

    void displayLife();
    void draw() const;
    void destroyed();

    void move(int dx, int dy);
    void collision ();
};

#endif