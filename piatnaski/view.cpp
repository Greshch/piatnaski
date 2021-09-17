#include <iostream>
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
			SetConsoleCursorPosition(handle, tmp);
			SetConsoleTextAttribute(handle, DARKGREEN);
			if (board[i][j])
			{
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
