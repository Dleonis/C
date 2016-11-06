#include<stdio.h>
int Mystrlen(char *src)
{
	int len = 0;
	while('\0' != *src++)
	{
		len++;	
	}
	return len;
}
int main()
{
	char a[] = "abcdefg";
	printf("a : %s, len : %d\n", a, Mystrlen(a));
	return 0;
}
