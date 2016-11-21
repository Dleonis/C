#include<stdio.h>
#include<string.h>
char findch(char *src, int len)
{
	int i = 0;
	int find[26] = {0};
	for(i = 0; i < len; i++)
	{
		find[src[i] - 'a']++;
	}
	for(i = 0; i < len; i++)
	{
		if(find[src[i] - 'a'] == 1) 
		{
			return src[i];
		}
	}
}

int main()
{
	char str[] = "abcdefvabcdef";
	char ch = findch(str, strlen(str));
	printf("%c\n", ch);
	return 0;
}
