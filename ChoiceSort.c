#include <stdio.h>

void show(int arr[], int len)
{
	int i =0;
	for(i = 0; i < len; i++)
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

void ChoiceSort(int arr[], int len)
{
	if(NULL == arr)
	{
		printf("Error!\n");
		return ;
	}
	int i = 0;
	for(i = 0; i < len; i++)
	{
		int j = 0;
		for(j = i; j < len; j++)
		{
			if(arr[i] > arr[j])
			{
				swap(&arr[i], &arr[j]);
			}
		}
	}
}

int main()
{
	int arr[] = {12,45,32,12,543,56,453,532,23,421};
	int len = sizeof(arr) / sizeof(arr[0]);
	show(arr, len);
	ChoiceSort(arr, len);
	show(arr, len);
	return 0;
}
