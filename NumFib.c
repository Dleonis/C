//斐波那契数是这样一个数列：0、1、1、2、3、5、8、13、21、……

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
void NumFib(int const num)
{
	assert(num > 0);
	int i = 0;
	int F_num = 0;
	int *p = (int *)malloc(num*sizeof(int));
	p[0] = 0;
	if(num > 1)
	{
		p[1] = 1;
	}	
	for(i = 2; i < num; i++)
	{
		p[i] = p[i-1] + p[i-2];
	}
	for(i = 0; i < num; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
	free(p);
	p = NULL;
}

int main()
{
	int num = 0;
	int *p = NULL;
	printf("Please Enter:\n");
	scanf("%d", &num);
	NumFib(num);
	return 0;
}
