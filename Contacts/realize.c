#define _CRT_SECURE_NO_WARNINGS
#include "contacts.h"
static void init(Stu *stu)//��ʼ��һ���ṹ
{
	printf("*��������ϵ�˵����֣�");
	scanf("%s", &(*stu).name);
	printf("*��������ϵ�˵��Ա�");
	scanf("%s", &(*stu).sex);
	printf("*��������ϵ�˵����䣺");
	scanf("%d", &(*stu).age);
	printf("*��������ϵ�˵ĵ绰��");
	scanf("%lld", &(*stu).tele);
	printf("*��������ϵ�˵ĵ�ַ��");
	scanf("%s", &(*stu).address);
	printf("\n");
}
void init_all(Stu stu[NUMS], int nums)//ȫ����ʼ��
{
	if (stu == NULL)
	{
		printf("���ʳ���\n");
		return;
	}
	int i = 0;
	for (i = 0; i < nums; i++)
	{
		printf("������� %d ���˵���Ϣ\n", i + 1);
		init(&stu[i]);
	}
}
static void print(Stu stu)//��ӡ��ϵ��
{		
		printf("���� �� %s\n", stu.name);
		printf("�Ա� �� %s\n", stu.sex);
		printf("���� �� %d\n", stu.age);
		printf("�绰 �� %lld\n", stu.tele);
		printf("סַ �� %s\n", stu.address);
		printf("\n");
	
}
void print_all(Stu stu[NUMS], int nums)//��ӡȫ����ϵ��
{
	if (stu == NULL)
	{
		printf("���ʳ���\n");
		return;
	}
	int i = 0;
	int flag = 1;
	for (i = 0; i < nums; i++)
	{
		
		if (stu[i].age !=  -100)
		{
			printf("�� %d ����ϵ�˵���Ϣ��\n", flag);
			print(stu[i]);
			flag++;
		}
	}

}
static Stu *appiont(Stu stu[NUMS], int nums)//�ҵ�ָ������ϵ�ˣ�����ֵ��һ��ָ��ṹ���ָ��
{
	if (stu == NULL)
	{
		printf("���ʳ���\n");
		return NULL;
	}
	char people[5] = { 0 };
	printf("������Ҫ���ҵ���ϵ�ˣ�");
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
void find(Stu stu[NUMS], int nums)//����ָ����ϵ��
{
	if (stu == NULL)
	{
		printf("���ʳ���\n");
		return;
	}
	Stu *pstu = NULL;
	pstu = appiont(stu, nums);
	if (pstu != NULL)
	{
		printf("���ҳɹ�! \n");
		print(*pstu);
	}
	else
	{
		printf("����ʧ�ܣ�\n");
		return ;
	}
}
void alter(Stu stu[NUMS], int nums)//�޸�ָ����ϵ��
{
	if (stu == NULL)
	{
		printf("���ʳ���\n");
		return;
	}
	Stu *pstu = appiont(stu, nums);
	if (pstu == NULL)
	{
		printf("����ʧ�ܣ�\n");
		return;
	}
	else
	{
		init(pstu);
		printf("�޸���ɣ�\n");
	}
}
static void empty(Stu *stu)
{
	(*stu).age = -100;
}
void mydelete(Stu stu[NUMS], int nums)//ɾ��ָ����ϵ��
{
	if (stu == NULL)
	{
		printf("���ʳ���\n");
		return;
	}
	Stu *pstu = appiont(stu, nums);
	if (pstu == NULL)
	{
		printf("����ʧ�ܣ�\n");
		return;
	}
	empty(pstu);
}
void empty_all(Stu stu[NUMS], int nums)//���������ϵ��
{
	if (stu == NULL)
	{
		printf("���ʳ���\n");
		return;
	}
	int i = 0;
	for (i = 0; i < nums; i++)
	{
		empty(&stu[i]);
	}
	printf("����ɹ���\n");
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
		printf("*****1.��ʼ��ͨѶ¼*******\n");
		printf("*****2.������ϵ��  *******\n");
		printf("*****3.ɾ����ϵ��  *******\n");
		printf("*****4.�޸���ϵ��  *******\n");
		printf("*****5.�����ϵ��  *******\n");
		printf("*****6.��ʾ��ϵ��  *******\n");
		printf("*****0.�˳�        *******\n");
		printf("**************************\n");

		scanf("%d", &i);
		pstu[i](stu, nums);
	}
}