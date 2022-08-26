//Created with devC++ 5.11

#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>

using namespace std;

//variables
char key;
int programStop = false;


string number;
string name;
string lastName;
string email;

fstream file;


//Extra functions

//this function will let us put the text where we want
void coordxy(int x, int y){
	
	HANDLE console;
	COORD position;
	
	position.X = x;
	position.Y = y;
	
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(console,position);
	
}

//this function will adjust the window to the size we want.
bool windowAdjust(int w, int h){
	
	_COORD Coord;
	Coord.X = w;
	Coord.Y = h;
	
	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Right = w - 1;
	Rect.Bottom = h - 1;
	
	//this is to get the console identifier
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	
	//Adjust the buffer to the new size
	SetConsoleScreenBufferSize(Console, Coord);
	
	//it changes the console's size
	SetConsoleWindowInfo(Console, TRUE, &Rect);
	
	return TRUE;
	
}

//this function will hide the pointer
void hideCursor(){
	
	HANDLE console;
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 1;
	cursor.bVisible = false;
	SetConsoleCursorInfo(console, &cursor);
	
}

//this function will draw the main panel of the app
void graphicInterface(){
	
	//horizontal lines
	for(int x = 1; x<= 118; x++){
		
		coordxy(x, 0);   printf("%c", 205);
		coordxy(x,29);   printf("%c", 205);
	}
	
	//vertical lines
	for(int y = 1; y <= 29; y++){
		
		coordxy(1,y);   printf("%c",186);
		coordxy(118,y); printf("%c",186);
	}
	
	//coorners
	coordxy(1,0);    printf("%c", 201);
	coordxy(1,29);   printf("%c", 200);
	coordxy(118,0);  printf("%c", 187);
	coordxy(118,29); printf("%c", 188);
	
}


//function to create a new contact
void newContactScreen(){
	
	system("cls"); //cleaning screen
	graphicInterface(); // calling the panel
	
	char save; // this is to confirm the data we want to save
	
	//data entry
	coordxy(23,3);  cout << "**CONTACT INFORMATION**";
	coordxy(43,7);  cout << "TELEPHONE NUMBER:";
	coordxy(43,9);  cout << "NAME:";
	coordxy(43,11); cout << "LAST NAME:";
	coordxy(43,13); cout << "E-MAIL ADDRESS:";
	
	coordxy(34,27); cout << "Instructions: Write data for each field and hit ENTER";
	
	//We receive the data from the keyboard
	coordxy(64,7);  cin >> number;
	coordxy(64,9);  cin >> name;
	coordxy(64,11); cin >> lastName;
	coordxy(64,13); cin >> email;
	
	coordxy(35,15); cout <<"------------------------------------------------";
	coordxy(45,17); cout << "DATA COMPLETED, WANT TO SAVE?";
	coordxy(47,19); cout << "a = yes, Any other key = no";
	coordxy(60,20); save = getch();
	
	
	//conditionals
	if(save == 'a'){
		
		//code to save the data
		file.open("data.txt", ios::app); //creating the file
		file << number << " " << name << " " << lastName << " " << email << endl; //sending the data
		file.close(); // we close the file
		
		//showing a message and emulating the blink effect
		hideCursor();
		coordxy(55,21); cout << "DATA SAVED";
		Sleep(500);
		coordxy(55,21); cout << "          ";
		Sleep(500);
		coordxy(55,21); cout << "DATA SAVED";
		Sleep(500);
		coordxy(55,21); cout << "          ";
		Sleep(500);
		coordxy(55,21); cout << "DATA SAVED";
		Sleep(500);		
		
	}
	
	
	
}




//main function
int main(){
	
	
	while(programStop != true){
		
		
		//cleaning whatever was written before
		system("cls");
		
		//colors and text
		system("COLOR F0"); // we use a white background and black text
		
		windowAdjust(120, 30); // we set the screen size
		graphicInterface();
		
		//Menu to be displayed
		coordxy(23,3);  cout << "**SAVING DATA WITH C++**";
		coordxy(42,10); cout << "MENU";
		coordxy(42,11); cout << "---------------------------";
		coordxy(48,13); cout << "a: Create a new contact";
		coordxy(48,14); cout << "b: Exit to Windows";
		
		coordxy(30,27); cout << "Instruccions: Choose one option using the letters 'a' or 'b'";
		coordxy(48,17); cout << "->";
		coordxy(52,17); key = getch(); // we receive the option from the keyboard
		
		
		//conditionals
		
		if(key == 'a'){
			
			
			newContactScreen();
			system("cls");
			
		} else if(key == 'b'){
			
			programStop = true;
			coordxy(38,24); cout << "[SHUTTING DOWN THE PROGRAM . HIT ANY KEY TO EXIT]";
			getch();
			
		}else{
			
			coordxy(48,19); cout << "[NO VALID OPTION!!!!]";
			getch();
			
			
		}
		
	}
	
	
	
	return 0;
}