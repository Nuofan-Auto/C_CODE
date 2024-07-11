#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BOMB 10
#define ROW 9
#define COL 9
#define ROWS 10
#define COLS 10

void SetBomb(char board[ROWS][COLS], int row, int col);
void InitBoard(char board[ROWS][COLS], int row, int col);
void PrintBoard(char board[ROWS][COLS], int row, int col);
void Play(char real[ROWS][COLS], char show[ROWS][COLS], int row, int col);