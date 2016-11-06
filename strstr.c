//strstr(str1,str2) 函数用于判断字符串str2是否是str1的子串。如果是，则该函数返回str2在str1中首次出现的地址；否则，返回NULL。
#include<stdio.h>
#include<assert.h>
char *Mystrstr(char *src, char *dest)
{
	assert(src);
	assert(dest);
	char *cop_s = NULL;
	char *cop_d = NULL;
	while (*src)
	{
		if (*dest == *src)//与目标相等时进入循环
		{
			cop_s = src;
			cop_d = dest;
			while (*cop_d++ == *cop_s++)//如果字符串在源字符串中存在，返回出现的位置，不然重新从下一个字符开始匹配。
			{
				if (*cop_d == '\0')
				{
					return src;
				}
			}	
		}
		src++;
	}
	return NULL;

}
int main()
{
	char arr[] = "abcdcdfe";

	printf("arr : %s\n", arr);
	printf("Str : %s\n", Mystrstr(arr, "cd"));
	return 0;
}
