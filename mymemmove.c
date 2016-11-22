#include<stdio.h>
#include<assert.h>

void *mymemmove(void *dst, const void *src, int len)
{
	assert(dst);
	assert(src);
	if((dst <= src) || ((char *)dst >= (char *)src + len))
	{
		while(len--)
		{
			*(char *)dst++ = *(char *)src++;
		}
	}
	else
	{
		dst = dst+len-1;
		src = src+len-1;
		while(len--)
		{
			*(char *)dst-- = *(char *)src--;
		}
	}
}

int main()
{
	char src[] = "hello bit";
	char dst[15] = {0};
	int nums = 0;
	printf("Please Enter :");
	scanf("%d", &nums);
	mymemmove(dst, src+2, nums*sizeof(char));
	printf("%s\n", dst);
	return 0;
}
