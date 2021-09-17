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
		DrawBoard();
		int key = ReadKey();
		if (key == EXIT)	break;
		UpdateBoard(key);
		Sleep(100);
	}
	
	CloseApp();
	//PrintActiveNode();
	//PrintBoard();
	return 0;
}