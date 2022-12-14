#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;
bool window_adjust(int width,int height){
    _COORD Coord;
    Coord.X=width;
    Coord.Y=height;

    _SMALL_RECT Rect;
    Rect.Top=0;
    Rect.Left=0;
    Rect.Bottom=height-1;
    Rect.Right=width-1;
    
    //this is to get the console identifier
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	
	//Adjust the buffer to the new size
	SetConsoleScreenBufferSize(Console, Coord);
	
	//it changes the console's size
	SetConsoleWindowInfo(Console, TRUE, &Rect);
	
	return TRUE;

}
void coordxy(int x,int y){
    HANDLE console;
    COORD position;

    position.X=x;
    position.Y=y;

    console =GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(console,position);
}
void graphic_interface(){

    for(int i=1;i<=148;i++){
        coordxy(i,0); printf("%c",205);
        coordxy(i,49); printf("%c",205);
    }
    for(int i=1;i<=49;i++){
    	coordxy(1,i); printf("%c",186);
    	coordxy(148,i); printf("%c",186);
	}

    coordxy(1,0); printf("%c",201);
    coordxy(1,29); printf("%c",200);
    coordxy(148,0); printf("%c",187);
    coordxy(148,29); printf("%c",188);
}
void hideCursor(){
    HANDLE console;
    console=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize=1;
    cursor.bVisible =false;
    SetConsoleCursorInfo(console,&cursor);
}
void welcome(){
    coordxy(70,12); cout<<"Hotel Grand Food";
    coordxy(70,22);  cout<<"A restaurant management tool";
    hideCursor();
    coordxy(75,15);  cout<<"WELCOME";
    Sleep(500);
    coordxy(75,15);  cout<<"       ";
    Sleep(500);
    coordxy(75,15);  cout<<"WELCOME";
    Sleep(500);
    coordxy(75,15);  cout<<"       ";
    Sleep(500);
    coordxy(75,15);  cout<<"WELCOME";
    
}
