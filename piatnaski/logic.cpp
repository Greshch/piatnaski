#include <iostream>
#include <algorithm>
#include "logic.h"
#include "global.h"

void InitBoard()
{
	/*board[head.Y][head.X] = 1;*/
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLLS; j++)
		{
			if (i == ROWS - 1 && j == COLLS - 1)	continue;
			board[i][j] = i * COLLS + j + 1;
		}
	}
}

void UpdateHead(int key)
{
	/*board[head.Y][head.X] = 0;*/
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
	board[head.Y][head.X] = 0;
}

void UpdateBoard(int key)
{
	static bool first_call = true;
	if (!IsDirrectKey(key) && !first_call)	return;

	UpdateHead(key);
	GetActiveNode();
	first_call = false;
}

void GetActiveNode()
{
	activeNode.clear();
	auto x = head.X;
	auto y = head.Y;
	//LEFT 
	if (x > 0)	activeNode.push_back({ {(short)(x - 1), y }, RIGHT });
	//UP 
	if (y > 0)	activeNode.push_back({ {x, (short)(y - 1) }, DOWN });
	//RIGHT 
	if (x < COLLS - 1)	activeNode.push_back({ {(short)(x + 1), y }, LEFT });
	//DOWN
	if (y < ROWS - 1)	activeNode.push_back({ {x, (short)(y + 1) }, UP });
}

bool IsNodeActive(int row, int col)
{
	using namespace std;
	COORD tmp{ col, row };
	return activeNode.end() != find_if(activeNode.begin(), activeNode.end(),
		[tmp](auto const& e) {
			return tmp.X == e.first.X 
				   &&
				   tmp.Y == e.first.Y;
		}
	);
}

bool IsWin()
{
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLLS; j++)
		{
			if (i == ROWS - 1 && j == COLLS - 1)
			{
				if (board[i][j] != 0)	return false;
			}
			else 
			{
				if (board[i][j] != i * COLLS + j + 1)	return false;
			}
		}
	}
	return true;
}

bool IsDirrectKey(int key)
{
	return key == LEFT
					||
		   key == UP
					||
		   key == RIGHT
					||
		   key == DOWN;
}

It_Node GetNodeByDirect(int dir)
{
	using namespace std;
	return find_if(activeNode.begin(), activeNode.end(),
		[dir](auto const& e) {
			return e.second == dir;
		}
	);
}



