#include <iostream>
#include <conio.h>
#include <utility>
#include <vector>
#include "global.h"

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cci;

int board [ROWS][COLLS] { 0 };
COORD head {COLLS - 1, ROWS - 1};
std::vector < std::pair <COORD, int> > activeNode;



int ReadKey()
{
	int key = 0;
	if (_kbhit())
	{
		key = _getch();
		if (key == 224)
		{
			key = _getch();
		}
	}
	return key;
}

void InitApp()
{
	cci.bVisible = false;
	cci.dwSize = 200;
	SetConsoleCursorInfo(handle, &cci);
}

void CloseApp()
{
	system("cls");
	SetConsoleCursorPosition(handle, { 0, 0 });
	SetConsoleTextAttribute(handle, WHITE);
	cci.bVisible = true;
	cci.dwSize = 10;
	SetConsoleCursorInfo(handle, &cci);
}
