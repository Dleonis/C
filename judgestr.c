#include<stdio.h>
#include<assert.h>
#include<string.h>
int judgestr(char *src, char *dest , int len)
{
	assert(src);
	assert(dest);
	char *flag = src;
	char *copy_d = dest;
	int count = 0;
	while (*src)
	{
		if (*src == *dest)//如果src == dest 左旋转情况
		{
			char *pa = src;
			char *pb = dest;
			count += 1;
			while (*--pa == *++pb)
			{
				count++;
			}
			if ((pa + 1 == flag))
			{
				return count;
			}
			else
			{
				count = 0;
			}
		}
		if (*src == *(dest + len - 1))//src == dest最后一个字符  右旋转情况
		{
			char *pa = src;
			char *pb = dest+len-1;
			while (*++pa == *--pb)
			{
				count--;
			}
			if (*pa == '\0')
			{
				return count;
			}
			else
			{
				count = 0;
			}
		}
		src++;
	}
	return count;
}
int main()
{
	char src[] = "hello world and bit";
	/*char dest[] = "hello world and tib";*/
	char dest[] = "dlrow olleh and bit";
	int count = 0;//通过count判断他们是左旋转还是右旋转
	count = judgestr(src, dest,strlen(src));
	if (count > 0)
	{
		printf("左旋%d个字符\n", count);
	}
	else if (count < 0)
	{
		printf("右旋%d个字符\n", 0-count);
	}
	else
	{
		printf("不是字符串翻转而来的\n");
	}
	return 0;
}
