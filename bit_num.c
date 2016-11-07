#include<stdio.h>
/*int bit_num(int num)
{
	int count = 0;
	int i = 0;
	for(i = 0; i < 32; i++)//每次把num向右移一位，然后与1相与判断其值。一共需要循环32次。
	{
		if((num >> i) & 1)
		{
			count++;
		}
	}
	return count;
}*/
int bit_num(int num)
{	
	int count = 0;
	int i = 0;
//如果num不为0，num &=（num-1）这样做每次都可以消去数字最低位的1  例如10
//0000 1010    ——10          0001 0100  ——20
//0000 1001    ——10-1        0001 0011  ——19
//0000 1000    ——&           0001 0000  ——&
//这样就可以让循环可以有多少1就运行多少次，提高效率。
	while(num)
	{
		if(num)
		count++;
		num &= num - 1;
	}
	return count;
}
int main()
{
	int num = 0;
	printf("Please Enter:");
	scanf("%d", &num);
	printf("bit_num = %d\n", bit_num(num));
	return 0;
}
