#include "bullet.hpp"
#include "point.hpp"
#include <graphics.h>

Bullet ::Bullet()
{
    location.set(0, 0);
    width = 3;
    height = 10;
    dx = 0;
    dy = -10;
    color = GREEN;
}

Bullet::Bullet(Point _location, int _w, int _h, int _dx, int _dy)
{
    location = _location;
    width = _w;
    height = _h;
    dx = _dx;
    dy = _dy;
}

Bullet ::Bullet(int _x, int _y, int _w, int _h, int _dx, int _dy)
{
    location.set(_x, _y);
    width = _w;
    height = _h;
    dx = _dx;
    dy = _dy;
}

Point Bullet ::getLocation() const
{
    return location;
}
int Bullet::getX() const
{
    return location.getX();
}
int Bullet::getY() const
{
    return location.getY();
}
int Bullet::getHeight() const
{
    return height;
}
int Bullet::getWidth() const
{
    return width;
}
int Bullet::getColor() const
{
    return color;
}
int Bullet ::getRight() const
{
    return location.getX() + width;
}
int Bullet::getBottom() const
{
    return location.getY() + height;
}
int Bullet::getDx() const
{
    return dx;
}
int Bullet::getDy() const
{
    return dy;
}

void Bullet::setLocation(Point value)
{
    location = value;
}
void Bullet::setLocation(int _x, int _y)
{
    location.set(_x, _y);
}
void Bullet ::setX(int value)
{
    location.setX(value);
}
void Bullet ::setY(int value)
{
    location.setY(value);
}
void Bullet ::setHeight(int value)
{
    height = value;
}
void Bullet ::setWidth(int value)
{
    width = value;
}
void Bullet ::setColor(int value)
{
    color = value;
}
void Bullet ::setSize(int _width, int _height)
{
    width = _width;
    height = _height;
}
void Bullet ::setDx(int value)
{
    dx = value;
}
void Bullet ::setDy(int value)
{
    dy = value;
}

void Bullet ::destroyed()
{
    location = 0;
    width = 0;
    height = 0;
    color = 0;
    dx = 0;
    dy = 0;
}

void Bullet::setEnemy(Enemy e[])
{
    for (int i = 0; i < 50; i++)
    {

        enemy[i] = &e[i];
    }
}
void Bullet::draw() const
{
    setfillstyle(SOLID_FILL, color);
    bar(location.getX(), location.getY(), location.getX() + width, location.getY() + height);
}
void Bullet ::undraw() const
{
    setfillstyle(SOLID_FILL, BLACK);
    bar(location.getX(), location.getY(), location.getX() + width + 1, location.getY() + height + 1);
}

void Bullet::move()
{
    undraw();
    location.move(dx, dy);
    collision();
    draw();
}

void Bullet::collision()
{
    for (int i = 0; i < 50; i++)
    {
        if (location.getX() >= enemy[i]->getX() && location.getX() <= enemy[i]->getRight() && location.getY() <= enemy[i]->getBottom() && location.getY() >= enemy[i]->getY())
        {
            destroyed();
            enemy[i]->destroyed();
        }
    }
}