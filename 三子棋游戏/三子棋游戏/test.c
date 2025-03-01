#define _CRT_SECURE_NO_WARNINGS
//测试游戏的逻辑
#include "game.h"
menu()
{
	printf("*************************\n");
	printf("***** 1.play 0.exit *****\n");
	printf("*************************\n");
}

void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1)
	{
		playermove(board, ROW, COL);//人下棋
		DisplayBoard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		computermove(board, ROW, COL);//电脑下棋
		DisplayBoard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
		printf("玩家赢\n");
	else if (ret == '#')
		printf("电脑赢\n");
	else
		printf("平局\n");
}
int main()
{
	srand((unsigned int)time(NULL));//设置随机数  时间戳
	int input = 0;
	do
	{
		menu();
		//打印菜单
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1 :
			printf("三子棋\n");
			game();
			break;
		case 0 :
			printf("退出游戏\n");
				break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}