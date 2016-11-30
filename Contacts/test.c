#define _CRT_SECURE_NO_WARNINGS
#include "contacts.h"

void init_all(Stu stu[NUMS], int nums);//初始化
void mydelete(Stu stu[NUMS], int nums);//删除指定联系人
void find(Stu stu[NUMS], int nums);//查找指定联系人
void alter(Stu stu[NUMS], int nums);//修改指定联系人
void print_all(Stu stu[NUMS], int nums);//显示所有联系人
void empty_all(Stu stu[NUMS], int nums);//清空所有联系人
//void sort(Stu stu[NUMS], int nums);//排序所有联系人
void end(Stu stu[NUMS], int nums);
void(*pstu[]) (Stu stu[NUMS], int nums) = { end, init_all, find, mydelete, alter, empty_all, print_all };
void menu(Stu stu[NUMS], int nums, void(*pstu[])(Stu stu[NUMS], int nums));
int main()
{
	Stu stu[NUMS] = { 0 };
	int nums_peo = 0;
	printf("<Nums of people:> ");
	scanf("%d", &nums_peo);
	menu(stu, nums_peo, pstu);
	system("pause");
	return 0;
}