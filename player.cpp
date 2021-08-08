#include "point.hpp"
#include "player.hpp"
#include "plane.hpp"
#include "enemy.hpp"
#include "Sky.hpp"
#include <graphics.h>
#include <cstring>
#include <string>

using namespace std;

Player::Player() {}
Player::Player(Point location = 0, int width = 0, int height = 0, int dx = 0, int dy = 0, int _life = 0) : Plane(location, width, height, dx, dy), life(_life)
{
}

Player ::Player(int x = 0, int y = 0, int width = 0, int height = 0, int dx = 0, int dy = 0, int _life = 0) : Plane(x, y, width, height, dx, dy), life(_life)
{
}

int Player::getLife()
{
    return life;
}


void Player::setLife(int _life)
{
    life = _life;
}

void Player::convertToChar()
{
    string s = to_string(life);
    lifeChar = const_cast<char*>(s.c_str());
}

void Player::displayLife()
{
    outtextxy(20, 20, lifeChar);
}

void Player::draw() const
{
    setcolor(GREEN);
    rectangle(location.getX(), location.getY(), location.getX() + width, location.getY() + height);
}

void Player ::setEnemy(Enemy e[])
{
    for (int i = 0; i < 50; i++)
    {
        enemy[i] = &e[i];
    }
}

void Player ::move(int dx, int dy)
{
    undraw();
    location.move(dx, dy);

    if (getRight() >= r->getRight())
    {
        location.setX(r->getRight() - width);
    }

    else if (getX() <= r->getX())
    {
        location.setX(r->getX());
    }

    if (getBottom() >= r->getBottom())
    {
        location.setY(r->getBottom() - height);
    }

    else if (getY() <= r->getY())
    {
        location.setY(r->getY());
    }
    collision();
    draw();
}

void Player::destroyed()
{
    undraw();
    location.set(0, 0);
    width = 0;
    height = 0;
    dx = 0;
    dy = 0;
    setcolor(BLACK);
}

void Player ::collision()
{
    for (int i = 0; i < 50; i++)
    {
        if (location.getX() >= enemy[i]->getX() && location.getX() <= enemy[i]->getRight() && location.getY() <= enemy[i]->getBottom() && location.getY() >= enemy[i]->getY())
        {
            destroyed();
            enemy[i]->destroyed();
            int j;
            
            for (j =i; j < 50; j++)
            {
                enemy[j]->destroyed();
            }
            readimagefile("10.jpg", 0, 0, getmaxwidth(), getmaxheight());
        }
    }
}
