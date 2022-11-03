#include "TXLib.h"

void drawFon()
{
    txSetColor (TX_BLUE);
    txSetFillColor (TX_BLUE);
    txRectangle (0, 0, 800, 450);
    txSetColor (TX_GREEN);
    txSetFillColor (TX_GREEN);
    txRectangle (0, 450, 800, 600);
}

void drawDom(int x_dver, int y_dver)
{
    //x_dver = 350
    //y_dver = 350
    txSetColor (TX_WHITE);
    txSetFillColor (TX_BROWN);
    txRectangle (100, 300, 400, 500);
    POINT kr[3] = {{100, 300}, {250, 200}, {400, 300}};
    txPolygon (kr, 3);
    txSetColor (TX_WHITE);
    txSetFillColor (TX_GRAY);
    txRectangle(260, 350, 350, 500);
    txSetFillColor (RGB(155, 0, 155));
    POINT dver[4] = {{260, 350}, {x_dver, y_dver}, {x_dver, y_dver+500-350}, {260, 500}};
    txPolygon (dver, 4);
}

void drawSun(int x)
{
    txSetColor (TX_WHITE);
    txSetFillColor (TX_YELLOW);
    txCircle(x, 100, 50);
}

void drawCloud(int x)
{
    txSetColor (TX_WHITE);
    txSetFillColor (RGB ( 175, 241, 238));
    txEllipse (x,     60, x+190, 140);
    txEllipse (x+120, 50, x+300, 160);
    txEllipse (x+230, 50, x+370, 140);
}

void drawMan(int x, int y, double rasm)
{
    txSetColor (TX_WHITE);
    txSetFillColor (TX_WHITE);
    txCircle(x, y, 20*rasm);
    txLine(x, y+10*rasm, x,         y+80*rasm);
    txLine(x, y+20*rasm, x+30*rasm, y+50*rasm);
    txLine(x, y+20*rasm, x-30*rasm, y+50*rasm);
    txLine(x, y+80*rasm, x+30*rasm, y+110*rasm);
    txLine(x, y+80*rasm, x-30*rasm, y+110*rasm);
}

void drawTree(int x, int y)
{
    txSetColor (TX_BLACK);
    txSetFillColor (TX_BROWN);
    txRectangle(x+690-690, y+370-370, x+710-690, y+550-370);
    txSetColor (TX_GREEN);
    txSetFillColor (TX_GREEN);
    txEllipse (x+650-690, y+300-370, x+750-690, y+450-370);
    txEllipse (x+670-690, y+160-370, x+730-690, y+350-370);
}

void drawCar(int x0, int y0, float a)
{
    int r  = 20;
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
    int l = 150;

    txSetColor (TX_WHITE, 2);
    txSetFillColor (TX_BLACK);
    txCircle (x0, y0, r);
    txCircle (x0+l, y0, r);

    x1 = x0+r*cos(a);
    y1 = y0+r*sin(a);
    x2 = x0+r*cos(a+2.1);
    y2 = y0+r*sin(a+2.1);
    x3 = x0+r*cos(a+4.2);
    y3 = y0+r*sin(a+4.2);

    txLine    (x0, y0, x1, y1);
    txLine    (x0, y0, x2, y2);
    txLine    (x0, y0, x3, y3);
    txLine    (x0+l, y0, x1+l, y1);
    txLine    (x0+l, y0, x2+l, y2);
    txLine    (x0+l, y0, x3+l, y3);

}

int main()
{
    txCreateWindow (800, 600);

    int xSun = 100;
    int xCloud = 420;
    int xMan = 590;
    int yMan = 430;
    double rasmMan = 1;
    int xDver = 350;
    int yDver = 350;
    int xTree1 = 690;
    int yTree = 270;
    int xTree2 = 590;
    int xTree = 50;
    int xCar = 500;
    int yCar = 450;
    float aCar = 0;



    while(xSun < 850)
    {
        drawFon();
        drawSun(xSun);
        drawCloud(xCloud);
        drawDom(xDver, yDver);
        drawTree(xTree1, yTree);
        drawTree(xTree2, yTree);
        drawCar(xCar, yCar, aCar);
        drawMan(xMan, yMan, rasmMan);

        xSun +=5;
        xCloud = xCloud - 5;
        xMan = xMan - 5;
        txSleep(10);
    }

    while(xMan < 350)
    {
        drawFon();
        drawSun(xSun);
        drawCloud(xCloud);
        drawDom(xDver, yDver);
        drawTree(xTree1, yTree);
        drawTree(xTree2, yTree);
        drawCar(xCar, yCar, aCar);
        drawMan(xMan, yMan, rasmMan);


        xMan = xMan + 5;
        txSleep(10);
    }

    while(xDver > 260)
    {
        drawFon();
        drawSun(xSun);
        drawCloud(xCloud);
        drawDom(xDver, yDver);
        drawTree(xTree1, yTree);
        drawTree(xTree2, yTree);
        drawCar(xCar, yCar, aCar);
        drawMan(xMan, yMan, rasmMan);


        xDver = xDver - 1;
        yDver = yDver + 1;
        txSleep(10);
    }

    while(xMan > 305)
    {
        drawFon();
        drawSun(xSun);
        drawCloud(xCloud);
        drawDom(xDver, yDver);
        drawTree(xTree1, yTree);
        drawTree(xTree2, yTree);
        drawCar(xCar, yCar, aCar);
        drawMan(xMan, yMan, rasmMan);


        xMan = xMan - 5;
        txSleep(10);
    }

    while(rasmMan > 0.5)
    {
        drawFon();
        drawSun(xSun);
        drawCloud(xCloud);
        drawDom(xDver, yDver);
        drawTree(xTree1, yTree);
        drawTree(xTree2, yTree);
        drawCar(xCar, yCar, aCar);
        drawMan(xMan, yMan, rasmMan);


        rasmMan = rasmMan-0.05;
        txSleep(10);
    }

    while(xDver < 350)
    {
        drawFon();
        drawSun(xSun);
        drawCloud(xCloud);
        drawTree(xTree1, yTree);
        drawTree(xTree2, yTree);
        drawCar(xCar, yCar, aCar);
        drawMan(xMan, yMan, rasmMan);
        drawDom(xDver, yDver);


        xDver = xDver + 1;
        yDver = yDver - 1;
        xCar+=5;
        aCar+=0.1;
        txSleep(10);
    }


    xCar = -150;
    while(xCar< 900)
    {
        drawFon();

        for(int x=100; x<900; x+=150)
        {
            drawTree(x, yTree);
        }
        drawCar(xCar, yCar, aCar);
        xCar+=5;
        aCar+=0.1;
        txSleep(10);
    }


txTextCursor (false);
return 0;
}

