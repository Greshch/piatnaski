#pragma once

void InitBoard();

void UpdateHead(int key = 0);

void UpdateBoard(int key = 0);

void GetActiveNode();

bool IsNodeActive(int row, int col);

void ShuffleBoard(int times = 25);

bool IsWin();

bool IsDirrectKey(int key);