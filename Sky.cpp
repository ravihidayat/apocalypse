#include "Sky.hpp"
#include <graphics.h>


Sky::Sky(int _x, int _y, int _width, int _height, int _color)
{
	set(_x, _y, _width, _height, _color);
}

int Sky::getX() const { return x; }
int Sky::getY() const { return y; }
int Sky::getWidth() const { return width; }
int Sky::getHeight() const { return height; }
int Sky::getColor() const { return color; }
int Sky::getRight() const { return x + width; }
int Sky::getBottom() const { return y + height; }

void Sky::setX(int value) { x = value; }
void Sky::setY(int value) { y = value; }
void Sky::setWidth(int value) { width = value; }
void Sky::setHeight(int value) { height = value; }
void Sky::setSize(int _width, int _height)
{
	width = _width;
	height = _height;
}
void Sky::setColor(int value) { color = value; }
void Sky::set(int _x, int _y, int _width, int _height, int _color)
{
	x = _x;
	y = _y;
	width = _width;
	height = _height;
	color = _color;
}

void Sky::draw() const
{
	setfillstyle(SOLID_FILL,color);
	bar(x,y,x+width, y+height);
}
