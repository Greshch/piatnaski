#include <iostream>
#include <Windows.h>
#include "view.h"
#include "global.h"
#include "logic.h"

void DrawBoard()
{
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLLS; j++)
		{
			COORD tmp{ LEFT_BOARD + j * SCALE_X, UP_BOARD + i * SCALE_Y };
			// Draw Nums
			SetConsoleCursorPosition(handle, tmp);
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | DARKGREEN);
			if (board[i][j])
			{
				//SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | BACKGROUND_BLUE);
				std::cout << board[i][j];
			}
			else
			{
				std::cout << "  ";
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

void PrintActiveNode()
{
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLLS; j++)
		{
			std::cout << IsNodeActive(i, j) << " ";
		}
		std::cout << std::endl;
	}
}

void DrawResult(bool win)
{
	if (!win)
	{
		SetConsoleCursorPosition(handle, end_line);
		SetConsoleTextAttribute(handle, RED);
		std::cout << "...EXIT...\n";
		return;
	}
	SetConsoleCursorPosition(handle, end_line);
	SetConsoleTextAttribute(handle, YELLOW);
	std::cout << "...Well done!!\n";
}
