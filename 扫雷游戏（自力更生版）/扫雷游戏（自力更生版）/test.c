#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu()
{
	printf("****************************\n");
	printf("********* 1、play **********\n");
	printf("********* 0、exit **********\n");
	printf("****************************\n");
}
void game()
{
	char real[ROWS][COLS] = {'0'};
	char show[ROWS][COLS] = { '*'};
	InitBoard(real, ROW, COL);
	InitBoard(show, ROW, COL);
	SetBomb(real, ROW, COL);
	//PrintBoard(real, ROW, COL);
	//PrintBoard(show, ROW, COL);
	Play(real, show, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		int ret = 0;
		printf("请选择:>");
		scanf("%d", &ret);
		if (ret == 1)
		{
			game();
		}
		else if (ret == 0)
		{
			printf("退出游戏\n");
			break;
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}

	} while (1);
	return 0;
}