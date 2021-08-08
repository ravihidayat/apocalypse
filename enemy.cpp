#include <graphics.h>
#include "enemy.hpp"
#include "point.hpp"
#include "plane.hpp"

Enemy::Enemy(){}
Enemy::Enemy(Point location=0, int width=50, int height=50, int dx=0, int dy=20) : Plane(location, width, height, dx, dy)
{}

Enemy::Enemy(int x = 0, int y = 0, int width = 0, int height = 0, int dx = 0, int dy = 0) : Plane(x, y, width, height, dx, dy)
{
}

void Enemy::draw() const
{
  setcolor(DARKGRAY);
  rectangle(location.getX(), location.getY(), location.getX() + width, location.getY() + height);
  //readimagefile("obj.jpg", x, y, x + width, y + length);
}

void Enemy::destroyed()
{
  undraw();
  location = 0;
  width = 0;
  height = 0;
  dx = 0;
  dy = 0;
  setcolor(BLACK);
}

void Enemy::move()
{
  undraw();
  
  
  location.move(dx, dy);

  draw();
}