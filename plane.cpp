#include "point.hpp"
#include "Sky.hpp"
#include "plane.hpp"
#include <graphics.h>


Plane::Plane(){}
Plane::Plane(Point _location, int _w, int _h, int _dx, int _dy)
{
    location = _location;
    width = _w;
    height = _h;
    dx = _dx;
    dy = _dy;
}

Plane::Plane(int _x, int _y, int _w, int _h, int _dx, int _dy)
{
    location.setX(_x);
    location.setY(_y);
    width = _w;
    height = _h;
    dx = _dx;
    dy = _dy;
}

Point Plane::getLocation() const
{
    return location;
}

int Plane::getX() const
{
    return location.getX();
}

int Plane::getY() const
{
    return location.getY();
}

int Plane::getWidth() const
{
    return width;
}

int Plane::getHeight() const
{
    return height;
}


int Plane::getRight() const
{
    return location.getX() + width;
}

int Plane::getBottom() const
{
    return location.getY() + height;
}

int Plane::getDx() const
{
    return dx;
}

int Plane::getDy() const
{
    return dy;
}

Sky* Plane::getSky () const
{
    return r;
}

void Plane::setX(int value)
{
   location.setX(value);
}

void Plane::setY(int value)
{
    location.setY(value);
}

void Plane::setWidth(int value)
{
    width = value;
}

void Plane::setHeight(int value)
{
    height = value;
}

void Plane::setSize(int _width, int _height)
{
    width = _width;
    height = _height;
}

void Plane:: destroyed()
{
    location = 0;
    width = 0;
    height = 0;
    dx = 0;
    dy = 0;
}

void Plane::setLocation(Point value)
{
    location = value;
}

void Plane::setLocation (int _x, int _y)
{
    location.set(_x, _y);
}

void Plane::setDx(int value)
{
    dx = value;
}

void Plane::setDy(int value)
{
    dy = value;
}

void Plane::setSky (Sky *q)
{
    r = q;
}

/*void Plane::draw() const
{
   // setcolor(WHITE);
    //rectangle(location.getX(), location.getY(), location.getX()+width, location.getY()+height);
    readimagefile("plane2.jpg", location.getX(), location.getY(), location.getX()+width, location.getY()+height);
}*/

void Plane::undraw() const
{
    setcolor(BLACK);
    rectangle(location.getX(), location.getY(), location.getX()+width, location.getY()+ height);
}

void Plane::move(int dx, int dy)
{
    undraw();
    location.move(dx, dy);

    if(getRight() >= r->getRight())
    {
        location.setX(r->getRight() - width);
    }

    else if (getX() <= r->getX())
    {
        location.setX(r->getX());
    }

    if(getBottom()>= r->getBottom())
    {
        location.setY(r->getBottom() - height);
    }

    else if(getY() <= r->getY())
    {
        location.setY(r->getY() );
    }

    draw();
}