#define _CRT_SECURE_NO_WARNINGS
//��Ϸ�����ʵ��
#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		/*printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);*/
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void playermove(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("�������\n");
	printf("����������:>");
	//��������Ϸ��Լ���
	while (1)
	{
		scanf("%d %d", &i, &j);
		if (i >= 1 && i <= row && j >= 1 && j <= col)
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				break;//����ѭ��
			}
			else
			{
				printf("���걻ռ�ã���ѡ������λ��:>");
			}
		}
		else
		{
			printf("����Ƿ�������������:>");
		}
	}
}
void computermove(char board[ROW][COL], int row, int col)
{
	printf("��������\n");

	int i = 0;
	int j = 0;

	while (1)
	{
		i = rand() % row;
		j = rand() % col;//ȷ�����ɵ����ֵ�Ϸ�
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			break;
		}
	}
}

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char Iswin(char board[ROW][COL], int row, int col)
{
	//�ж���
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]&&board[i][0]!=' ')
		{
			return board[i][1];//̫����
		}
	}
	//�ж���
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j]&&board[0][j]!=' ')
		{
			return board[1][j];//̫����
		}
	}
	//�ж������Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')
	{
		return board[0][2];
	}
	if (IsFull(board, row, col))
	{
		return 'E';
	}
	return 'C';
}
	