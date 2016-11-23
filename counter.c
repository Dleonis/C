#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void user()
{
	printf("use :   ./cal -[a|s|m|d] data1 data2\n");
}
int add(int a, int b)
{
	return a+b;
}
int sub(int a, int b)
{
	return a-b;
}
int mul(int a, int b)
{
	return a*b;
}
int mydiv(int a, int b)
{
	return a/b;
}



int main(int argc, const char *argv[])
{
	if(argc != 4)
	{
		user();
		return 0;
	}
	int data1 = atoi(argv[2]);
	int data2 = atoi(argv[3]);
	
	if(0 == strcmp("-a", argv[1]))
	{
		printf("res : %d\n", add(data1, data2));		
	}
	else if(0 == strcmp("-s", argv[1]))
	{
		printf("res : %d\n", sub(data1, data2));
	}
	else if(0 == strcmp("-m", argv[1]))
	{
		printf("res : %d\n", mul(data1, data2));
	}
	else if(0 == strcmp("-d", argv[1]))
	{
		if(data2 == 0)
		{
			printf("div value is zeor\n");
		}
		else
		{
			printf("res : %d\n", mydiv(data1, data2));
		}
	}
	else
	{
		user();
	}
	return 0;
}
