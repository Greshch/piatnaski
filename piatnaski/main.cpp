#include <iostream>
#include "global.h"
#include "view.h"
#include "logic.h"


int main()
{
	srand(time(0));
	InitApp();
	InitBoard();
	ShuffleBoard();

	bool win = false;
	while (true)
	{
		win = IsWin();
		DrawBoard();
		int key = ReadKey();
		if (key == EXIT || win)	break;
		UpdateBoard(key);
		Sleep(100);
	}
	
	DrawResult(win);
	Sleep(2000);
	CloseApp();
	return 0;
}