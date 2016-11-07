#include<stdio.h>
#include<assert.h>
/*int mystrlen(char *pc)
{
	assert(pc);
	while(*pc)
	{
		return (1 + mystrlen(++pc));
	}
}*/
int mystrlen(char *pc)
{
	assert(pc);
	return *pc ? 1+(mystrlen(++pc)):0;
}
int main()
{
	char arr[] = "abcdefg";
	printf("len = %d\n",mystrlen(arr));
	return 0;
}
