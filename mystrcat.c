#include<stdio.h>
#include<assert.h>

char *mystrcat(char *dst, const char *src)
{
	assert(dst);
	assert(src);
	char *ret = dst;
	while(*++dst);
	while(*dst++ = *src++);
	return ret;
}

int main()
{
	char src[] = "hello bit";
	char dst[] = "abcdef";
	mystrcat(dst, src);
	printf("%s\n", dst);
	return 0;
}
