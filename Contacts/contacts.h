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

void init_all(Stu stu[NUMS], int nums);//��ʼ��
void mydelete(Stu stu[NUMS], int nums);//ɾ��ָ����ϵ��
void find(Stu stu[NUMS], int nums);//����ָ����ϵ��
void alter(Stu stu[NUMS], int nums);//�޸�ָ����ϵ��
void print_all(Stu stu[NUMS], int nums);//��ʾ������ϵ��
void empty_all(Stu stu[NUMS], int nums);//���������ϵ��
//void sort(Stu stu[NUMS], int nums);//����������ϵ��
void end(Stu stu[NUMS], int nums);

void menu(Stu stu[NUMS], int nums, void(*pstu[])(Stu stu[NUMS], int nums));
#endif
