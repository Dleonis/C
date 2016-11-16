#include<stdio.h>
int main()
{
	int arr[] = { 2, 5, 4, 3, 7, 9, 44, 66, 1, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	printf("Before:");
	for (i = 0; i < size; i++)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n");
	for (i = 0; i < size; i++)
	{
		int j = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				arr[j] ^= arr[j + 1];
				arr[j + 1] ^= arr[j];
				arr[j] ^= arr[j + 1];
			}
		}
	}
	printf("After :");
	for (i = 0; i < size; i++)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n");
	return 0;
}
