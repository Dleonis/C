#include<stdio.h>
#include<assert.h>
char *strreverse(char *p)
{
	assert(p);
	char *src = p; 
	char *left = p;
	char *right = NULL;
	while(*p++)
	{
		;
	}
	right = p-2;
	while(left <= right)
	{
		char tmp = *left;
		*left++ = *right;
		*right-- = tmp;
	}
	return src;
}
int main()
{
	char arr[] = "hello bit!";
	printf("Before : %s\n", arr);
	strreverse(arr);
	printf("After  : %s\n", arr);
	return 0;
}
