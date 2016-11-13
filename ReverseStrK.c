#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<windows.h>
#include<malloc.h>


void RoundStr(char *src, int len, int k)
{
	assert(src);         // src不能为空
	assert(len > 0);     // len不能为0
	int i = 0; 
	k %= len;            // 计算出真正要旋转的字符个数，比如一个长度为7的字符串，翻转8个字符，相当于翻转了1个字符
	for (i = 0; i < k; i++)
	{
		char tmp = src[0];
		int j = 0;
		for (j = 0; j < src - 1; j++)
		{
			src[j] = src[j + 1];
		}
		src[j] = tmp;
	}
}


void reverse(char *left, char *right)
{
	assert(left);
	assert(right);
	while (left < right)
	{
		*left ^= *right;
		*right ^= *left;
		*left ^= *right;
		left++, right--;
	}
}
void RoundStr(char *src, int len, int k)
{	
	assert(src);         // src不能为空
	assert(len > 0);     // len不能为0
	k %= len;
	reverse(src, src + k - 1);
	reverse(src + k, src + len - 1);
	reverse(src, src + len - 1);
	return;
}

void RoundStr(char *src, int len, int k)
{
	assert(src);         // src不能为空
	assert(len > 0);     // len不能为0
	k %= len;
	char *dst = (char *)malloc(sizeof(char)*(2 * len) +1);
	strcpy(dst, src);
	strcat(dst, src);
	strncpy(src, dst + k, len);
	*(src + len) = '\0';
	free(dst);
	dst = NULL;
	return ;
}

int main()
{
	char arr[] = "abcdefg";
	int nums = 0;
	scanf("%d", &nums);
	printf("Before : %s\n", arr);
    RoundStr(arr,strlen(arr) ,nums);
    printf("After  : %s\n", arr);
	system("pause");
	return 0;
}

