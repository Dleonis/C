#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int substr(char *dst,char *arr, int start, int len)
{
	assert(dst);
	assert(arr);
	char *copy_dst = dst;
	arr += start;
	while((len>0) && (*arr != '\0'))
	{
		*dst++ = *arr++;
		len--;
	}
	*dst = '\0';
	return (dst-copy_dst);
}
int main()
{
	char arr[] = "hello World and bit";
	char *dst;
	int len = 0;
	int start = 0;
	int re_len = 0;
	printf("src : %s\n",arr);
	printf("请输入开始的位置和要复制的长度：<start,len>\n");
	scanf("%d,%d", &start, &len);
	dst = (char *)malloc(len*sizeof(char));
	re_len = substr(dst,arr,start,len);
	printf("dst : %s,re_len : %d\n",dst,re_len);
	free(dst);
	dst = NULL;
	return 0;
}
