#pragma once
//游戏代码的声明
#include <stdio.h>
#include <stdlib.h>//rand（）,srand（）
#include <time.h>//time()
#define ROW 3
#define COL 3
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL],int row ,int col );
void playermove(char board[ROW][COL], int row, int col);
void computermove(char board[ROW][COL], int row, int col);
char Iswin(char board[ROW][COL], int row, int col);