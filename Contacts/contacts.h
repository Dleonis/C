#ifndef _CONTACTS_
#define _CONTACTS_
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<string.h>
#define NUMS 1000

typedef struct{
	char name[5];
	char sex[2];
	int age;
	long long tele;
	char address[10];
}Stu;

void init_all(Stu stu[NUMS], int nums);//初始化
void mydelete(Stu stu[NUMS], int nums);//删除指定联系人
void find(Stu stu[NUMS], int nums);//查找指定联系人
void alter(Stu stu[NUMS], int nums);//修改指定联系人
void print_all(Stu stu[NUMS], int nums);//显示所有联系人
void empty_all(Stu stu[NUMS], int nums);//清空所有联系人
//void sort(Stu stu[NUMS], int nums);//排序所有联系人
void end(Stu stu[NUMS], int nums);

void menu(Stu stu[NUMS], int nums, void(*pstu[])(Stu stu[NUMS], int nums));
#endif
