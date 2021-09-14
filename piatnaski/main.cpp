#include <iostream>
#include "global.h"
#include "view.h"
#include "logic.h"


int main()
{
	using namespace std;
	InitApp();
	InitBoard();
	while (true)
	{
		int key = ReadKey();
		if (key == EXIT)	break;
		DrawBoard();
		Sleep(100);
		UpdateHead(key);
		UpdateBoard();
	}
	
	CloseApp();
	//PrintBoard();
	return 0;
}