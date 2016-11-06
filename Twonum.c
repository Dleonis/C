#include<stdio.h>
int main()
{
	int num1 = 0;
	int num2 = 0;
	int i = 0;
	int count = 0;
	printf("Please Enter two number\n");
	scanf("%d %d", &num1, &num2);
	num1 ^= num2;
	for (i = 0; i < 32; i++)
	{
		if ((num1 >> i) & 1)
		{
			count++;
		}
	}
	printf("count = %d\n", count);
	return 0;
}