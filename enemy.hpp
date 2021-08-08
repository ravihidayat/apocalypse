#ifndef ENEMY_H
#define ENEMY_H
#include "point.hpp"
#include "plane.hpp"

class Enemy : public Plane
{
public:
  Enemy();
  Enemy(Point location, int width, int height, int dx, int dy);
  Enemy(int x, int y, int width, int height, int dx, int dy);

  void draw() const;
  void destroyed();
  void move();
};

#endif