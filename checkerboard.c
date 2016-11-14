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
void play(char a[ROW][COLU], int x, int y)//��goto���ƣ�������󣬺��Ѿ�������������꣩��������
{
flag:
	printf("���������꣺(a b)\n");
	int n_ROW = 0;
	int n_COLU = 0;
	scanf("%d %d", &n_ROW, &n_COLU);
	if ((n_ROW-1 > x && n_ROW-1 < 0) && (n_COLU-1 > y && n_COLU-1 < 0))
	{
		printf("�����������������\n");
		goto flag;
	}
	if (a[n_ROW - 1][n_COLU - 1] == ' ')
	{
		a[n_ROW - 1][n_COLU - 1] = 'x';
	}
	else
	{
		printf("�˴��Ѿ�����,���������룡\n");
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
			if (a[i][j] == ' ')//���Դ�ͷ�ҿո��ҵ����壬������+1
			{
				a[i][j] = 'o';
				count++;
				break;
			}
		}
		if (count>0)//��������Ϊ0����
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
		// �жϺ��к������Ƿ����
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
		//�ж�б���Ƿ����
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
		else if (i == x-1) //ֻ�����ж���֮�����ȷ���ǲ���ƽ��
			return -1;		
	}	
}
void game(char a[ROW][COLU], int x, int y)
{
	int count = 0;
	init(a, x, y);
	print(a);
	int i = 0;
	for (i = 0; i < x*y/2 + 1; i++)//������������� ��x*y/2+1����
	{
		computer(a, x, y);//����������
		print(a);         //���������ӡ�������겻��ӡ������������Ӯ֮���ӡһ��
		count = win(a, x, y);// �жϵ����ǲ���Ӯ��
		if (count == 0)
		{
			printf("������\n");
			break;
		}
		if (i < x*y / 2)      //�������£��˱ȵ�������һ��
		{
			play(a, x, y);	
		}
		count = win(a, x, y); //�ж����ǲ���Ӯ��,Ӯ���ڴ�ӡһ��
		if (count == 1)
		{
			print(a);
			printf("��Ӯ��\n");
			break;
		}
		if (i == x*y / 2) //�ڵ����������һ��ʱ�ж��Ƿ�Ϊƽ��
		{
			count = win(a, x, y);
			if (count == -1)
			{
				printf("ƽ��\n");
				break;
			}
		}
	}
}