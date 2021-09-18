#pragma once
#include <vector>
#include <utility>
#include <Windows.h>
#include "global.h"

typedef std::vector<std::pair<COORD, int>>::iterator It_Node;

void InitBoard();

void UpdateHead(int key = 0);

void UpdateBoard(int key = 0);

void GetActiveNode();

bool IsNodeActive(int row, int col);

void ShuffleBoard(int times = SHUFLE_TIMES);

bool IsWin();

bool IsDirrectKey(int key);

It_Node GetNodeByDirect(int dir);

int GetReverseDir(int dir);

bool IsValidNode(It_Node pNode);

void SwapCellsBoard(COORD const& a, COORD const& b);

int GetRandomeKey();