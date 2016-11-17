#define _CRT_SECURE_NO_WARNINGS

#include"sweep.h"
#include<stdio.h>

void menu()
{
	printf("**********************\n");
	printf("****1.play 0.exit*****\n");
	printf("**********************\n");
}
int main()
{
	while (1)
	{
		menu();
		int choose = 0;
		scanf("%d", &choose);
		if (choose == 1)
		{
			play();
		}
		else
		{
			break;
		}
	}
	system("pause");
	return 0;
}
