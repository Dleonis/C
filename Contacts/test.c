#define _CRT_SECURE_NO_WARNINGS
#include "contacts.h"

void init_all(Stu stu[NUMS], int nums);//��ʼ��
void mydelete(Stu stu[NUMS], int nums);//ɾ��ָ����ϵ��
void find(Stu stu[NUMS], int nums);//����ָ����ϵ��
void alter(Stu stu[NUMS], int nums);//�޸�ָ����ϵ��
void print_all(Stu stu[NUMS], int nums);//��ʾ������ϵ��
void empty_all(Stu stu[NUMS], int nums);//���������ϵ��
//void sort(Stu stu[NUMS], int nums);//����������ϵ��
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