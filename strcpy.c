#include<stdio.h>
#include<assert.h>
#include<windows.h>
char *Mystrcpy(char *dest, char *src)
{
	char *ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main()
{
	char a[] = "abcdef";
	char b[10] = { 0 };
	printf("Before: a : %s\nb : %s\n", a, b);
	Mystrcpy(b, a);
	printf("After : a : %s\nb : %s\n", a, b);
	system("pause");
	return 0;
}