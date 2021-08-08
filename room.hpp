#ifndef ROOM_H
#define ROOM_H

class Room
{
private:
	int x, y;           
	int width, height;  
	int color;          
public:
	Room(int _x=0, int _y=0, int _width=0, int _height=0, int _color=0);

	int getX() const;   
	int getY() const;   
	int getWidth() const;
	int getHeight() const;
	int getColor() const;
	int getRight() const;
	int getBottom() const;

	void setX(int value);
	void setY(int value);
	void setWidth(int value);
	void setHeight(int value);
	void setSize(int _width, int _height);
	void setColor(int value);
	void set(int _x, int _y, int _width, int _height, int _color);

	void draw() const;
};

#endif