#include<stdio.h>
#include<assert.h>
#include<string.h>
void *strreverse(char *left,char *right)
{
	assert(left);
	assert(right);
	if(left < right)
	{
		*left ^= *right;
		*right ^= *left;
		*left ^= *right;
		strreverse(left+1,right-1);
	}
	return ;
}
int main()
{
	char arr[] = "abcdefg";
	printf("%s\n", arr);
	strreverse(arr, arr + strlen(arr)-1);
	printf("%s\n", arr);
	return 0;
}
