#ifndef PLANE_H
#define PLANE_H
#include "point.hpp"
#include "Sky.hpp"


class Plane
{
protected:
    Point location; // for plane's location, implementing composition.
    int width, height; // Plane's dimension
    int dx, dy; // Plane's speed

    Sky* r; // points to room's object; aggregation
    
public:
Plane();
Plane (Point _location, int _w, int _h, int _dx, int _dy);
Plane (int _x, int _y, int _w, int _h, int _dx, int _dy);

Point getLocation() const;
int getX() const;
int getY() const;
int getWidth() const;
int getHeight() const;
int getRight() const;
int getBottom() const;
int getDx() const;
int getDy() const;

Sky* getSky () const;

void setX(int value);
void setY(int value);
void setWidth(int value);
void setHeight(int value);
void setSize(int _width, int _height);
void destroyed();
void setLocation(Point value);
void setLocation (int _x, int _y);
void setDx(int value);
void setDy(int value);
void setSky (Sky *q);

virtual void draw() const=0;
void undraw() const;

virtual void move(int dx=0, int dy=0);
};


#endif
