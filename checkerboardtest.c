#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"checkerboard.h"
#include<string.h>
void menu()
{
	printf("*************************\n");
	printf("**1.��ʼ��Ϸ 0.��Ϸ�˳�**\n");
	printf("*************************\n");
}
int main()
{
	int input = 0;
	char arr[ROW][COLU];
	do
	{
		menu();
		printf("��ѡ��:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game(arr,ROW,COLU);
			break;
		case 0:
			exit();
			break;
		default:
			printf("����������������룺\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}