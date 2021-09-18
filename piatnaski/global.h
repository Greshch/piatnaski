#pragma once
#include <Windows.h>
#include <utility>
#include <vector>

extern HANDLE handle;

enum CTRLS { LEFT = 75, UP = 72, RIGHT = 77, DOWN = 80, EXIT = 'q' };

enum colors { BLUE = 9, RED = 12, YELLOW = 14, DARKGREEN = 2, WHITE = 7, PURPLE = 5 };

int const ROWS = 4;
int const COLLS = 4;

int const SHUFLE_TIMES = 1024;

extern COORD head;
extern COORD end_line;
extern std::vector < std::pair <COORD, int> > activeNode;
extern int board[ROWS][COLLS];

extern CONSOLE_CURSOR_INFO cci;

int ReadKey();

void InitApp();

void CloseApp();

