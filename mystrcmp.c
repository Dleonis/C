#include<stdio.h>
#include<assert.h>

int mystrcmp(const char *dst, const char *src)
{
	assert(dst);
	assert(src);
	while((*dst++ != '\0') && (*src++ != '\0'))
	{
		if(*dst > *src)
		{
			return 1;	
		}
		else if(*dst < *src)
		{
			return -1;
		}
	}
	if((*dst != '\0') && (*src == '\0'))
	{
		return 1;
	}
	else if((*dst == '\0') && (*src != '\0'))
	{
		return -1;
	}
	
	return 0;
}

int main()
{
	char src[] = "hello";
	int i = 0;
	i = mystrcmp( "hello bit" , src);
	if(0 == i)
	{
		printf("dst = src\n");
	}
	else if(1 == i)
	{
		printf("dst > src\n");
	}
	else
	{
		printf("dst < src\n");
	}
}
