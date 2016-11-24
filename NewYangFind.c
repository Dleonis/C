#include<stdio.h>

int NewYangFind(int (*src)[4], int lines, int rows, int nums)
{
	int row = rows - 1;
	int line = 0;
	while((line < 4) && (row >= 0))
	{
		if( nums > src[line][row])
		{
			line++;
		}
		else if( nums < src[line][row])
		{
			row--;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int arr[][4] = {{1, 2, 3, 4},{24, 32, 45, 46},
			{25, 34, 65, 66},{32, 35, 87, 99}};
	int nums = 0;
	printf("Please Enter: ");
	scanf("%d", &nums);
	int flag = NewYangFind(arr, 4, 4, nums);
	if(flag == 1)
	{
		printf("Find it\n");
	}
	else
	{
		printf("Not find\n");
	}	
	
	return 0;
}

