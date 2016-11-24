#include <stdio.h>

void show(const int arr[], int len)
{
	int i = 0;
	for(i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int *start, int *end)
{
	*start ^= *end;
	*end ^= *start;
	*start ^= *end;
}

void newOddEven(int arr[], int len)
{
	int *start = arr;
	int *end = arr+len-1;
	while(start < end)
	{
		while(start < end && (*start & 1))
		{
			start++;
		}
		while(start < end && !(*end &1))
		{
			end--;
		}
		if(start < end)
		{
			swap(start++, end--);
		}

	}
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int len =sizeof(arr)/sizeof(arr[0]);
	
	printf("Before : ");
	show(arr, len);
	newOddEven(arr, len);
	printf("After  : ");
	show(arr, len);
	return 0;
} 
