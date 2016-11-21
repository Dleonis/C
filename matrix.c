#include<stdio.h>

int find(int *arr, int len, int num)
{
	int i = 0;
	for(i = 0; i < len; i++)
	{
		if(*(arr+i) == num)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int arr[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
	int num = 0;
	int len = sizeof(arr)/sizeof(arr[0][0]);
	printf("请输入要查找的数字：");
	scanf("%d", &num);
	if(1 == find(arr[0], len, num))
	{
		printf("存在\n");
	}
	else
	{
		printf("不存在\n");
	}
	return 0;
}
