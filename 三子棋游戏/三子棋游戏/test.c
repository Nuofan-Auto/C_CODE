#define _CRT_SECURE_NO_WARNINGS
//������Ϸ���߼�
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
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	//����
	while (1)
	{
		playermove(board, ROW, COL);//������
		DisplayBoard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		computermove(board, ROW, COL);//��������
		DisplayBoard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
		printf("���Ӯ\n");
	else if (ret == '#')
		printf("����Ӯ\n");
	else
		printf("ƽ��\n");
}
int main()
{
	srand((unsigned int)time(NULL));//���������  ʱ���
	int input = 0;
	do
	{
		menu();
		//��ӡ�˵�
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1 :
			printf("������\n");
			game();
			break;
		case 0 :
			printf("�˳���Ϸ\n");
				break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}