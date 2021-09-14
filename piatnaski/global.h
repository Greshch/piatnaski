#pragma once
#include <Windows.h>

extern HANDLE handle;

enum CTRLS { LEFT = 75, UP = 72, RIGHT = 77, DOWN = 80, EXIT = 'Q' };

enum colors { BLUE = 9, RED = 12, YELLOW = 14, DARKGREEN = 2, WHITE = 7, PURPLE = 5 };

int const ROWS = 4;
int const COLLS = 4;

extern COORD head;
extern int board[ROWS][COLLS];

extern CONSOLE_CURSOR_INFO cci;

int ReadKey();

void InitApp();

void CloseApp();

