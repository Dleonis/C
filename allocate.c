#define _CRT_SECURE_NO_WARNINGS
#include "memory.h"
Node *init(Node *p)
{
	Node *cop = (Node *)malloc(sizeof(Node));
	p = (Node *)malloc(sizeof(Node));
	p->flag = 1;
	p->next = cop;
	int size = 0;
	cop->start = 0;
	cop->flag = 0;
	printf("请输入内存大小：");
	scanf("%d", &size);
	cop->size = size - 1;
	cop->end = cop->size;
	cop->next = NULL;
	return p;
}
void print(Node *p)
{
	int i = 0;
	Node *cop = p->next;
	while (cop != NULL)
	{
		
			printf("start   end    flag    size\n");
			printf("%d      %d     %d       %d\n", \
				cop->start, cop->end, cop->flag, cop->size);
			printf("\n");
			cop = cop->next;
		
	}
	printf("\n");
}

void FF(Node *p)//首次适应法
{
	Node *cop = p->next;
	int i = 0;
	int size = 0;
	int num = 0;
	cop = p->next;
	Node *new = (Node *)malloc(sizeof(Node));
	printf("请输入分配内存的大小：");
	scanf("%d", &new->size);
	while (cop != NULL)
	{
		num = 0;
		//如果内存块为空，而且内存块的大小大于要插入的大小，插入
		if ((cop->flag == 0) && (cop->size >= new->size)&&(new->size > 0))
		{
			if (cop->size - new->size <= MIN)
			{
				cop->flag = 1;
				num = 1;
				break;
			}
			else
			{
				Node *tmp = cop->next;
				int start = cop->start;
				int end = cop->end;

				cop->flag = 1;
				cop->size = new->size;
				cop->end = cop->start + cop->size - 1;
				cop->next = new;

				new->flag = 0;
				new->start = cop->end + 1;
				new->end = end;
				new->size = new->end - new->start + 1;
				new->next = tmp;
				num = 1;
				break;
			}
		}
		cop = cop->next;
	}
	if (num == 1)
	{
		printf("分配成功\n");
	}
	else
	{
		printf("分配失败\n");
	}
}

Node *NF(Node *pret)
{
	Node *ret = NULL;
	Node *cop = pret;
	int i = 0;
	int size = 0;
	int num = 0;
	Node *new = (Node *)malloc(sizeof(Node));
	printf("请输入分配内存的大小：");
	scanf("%d", &new->size);
	while (cop != NULL)
	{
		if ((cop->flag == 0) && (cop->size >= new->size)&&(new->size > 0))
		{
			if (cop->size - new->size <= MIN)
			{
				cop->flag = 1;
				num = 1;
				ret = cop->next;
				break;
			}
			else
			{
				Node *tmp = cop->next;
				int start = cop->start;
				int end = cop->end;
				cop->flag = 1;
				cop->size = new->size;
				cop->end = cop->start + cop->size - 1;
				cop->next = new;
				new->flag = 0;
				new->start = cop->end + 1;
				new->end = end;
				new->size = new->end - new->start + 1;
				new->next = tmp;
				num = 1;
				ret = new;
				break;
			}
		}
		cop = cop->next;
	}
	if (num == 1)
	{
		printf("分配成功\n");
	}
	else
	{
		printf("分配失败\n");
	}
	return ret;
}

