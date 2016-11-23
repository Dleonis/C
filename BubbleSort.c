#include<stdio.h>

void show(int arr[], int len)
{
	int i = 0;
	for(i = 0; i < len ; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
	
void BubbleSort(int arr[], int len)
{
	int i = 0;
	int flag = 0;
	for(i = 0; i < len; i++)
	{
		int j = 0;
		flag = 0;
		//注意循环条件
		for(j = 0; j < len - 1 - i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
				flag = 1;	
			}
		}
		//避免无效的循环（在从头比较一次之后发现没有任何值交换，则已经完成）
		if(flag == 0)
		{
			break;
		}
	}

}

int main()
{
	int arr[] = {2, 35, 64, 12, 54, 42, 62, 78, 96, 32};
	int len = sizeof(arr) / sizeof(arr[0]);
	show(arr, len);
	BubbleSort(arr, len);
	show(arr, len);
	return 0;
}
