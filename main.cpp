#include <graphics.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include "plane.hpp"
#include "Sky.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "bullet.hpp"

#define COUNT 50
using namespace std;

int main()
{
    int num = 0;
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();

    initwindow(screenWidth, screenHeight, "Apocalypse");

    unsigned seed = time(0);
    srand(seed);

    Sky r1(0, 0, screenWidth, screenHeight, BLACK);
    Player p1(100, 700, 50, 50, 0, 0, 3);
    Enemy enemies[COUNT];
    Bullet bul[1000];

    p1.displayLife();

    for (int i = 0; i < COUNT; i++)
    {
        enemies[i].setX((rand() % (screenWidth - 20 + 1)) + 7);
        enemies[i].setY(-20 - i * 80);
        enemies[i].setWidth(50);
        enemies[i].setHeight(50);
        enemies[i].setDx(0);
        enemies[i].setDy(5);
    }

    for (int i = 0; i < 1000; i++)
    {

        bul[i].setEnemy(enemies);
    }

    p1.setEnemy(enemies);

    p1.setSky(&r1);

    r1.draw();

    for (int i = 0; i < COUNT; i++)
    {
        enemies[i].draw();
    }

    p1.draw();

    char c;
    while (true)
    {

        delay(20);
        p1.collision();
        for (int i = 0; i < COUNT; i++)
        {
            enemies[i].move();
        }

        c = 0;

        if (kbhit())
        {
            c = getch();
            c = toupper(c);
            if (c == 27)
                break;
            if (c == 0)
                c = getch();
        }

        switch (c)
        {
        case KEY_LEFT:

            p1.move(-20, 0);
            break;
        case KEY_RIGHT:

            p1.move(20, 0);
            break;
        case KEY_UP:

            p1.move(0, -20);
            break;
        case KEY_DOWN:

            p1.move(0, 20);
            break;

        case 32:
            bul[num].setLocation((p1.getX() + p1.getWidth() / 2) - 1, p1.getY() - bul[num].getHeight() + 1);
            bul[num].draw();
            num += 1;
            break;
        }

        for (int i = 0; i < num; i++)
        {
            bul[i].move();
        }
        p1.collision();
        if (enemies[COUNT - 1].getY() > getmaxheight())
        {
            break;
        }
    }
    
    
    readimagefile("you.jpg", 0, 0, screenWidth, screenHeight);
    system("pause");
    return 0;
}