void BF(Node *p)
{
	Node *cop = p->next;
	int i = 0;
	int size = 0;
	int num = 0;
	Node *pprev = p;  //cop的前一个
	Node *paft = cop->next; //cop的下一个
	while (cop->next != NULL)
	{
		paft = cop->next;
		while (paft != NULL)
		{

			if (((paft->flag == 0) && (cop->flag == 0) && (cop->size > paft->size)) || \
				((paft->flag == 1) && (cop->flag == 0)))
			{
				pprev->next = paft;
				cop->next = paft->next;
				paft->next = cop;
				cop = paft;
				paft = cop->next;
			}
			paft = paft->next;
		}
		pprev = cop;
		cop = cop->next;
	}
	FF(p);
}
void WF(Node *p)
{

	Node *cop = p->next;
	int i = 0;
	int size = 0;
	int num = 0;
	Node *pprev = p;  //cop的前一个
	Node *paft = cop->next; //cop的下一个
	while (cop->next != NULL)
	{
		paft = cop->next;
		while (paft != NULL)
		{
			
			if (((paft->flag == 0) && (cop->flag == 0) && (cop->size < paft->size)) || \
				((paft->flag == 1) && (cop->flag == 0)))
			{
				pprev->next = paft;
				cop->next = paft->next;
				paft->next = cop;
				cop = paft;
				paft = cop->next;
			}
			paft = paft->next;
		}
		pprev = cop;
		cop = cop->next;
	}
	FF(p);
}
void myfree(Node *p)
{
	int i = 0;
	int nums = 0;
	int start = 0;
	int end = 0;
	printf("请输入要释放内存的开始位置：\n");
	scanf("%d", &start);
	printf("请输入要释放内存的结束位置：\n");
	scanf("%d", &end);
	Node *cop = p->next;
	Node *pprev = p;
	Node *paft = cop->next;
	while (cop != NULL)//找到要回收的内存
	{
		paft = cop->next;
		//判断它是否被利用
		if ((cop->flag == 1)&&(cop->start == start)&&(cop->end == end))
		{
			i = 1;
			break;
		}
		pprev = cop;
		cop = cop->next;
	}
	if (i == 0)
	{
		printf("没有找到该快内存，或已被释放\n");

	}
	else
	{
		if (paft != NULL)
		{
			if ((pprev->flag == 1) && (paft->flag == 1))
			{
				cop->flag = 0;
			}
			else if ((pprev->flag == 0) && (paft->flag == 1))
			{
				pprev->next = paft;
				pprev->size += cop->size;
				pprev->end = cop->end;
			}
			else if ((pprev->flag == 1) && (paft->flag == 0))
			{
				cop->flag = 0;
				cop->next = paft->next;
				cop->size += paft->size;
				cop->end = paft->end;
			}
			else if ((pprev->flag == 0) && (paft->flag == 0))
			{
				pprev->next = paft->next;
				pprev->size += (cop->size + paft->size);
				pprev->end = paft->end;
			}
			printf("释放成功\n");
		}
		else
		{
			if (pprev->flag == 1)
			{
				cop->flag = 0;
			}
			else if (pprev->flag == 0)
			{
				pprev->next = paft;
				pprev->size += cop->size;
				pprev->end = cop->end;
			}
		}
	}
}
void FirstFit(Node *p)
{
	int i = 1;
	int n = 1;
	while (n)
	{
		printf("*1.分配内存*\n");
		printf("*2.回收内存*\n");
		printf("*0.退出    *\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			FF(p);
			print(p);
			break;
		case 2:
			myfree(p);
			print(p);
			break;
		case 0:
			n = 0;
			break;
		default:
			printf("输入错误,重新输入！\n");
			break;
		}
	}
	printf("已退出！\n");
}
void NextFit(Node *pret)
{
	Node *reflag = NULL;
	int i = 1;
	int n = 1;
	while (n)
	{
		printf("*1.分配内存*\n");
		printf("*2.回收内存*\n");
		printf("*0.退出    *\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			if (reflag != NULL)
			{
				reflag = NF(reflag);
			}
			else
			{
				reflag = NF(p->next);
			}
			print(p);
			break;
		case 2:
			myfree(p);
			print(p);
			break;
		case 0:
			n = 0;
			break;
		default:
			printf("输入错误,重新输入！\n");
			break;
		}
	}
	printf("已退出！\n");
}
void BestFit(Node *p)
{
	int i = 1;
	int n = 1;
	while (n)
	{
		printf("*1.分配内存*\n");
		printf("*2.回收内存*\n");
		printf("*0.退出    *\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			BF(p);
			print(p);
			break;
		case 2:
			myfree(p);
			print(p);
			break;
		case 0:
			n = 0;
			break;
		default:
			printf("输入错误,重新输入！\n");
			break;
		}
	}
	printf("已退出！\n");
}
void WorstFit(Node *p)
{
	int i = 1;
	int n = 1;
	while (n)
	{
		printf("*1.分配内存*\n");
		printf("*2.回收内存*\n");
		printf("*0.退出    *\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			WF(p);
			print(p);
			break;
		case 2:
			myfree(p);
			print(p);
			break;
		case 0:
			n = 0;
			break;
		default:
			printf("输入错误,重新输入！\n");
			break;
		}
	}
	printf("已退出！\n");
}

void mnue()
{
	printf("******************************\n");
	printf("********1.首次适应法    ******\n");
	printf("********2.循环首次适应法******\n");
	printf("********3.最佳适应法    ******\n");
	printf("********4.最坏适应法    ******\n");
	printf("********5.重新输入      ******\n");
	printf("********0.退出程序      ******\n");
	printf("******************************\n");
}