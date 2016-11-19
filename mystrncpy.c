#include<stdio.h>
#include<assert.h>

char *strncpy(char *dst, const char *src, int n)
{
	assert(dst);
	assert(src);
	char *ret = dst;
	while((n--) && (*dst++ = *src++))
	
	*dst = '\0';
	return ret;
}

int main()
{
	char src[] = "abcdefg";
	char dst[] = "";
	int nums = 0;
	printf("Please Enter: \n");
	scanf("%d", &nums);
	strncpy(dst, src, nums);
	printf("%s\n", dst);
	return 0;
}
