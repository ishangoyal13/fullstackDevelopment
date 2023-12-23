#ifndef MYGRAPHICS_H
#define MYGRAPHICS_H
#include <windows.h>


//To compile your program with graphics.cpp you need to include the gdi32 library
//compile it using: g++ -o myprog.exe myprog.cpp graphics.cpp -lgdi32
// for visual studio if you get linker errors then goto properties->linker->input and add the library 
//gdi32.lib or gdi64.lib depending on your system.  Normally this libaray is added by default so you may be able 
//to compile the code.


//set the color of a pixel at (x,y) to colorVal
//create a color using different values of red (R), green (G) and blue (B)
//for example c is a color value, whose type is COLORREF: COLORREF c = RGB(30,300,20);
//usage exammple: mySetPixel(200,200,RGB(230,0,0));
void mySetPixel(int x,int y, COLORREF colorVal);


//draw a line from (x1,y1) to (x2,y2) using lineColor
//create a color using different values of red (R), green (G) and blue (B)
//for example c is a color value, whose type is COLORREF: COLORREF c = RGB(30,300,20);
//usage example: myLine(0,0,300,400,RGB(200,0,0));
void myLine(int x1, int y1, int x2, int y2, COLORREF lineColor);

//draw a rectangle with top corner (x1,y1) and bottom corner(x2,y2) with outline lineColor
//and fillColor
//create a color using different values of red (R), green (G) and blue (B)
//for example c is a color value, whose type is COLORREF: COLORREF c = RGB(30,300,20);
//usage example: 	myRect(300,300,350,350,RGB(100,0,0),RGB(0,0,240));
void myRect(int x1, int y1, int x2, int y2,COLORREF lineColor,COLORREF fillColor);

//draw an ellipse within a rectangle with top corner (x1,y1) and bottom corner(x2,y2)
//create a color using different values of red (R), green (G) and blue (B)
//for example c is a color value, whose type is COLORREF: COLORREF c = RGB(30,300,20);
//usage example: 	myEllipse(100,50,180,200,RGB(100,0,0),RGB(0,0,240));
void myEllipse(int x1, int y1, int x2, int y2,COLORREF colorForeground,COLORREF colorBackground)
;

//write a string at position (x,y) in lineColor and background color as fillColor
//create a color using different values of red (R), green (G) and blue (B)
//for example c is a color value, whose type is COLORREF: COLORREF c = RGB(30,300,20);
//usage example: 	myDrawText(100,200,40,"Good day",RGB(200,0,200),RGB(3,200,3));
void myDrawText(int x,int y,int ht,char str [],COLORREF lineColor,COLORREF fillColor);


//write a string at position (x,y) in lineColor and background color as fillColor
//the font size will be determined by the ht parameter
//create a color using different values of red (R), green (G) and blue (B)
//for example c is a color value, whose type is COLORREF: COLORREF c = RGB(30,300,20);
//usage example: 	myDrawText(100,200,40,"Good day",RGB(200,0,200),RGB(3,200,3));
void myDrawTextWithFont(int x,int y,int ht,char str[],COLORREF lineColor,COLORREF fillColor);

#endif


