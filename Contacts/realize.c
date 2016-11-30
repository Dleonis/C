#define _CRT_SECURE_NO_WARNINGS
#include "contacts.h"
static void init(Stu *stu)//初始化一个结构
{
	printf("*请输入联系人的名字：");
	scanf("%s", &(*stu).name);
	printf("*请输入联系人的性别：");
	scanf("%s", &(*stu).sex);
	printf("*请输入联系人的年龄：");
	scanf("%d", &(*stu).age);
	printf("*请输入联系人的电话：");
	scanf("%lld", &(*stu).tele);
	printf("*请输入联系人的地址：");
	scanf("%s", &(*stu).address);
	printf("\n");
}
void init_all(Stu stu[NUMS], int nums)//全部初始化
{
	if (stu == NULL)
	{
		printf("访问出错！\n");
		return;
	}
	int i = 0;
	for (i = 0; i < nums; i++)
	{
		printf("请输入第 %d 个人的信息\n", i + 1);
		init(&stu[i]);
	}
}
static void print(Stu stu)//打印联系人
{		
		printf("姓名 ： %s\n", stu.name);
		printf("性别 ： %s\n", stu.sex);
		printf("年龄 ： %d\n", stu.age);
		printf("电话 ： %lld\n", stu.tele);
		printf("住址 ： %s\n", stu.address);
		printf("\n");
	
}
void print_all(Stu stu[NUMS], int nums)//打印全部联系人
{
	if (stu == NULL)
	{
		printf("访问出错！\n");
		return;
	}
	int i = 0;
	int flag = 1;
	for (i = 0; i < nums; i++)
	{
		
		if (stu[i].age !=  -100)
		{
			printf("第 %d 个联系人的信息：\n", flag);
			print(stu[i]);
			flag++;
		}
	}

}
static Stu *appiont(Stu stu[NUMS], int nums)//找到指定的联系人，返回值是一个指向结构体的指针
{
	if (stu == NULL)
	{
		printf("访问出错！\n");
		return NULL;
	}
	char people[5] = { 0 };
	printf("请输入要查找的联系人：");
	scanf("%s", people);
	int i = 0;
	for (i = 0; i < nums; i++)
	{
		if ((strcmp((stu[i].name), people) == 0) && ( stu[i].age != -100 ))
		{
			return &stu[i];
		}
	}
	return NULL;
}
void find(Stu stu[NUMS], int nums)//查找指定联系人
{
	if (stu == NULL)
	{
		printf("访问出错！\n");
		return;
	}
	Stu *pstu = NULL;
	pstu = appiont(stu, nums);
	if (pstu != NULL)
	{
		printf("查找成功! \n");
		print(*pstu);
	}
	else
	{
		printf("查找失败！\n");
		return ;
	}
}
void alter(Stu stu[NUMS], int nums)//修改指定联系人
{
	if (stu == NULL)
	{
		printf("访问出错！\n");
		return;
	}
	Stu *pstu = appiont(stu, nums);
	if (pstu == NULL)
	{
		printf("查找失败！\n");
		return;
	}
	else
	{
		init(pstu);
		printf("修改完成！\n");
	}
}
static void empty(Stu *stu)
{
	(*stu).age = -100;
}
void mydelete(Stu stu[NUMS], int nums)//删除指定联系人
{
	if (stu == NULL)
	{
		printf("访问出错！\n");
		return;
	}
	Stu *pstu = appiont(stu, nums);
	if (pstu == NULL)
	{
		printf("查找失败！\n");
		return;
	}
	empty(pstu);
}
void empty_all(Stu stu[NUMS], int nums)//清空所有联系人
{
	if (stu == NULL)
	{
		printf("访问出错！\n");
		return;
	}
	int i = 0;
	for (i = 0; i < nums; i++)
	{
		empty(&stu[i]);
	}
	printf("清楚成功！\n");
}
void end(Stu stu[NUMS], int nums)
{
	exit(0);
}
void menu(Stu stu[NUMS],int nums, void(*pstu[])(Stu stu[NUMS], int nums))
{
	int i = 0;
	while (1)
	{
		printf("**************************\n");
		printf("*****1.初始化通讯录*******\n");
		printf("*****2.查找联系人  *******\n");
		printf("*****3.删除联系人  *******\n");
		printf("*****4.修改联系人  *******\n");
		printf("*****5.清空联系人  *******\n");
		printf("*****6.显示联系人  *******\n");
		printf("*****0.退出        *******\n");
		printf("**************************\n");

		scanf("%d", &i);
		pstu[i](stu, nums);
	}
}