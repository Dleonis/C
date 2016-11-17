#define _CRT_SECURE_NO_WARNINGS
#include"sweep.h"
#include<stdlib.h>
void play()
{
	int x = 0;
	int y = 0;
	int flag = 1;
	int Get = 1;
	int count = 0;
	int First = 1;
	char s_mine[ROW][COLU] = { 0 };
	char s_show[ROW - 2][COLU - 2] = { 0 };
	init_game(s_mine, s_show, ROW, COLU);//��ʼ�������������
	set_mine(s_mine);//����
	/*print(s_mine, ROW, COLU);*///�������
	pt_show(s_show, ROW - 2, COLU - 2);//���������
	printf("Please Enter (x,y):\n");
	/*f_decide(s_mine, x, y);*/
	while (flag)
	{
		scanf("%d %d", &x, &y);
		if (First == 1)
		{
			f_decide(s_mine, x, y);//��һ���ж��ǲ����ף���������
			First--;
		}
		else
			First--;
		flag = printf_get(Get ,s_mine, s_show, x, y);
		Get--;
		//����ŵ�λ�ò����ף���������Χ����
		/*print(s_mine, ROW, COLU);*/
		pt_show(s_show, ROW - 2, COLU - 2);
		count = win(s_show, ROW - 2, COLU - 2);//��count=���ڻ�δ�ŵ�����
		if (count == SET_NUM_MINE)//���count=�������Ѿ����꣬����ѭ��
		{
			break;
		}
	}
	if ((flag == 0) || (count != SET_NUM_MINE))
	{
		printf("HeHe,You Die!GameOver!\n");
	}
	else
	{
		printf("You Win!\n");
	}
	print(s_mine, ROW, COLU);
}
void init_game(char m_arr[ROW][COLU],char s_arr[ROW - 2][COLU - 2], int x, int y)
{
	memset(m_arr, ' ', x*y*sizeof(char));
	memset(s_arr, '*', (x-2)*(y-2)*sizeof(char));
}
void set_mine(char arr[ROW][COLU])
{
	srand((unsigned int)time(NULL));
	int count = SET_NUM_MINE;
	while (count)
	{
		int i = rand() % 10;
		int j = rand() % 10;
		if ((arr[i + 1][j + 1]) == ' ')//����Ǹ��ط���û�з��ף���ô�Ϳ������Ƿ�һ��
		{
			arr[i + 1][j + 1] = '@';
			count--;
		}
	}
}
void pt_show(char arr[ROW - 2][COLU - 2], int x, int y)
//���������
{
	int i = 0;
	int j = 0;
	printf("   ");
	for (i = 0; i < x + 1; i++)
	{
		printf("%3d", i);
	}
	printf("\n");
	for (i = 0; i < x; i++)
	{
		printf("%6d", i + 1);
		for (j = 0; j < y; j++)
		{
			printf("%3c", arr[i][j]);
		}
		printf("\n");
	}
}
void print(char arr[ROW][COLU], int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x + 1; i++)
	{
		printf("%3d", i);
	}
	printf("\n");
	for (i = 0; i < x; i++)
	{
		printf("%3d", i + 1);
		for (j = 0; j < y; j++)
		{
			printf("%3c", arr[i][j]);
		}
		printf("\n");
	}
}
int printf_get(int flag, char arr[ROW][COLU], char show_a[ROW - 2][COLU - 2], int x, int y)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int copx = 0;
	int copy = 0;
	//���������ж��Ǹ�λ���ǲ�����
	//�������
	if (arr[x][y] == ' ')
	{		
		copx = x - 1;
		copy = y - 1;
		//��������Χ������ �ڼ�������Χ��Ϊ�״�����Χ����
		if (flag == 1)
		{
			for (j = 0; j < 3; j++)
			{
				for (i = 0; i < 3; i++)
				{

					if (arr[copx][copy] == ' ')
					{
						k = (arr[copx - 1][copy - 1] == '@') + (arr[copx - 1][copy] == '@') + (arr[copx - 1][copy + 1] == '@')\
							+ (arr[copx][copy - 1] == '@') + (arr[copx][copy + 1] == '@') + (arr[copx + 1][copy] == '@') + \
							(arr[copx + 1][copy - 1] == '@') + (arr[copx + 1][copy + 1] == '@');
						if ((copy - 1 < 10) && (copy - 1 >= 0))
							//�ж�copy��ֵ������show_aԽ��
						{
							show_a[copx - 1][copy - 1] = '0' + k;
						}
					}
					copx++;
				}
				copx = x - 1;
				copy++;
			}
		}
		else
		{
			if (arr[copx][copy] == ' ')
			{
				k = (arr[copx - 1][copy - 1] == '@') + (arr[copx - 1][copy] == '@') + (arr[copx - 1][copy + 1] == '@')\
					+ (arr[copx][copy - 1] == '@') + (arr[copx][copy + 1] == '@') + (arr[copx + 1][copy] == '@') + \
					(arr[copx + 1][copy - 1] == '@') + (arr[copx + 1][copy + 1] == '@');
				if ((copy < 10) && (copy >= 0))
					//�ж�copy��ֵ������show_aԽ��
				{
					show_a[copx][copy] = '0' + k;
				}
			}
		}
		return 1;
		
	}
	return 0;
}
void f_decide(char arr[ROW][COLU], int x, int y)
{
	int i = 0;
	int j = 0;
	flag:
	srand((unsigned int)time(NULL));
	i = rand() % 10 + 1;
	j = rand() % 10 + 1;
	if (arr[x][y] == '@')
	{
		if (arr[i][j] == ' ')
		{
			arr[i][j] = '@';
			arr[x][y] = ' ';
		}
		else
			goto flag;

	}
}
int win(char arr[ROW - 2][COLU - 2], int x, int y)
{
	//ͨ���ж��������еġ�*�����ж�����
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			if (arr[i][j] == '*')
			{
				count++;
			}
		}
	}
	return count;
}