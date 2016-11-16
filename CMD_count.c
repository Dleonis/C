#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{

	if(strcmp(argv[1], "-a") == 0)
	{
		printf("%d\n", atoi(argv[2]) + atoi(argv[3]));
	}
	else if(strcmp(argv[1], "-s") == 0)
	{
		printf("%d\n", atoi(argv[2]) - atoi(argv[3]));
	}
	else if(strcmp(argv[1], "-m") == 0)
	{
		printf("%d\n", atoi(argv[2]) * atoi(argv[3]));
	}
	else if(strcmp(argv[1], "-d") == 0)
	{
		printf("%d\n", atoi(argv[2]) / atoi(argv[3]));
	}
	else
	{
		printf("Instruction is wrong!!!\n");
	}
	return 0;
}

