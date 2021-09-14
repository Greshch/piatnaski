#include <iostream>
#include "view.h"
#include "global.h"

void DrawBoard()
{
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLLS; j++)
		{
			COORD tmp{ LEFT_BOARD + j * SCALE_X, UP_BOARD + i * SCALE_Y };
			if (board[i][j] == 1)
			{
				SetConsoleCursorPosition(handle, tmp);
				SetConsoleTextAttribute(handle, RED);
				std::cout << (char)1;
			}
			else
			{
				SetConsoleCursorPosition(handle, tmp);
				SetConsoleTextAttribute(handle, RED);
				std::cout << ' ';
			}
		}
	}
}

void PrintBoard()
{
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLLS; j++)
		{
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
