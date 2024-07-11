#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void InitBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			board[i][j] = board[0][0];
		}
	}
}
void SetBomb(char board[ROWS][COLS], int row, int col)
{
	int count = 0;
	while (count < BOMB)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count++;
		}
	}
}
void PrintBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{

			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
char CountBomb(char real[ROWS][COLS], int x, int y)
{
	char count = '0';
	int i = 0;
	int j = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if (real[i][j] == '1')
			{
				count++;
			}
		}
	}
	return count;
}
int Iswin(char show[ROWS][COLS], int row, int col)
{
	int count = 0;
	int i = 0;
	int j = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '*')
			{
				count++;
			}
		}
	}
	return count;
}
void SpreadBoard(char real[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	if (CountBomb(real,x,y) == '0'&&show[x][y]=='*')
	{
		show[x][y] = ' ';
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				if (CountBomb(real, i, j) == '0')
				{
					SpreadBoard(real,show, i, j);
				}
				else
				{
					show[i][j] = CountBomb(real, i, j);
				}
			}
		}
	}
	if (CountBomb(real, x, y) != '0')
	{
		show[x][y] = CountBomb(real, x, y);
	}
}
void MarkBoard(char show[ROWS][COLS], int row, int col)
{
	while (1)
	{
		printf("�Ƿ�Ҫ��ǵ���,����1�����ǣ�����0�����:");
		int flag = 0;
		scanf("%d", &flag);
		if (flag == 1)
		{
			int x = 0;
			int y = 0;
			printf("������Ҫ��ǵ�����:");
			scanf("%d%d", &x, &y);
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				if (show[x][y] == '*')
				{
					show[x][y] = '#';
				}
				else
				{
					printf("�����������������\n");
				}
			}
			else
			{
				printf("�����������������\n");
			}
		}
		else if (flag == 0)
		{
			break;
		}
		else
		{
			printf("�����������������\n");
		}
	}
		
	
}
void Play(char real[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	while (1)
	{
		int i = rand() % 9 + 1;
		int j = rand() % 9 + 1;
		if (CountBomb(real, i, j) == '0')
		{
			SpreadBoard(real, show, i, j);
			PrintBoard(show, row, col);
			break;
		}
	}
	while (Iswin(show,row,col)>10)
	{
		int x = 0;
		int y = 0;
		printf("�������������:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] == '*')
			{
				if (real[x][y] == '1')
				{
					break;
				}
				else
				{
					SpreadBoard(real, show, x, y);
					PrintBoard(show, row, col);
					MarkBoard(show, row, col);
					PrintBoard(show, row, col);
				}
			}
			else
			{
				printf("�ô��ѱ����ң�����������\n");
			}

		}
		else
		{
			printf("�����������������\n");
		}
	}
	if (Iswin(show, row, col) > 10)
	{
		printf("�㱻ը���ˣ���Ϸ����\n");
		PrintBoard(real, row, col);
	}
	else
	{
		printf("��Ϸʤ��\n");
	}
}