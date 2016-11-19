#include<stdio.h>
#include<assert.h>

char *strcpy(char *dst, const char *src)
{
	assert(dst);
	assert(src);
	char *ret = dst;
	while(*dst++ = *src++);
	*dst = '\0';
	return ret;
}

int main()
{
	char str[] = "abcdefg";
	char dst[] = {0};
	strcpy(dst, str);
	printf("%s\n",dst);
	return 0;
}
