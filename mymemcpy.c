#include<stdio.h>
#include<assert.h>

void *mymemcpy(void *dst, void *src, int len)
{
	assert(dst);
	assert(src);
	void *ret = dst;
	while(len--)
	{
		*(char *)dst++ = *(char *)src++;
	}
	return ret;
}

int main()
{
	char src[10] = {0};
	printf("Please Enter:");
	int nums = 0;
	scanf("%d", &nums);
	mymemcpy(src, "hello", nums*sizeof(char));
	printf("%s\n", src);
	return 0;
}
