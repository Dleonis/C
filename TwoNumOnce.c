#include<stdio.h>
#include<assert.h>

int main()
{
	int arr[] = {1,2,3,4,5,6,1,2,3,4};
	int len = sizeof(arr)/sizeof(arr[0]);
	int i = 0;
	int flag = 0;
	int ret = 0;
	int num1 = 0;
	int num2 = 0;
	for(i = 0; i < len; i++)
	{
		flag ^= arr[i];   //用来记录整个数组异或的结果
	}
	ret = flag ^ (flag&(flag-1));//用来标记flag最低位为1的位置,他是一个只有一位为1的数字
	for(i = 0; i < len; i++)
	{
		if((arr[i] & ret) == ret)//如果arr[i]的那一位为1，说明他是异或成flag两个数中的一个。因为其他数字都是成对出现所以，异或他们就可以得到一个数字。
		{
			num1 ^= arr[i];
		}
		else
		{
			num2 ^= arr[i];
		}
	}
	printf("num1 = %d,num2 = %d\n", num1, num2);
	return 0;
}
