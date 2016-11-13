
#include<stdio.h>
#define SWAPBIT(x)  ((((x) & 0xaaaaaaaa) >> 1) | (((x)& 0x55555555) << 1))
int main()
{
	int value = 0;
	scanf("%d", &value);
	printf("After : %d\n", SWAPBIT(value));
	system("pause");
	return 0;
}
