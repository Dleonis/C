//输出一个数字的每一位
#include<stdio.h>
/*#define MAX 100
void print_num(int num)
{	
	int arr[MAX] = {0};
	int i = 0;
	while(num)
	{
		arr[i++] = num % 10;
		num /= 10;
	}
	for(i -= 1;i >= 0; i--)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}*/
void print_num(int num)
{
	if(num > 9)
	{
		print_num(num/10);
	}	
	printf("%d ",num % 10);
}
int main()
{
	int num = 0;
	printf("Please Enter:");
	scanf("%d", &num);
	print_num(num);
	printf("\n");
	return 0;
}

