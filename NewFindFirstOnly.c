#include <stdio.h>

int NewFindFirst(const char *src)
{
	int find[256] = {0};
	const char *start = src;
	while(*start != '\0')
	{
		find[(int)(*(start))] += 1;
		start++;
	}
	start = src;
	while(*start < 256)
	{
		if(find[(int)(*start)] == 1)
		{
			return *start;
		}
		start++;
	}
	return 256;
}

int main()
{
	char arr[] = "abcdabcdfsegc";
	if(NewFindFirst(arr) != 256)
	{
		char c =(char)NewFindFirst(arr);
		printf("%c\n", c);
	}
	else
	{
		printf("Not Find!!\n");
	}
	return 0;
}
