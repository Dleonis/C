#include<stdio.h>
#include<assert.h>

void show(int *arr, int len)
{
	int i = 0;
	for(i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void myswap(int *arr, int len)
{
	assert(arr);
	int i = 0;
	for(i = 0; i < len; i++)
	{
		if((arr[i]&1) == 0)
		{
			int tmp = arr[i];
			int j = i;
			for(; j < len - 1; j++)
			{
				arr[j] = arr[j+1];	
			}
			arr[j] = tmp;
		}
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int len = sizeof(arr)/sizeof(arr[0]);
	show(arr, len);
	myswap(arr, len);
	show(arr, len);
	return 0;
}
