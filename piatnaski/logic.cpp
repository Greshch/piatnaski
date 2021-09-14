#include "logic.h"
#include "global.h"

void InitBoard()
{
	board[head.Y][head.X] = 1;
}

void UpdateHead(int key)
{
	board[head.Y][head.X] = 0;
	switch (key)
	{
	case LEFT:
		if (head.X > 0)	head.X--;
		break;

	case UP:
		if (head.Y > 0)	head.Y--;
		break;

	case RIGHT:
		if (head.X < COLLS - 1)	head.X++;
		break;

	case DOWN:
		if (head.Y < ROWS - 1)	head.Y++;
		break;

	default:
		break;
	}
}

void UpdateBoard()
{
	board[head.Y][head.X] = 1;
}
