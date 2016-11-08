#include<stdio.h>
#include<assert.h>
#define MAX 100
char *strturnk(char *pa, int k)
{
	assert(pa);
	char *left = pa;
	char *right = (pa+k);
	while(left <= right)
	{
		char tmp = *left;
		*left++ = *right;
		*right-- = tmp;
	}
	return pa;
}
int main()
{
	char arr[] = "hello world and bit";
	int k = 0;
	printf("要旋转的长度：\n");
	scanf("%d", &k);
	printf("%s\n", arr);
	strturnk(arr,k);
	printf("%s\n", arr);
	return 0;
}
