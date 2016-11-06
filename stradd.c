#include<stdio.h>
#include<string.h>
#define MAX 100

char *stradd(char *left, int len)
{
	char *src = left;
	char *right = left + len;
	char *flag = NULL;
	while (*left)
	{
		if (*left == ' ')
		{
			flag = right;
			while (right != left)
			{
				*(right + 2) = *right;
				right--;
			}
			*left = '%';
			*(++left) = '2';
			*(++left) = '0';
			right = flag + 3;
		}
		left++;
	}
	return src;
}
int main()
{
	char arr[MAX] = { 0 };
	printf("Plese Enter:");
	gets(arr);
	printf("%s\n", arr);
	stradd(arr,strlen(arr));
	printf("%s", arr);
	system("pause");
	return 0;
}
