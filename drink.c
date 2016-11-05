#include<stdio.h>
int drink(int num)
{
	int count = num;
	if(count/2 > 1)
	{
	count += drink(count/2);
	}
	return count;
}
int main()
{	
	int money = 20;
	int num = 0;
	num = drink(20);
	printf("NUM = %d\n", num); 
	return 0;
}
