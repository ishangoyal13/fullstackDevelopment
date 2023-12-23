#define _WIN32_WINNT 0x0500 

#include <windows.h> 
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "string"
#include "mygraohics.h"
void myLine(int x1, int y1, int x2, int y2,COLORREF lineColor)
{

	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
	HPEN pen =CreatePen(PS_SOLID,2,lineColor); //2 is the width of the pen
    SelectObject(device_context,pen);
	MoveToEx(device_context,x1,y1,NULL);
    LineTo(device_context,x2, y2);
	DeleteObject(pen);

	ReleaseDC(console_handle, device_context);  
}
void myRect(int x1, int y1, int x2, int y2,COLORREF lineColor,COLORREF fillColor)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,2,lineColor); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(fillColor);
	SelectObject(device_context,brush);
	
	Rectangle(device_context,x1,y1,x2,y2);
	DeleteObject(pen);
	DeleteObject(brush);
	ReleaseDC(console_handle, device_context); 
}
void myEllipse(int x1, int y1, int x2, int y2,COLORREF lineColor,COLORREF fillColor)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,2,lineColor); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(fillColor);
	SelectObject(device_context,brush);
	Ellipse(device_context,x1,y1,x2,y2);
	DeleteObject(pen);
	DeleteObject(brush);	
	ReleaseDC(console_handle, device_context);

}

void myDrawText(int x,int y,int ht,char str[],COLORREF lineColor,COLORREF fillColor)
{
	WCHAR wstr[200]={};
	for (int i=0;i<200&&str[i];++i)
		wstr[i] = str[i];

	RECT rects;
	rects.left = x;
	rects.top = y;
	rects.right = x+ht;
	rects.bottom = y+ht;//(x,y,x+ht,y+ht);
	
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

	SetTextColor(device_context,lineColor);
	SetBkColor(device_context,fillColor);
	LPCSTR temp;
	temp=str;
	DrawText(device_context, temp, -1, &rects, DT_TOP | DT_NOCLIP);

	ReleaseDC(console_handle, device_context);
  
}

void myDrawTextWithFont(int x,int y,int ht,char  str[],COLORREF lineColor,COLORREF fillColor)
{
	
	WCHAR wstr[200]={};
	for (int i=0;i<200&&str[i];++i)
		wstr[i] = str[i];

	RECT rects;
	HFONT hFont;
	rects.left = x;
	rects.top = y;
	rects.right = x+ht;
	rects.bottom = y+ht;//(x,y,x+ht,y+ht);
	
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);
	hFont = CreateFont(ht,0,0,0,FW_DONTCARE,FALSE,TRUE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
			            CLIP_DEFAULT_PRECIS,1, VARIABLE_PITCH,TEXT("Impact"));
    SelectObject(device_context, hFont);

	SetTextColor(device_context,lineColor);
	SetBkColor(device_context,fillColor);
	

	LPCSTR temp;
	temp=str;
	DrawText(device_context,temp,-1,&rects,DT_TOP|DT_NOCLIP);
	DeleteObject(hFont);   
	ReleaseDC(console_handle, device_context);
  
}

void mySetPixel(int x,int y,COLORREF colorVal)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);
	
	SetPixel(device_context,x,y,colorVal);
	ReleaseDC(console_handle,device_context);
}



