#include<stdio.h>
#include<math.h>
unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
	unsigned int sum = 0;
	for (; i<32; i++)
	{
		sum += (unsigned int)(((value >> i) & 1)*pow(2, (31 - i)));
	}
	return sum;
}
void show(unsigned int num)
{
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");
}
int main()
{
	unsigned int num = 0;
	unsigned int re_num = 0;
	printf("Please Enter a num\n");
	scanf("%d", &num);
	show(num);
	re_num = reverse_bit(num);
	show(re_num);
	return 0;
}

