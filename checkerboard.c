#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include"checkerboard.h"
void init(char a[ROW][COLU], int x, int y)
{
	memset(a, ' ', x*y);
}
void print(char a[ROW][COLU])
{
	printf(" %c | %c | %c \n", a[0][0], a[0][1], a[0][2]);
	printf("___|___|____\n");
	printf(" %c | %c | %c \n", a[1][0], a[1][1], a[1][2]);
	printf("___|___|____\n");
	printf(" %c | %c | %c \n", a[2][0], a[2][1], a[2][2]);
	printf("\n");
}
void play(char a[ROW][COLU], int x, int y)//用goto控制（输入错误，和已经被输入过的坐标）重新输入
{
flag:
	printf("请输入坐标：(a b)\n");
	int n_ROW = 0;
	int n_COLU = 0;
	scanf("%d %d", &n_ROW, &n_COLU);
	if ((n_ROW-1 > x && n_ROW-1 < 0) && (n_COLU-1 > y && n_COLU-1 < 0))
	{
		printf("输入错误，请重新输入\n");
		goto flag;
	}
	if (a[n_ROW - 1][n_COLU - 1] == ' ')
	{
		a[n_ROW - 1][n_COLU - 1] = 'x';
	}
	else
	{
		printf("此处已经输入,请重新输入！\n");
		goto flag;
	}
}
void computer(char a[ROW][COLU], int x, int y)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			if (a[i][j] == ' ')//电脑从头找空格，找到下棋，计数器+1
			{
				a[i][j] = 'o';
				count++;
				break;
			}
		}
		if (count>0)//计数器不为0跳出
		{
			break;
		}
	}
}
int win(char a[ROW][COLU], int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++) 
	{	
		// 判断横行和纵行是否相等
		if( ((a[i][0] == 'x') && (a[i][1] == 'x') && (a[i][2] == 'x'))||
			((a[0][i] == 'x') && (a[1][i] == 'x') && (a[2][i] == 'x')))
		{
			return 1;
		}
		else if (((a[i][0] == 'o') && (a[i][1] == 'o') && (a[i][2] == 'o')) ||
			((a[0][i] == 'o') && (a[1][i] == 'o') && (a[2][i] == 'o')))
		{
			return 0;
		}
		//判断斜行是否相等
		else if (((i == 0) && (a[i][i] == 'x') && (a[i + 1][i + 1] == 'x') && (a[i + 2][i + 2] == 'x')) ||
			((i == x-1) && (a[i - 2][i] == 'x') && (a[i - 1][i - 1] == 'x') && (a[i][i - 2] == 'x')))
		{
			return 1;
		}
		else if (((i == 0) && (a[i][i] == 'o') && (a[i + 1][i + 1] == 'o') && (a[i + 2][i + 2] == 'o')) ||
			((i == x-1) && (a[i-2][i] == 'o') && (a[i - 1][i - 1] == 'o') && (a[i][i - 2] == 'o')))
		{
			return 0;
		}
		else if (i == x-1) //只有在判断完之后才能确定是不是平局
			return -1;		
	}	
}
void game(char a[ROW][COLU], int x, int y)
{
	int count = 0;
	init(a, x, y);
	print(a);
	int i = 0;
	for (i = 0; i < x*y/2 + 1; i++)//电脑先下最多下 （x*y/2+1）次
	{
		computer(a, x, y);//电脑先输入
		print(a);         //电脑下完打印，人下完不打印，所以在让人赢之后打印一次
		count = win(a, x, y);// 判断电脑是不是赢了
		if (count == 0)
		{
			printf("你输了\n");
			break;
		}
		if (i < x*y / 2)      //电脑先下，人比电脑少下一步
		{
			play(a, x, y);	
		}
		count = win(a, x, y); //判断人是不是赢了,赢了在打印一次
		if (count == 1)
		{
			print(a);
			printf("你赢了\n");
			break;
		}
		if (i == x*y / 2) //在电脑下完最后一步时判断是否为平局
		{
			count = win(a, x, y);
			if (count == -1)
			{
				printf("平局\n");
				break;
			}
		}
	}
}