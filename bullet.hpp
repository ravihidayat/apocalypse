#ifndef BULLET_H
#define BULLET_H
#include "point.hpp"
#include "enemy.hpp"

class Bullet
{
private:
    Point location;
    int width, height;
    int color;
    int dx, dy;

    Enemy *enemy[50];

public:
    Bullet();
    Bullet(Point _location, int _w, int _h, int _dx, int _dy);
    Bullet(int _x, int _y, int _w, int _h, int _dx, int _dy);

    Point getLocation() const;
    int getX() const;
    int getY() const;
    int getHeight() const;
    int getWidth() const;
    int getColor() const;
    int getRight() const;
    int getBottom() const;
    int getDx() const;
    int getDy() const;

    void setLocation(Point value);
    void setLocation(int _x, int _y);
    void setX(int value);
    void setY(int value);
    void setHeight(int value);
    void setWidth(int value);
    void setColor(int value);
    void setSize(int _width, int _height);
    void setDx(int value);
    void setDy(int value);
    void set(int _x, int _y);
    void destroyed();
    void setEnemy(Enemy e[]);

    void draw() const;
    void undraw() const;

    void collision();

    void move();
};

#endif