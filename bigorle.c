#include<stdio.h>
int checkSystem()
{
	union check
	{
	char a;
	int b;
	}ch;
	ch.b = 1;
	return (ch.a);
}
int main()
{
	int i = 0;
	i = checkSystem();
	if(i = 1)
	{
	printf("小端存储\n");
	}
	else
	{
	printf("大端存储\n");
	}
	return 0;
}
