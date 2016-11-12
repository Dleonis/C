#include "Process.h"

pcb *init(int n, pcb *p)
{
	int i = n;
	pcb *copy_p;
	p = (pcb *)malloc(sizeof(pcb));
	copy_p = (pcb *)malloc(sizeof(pcb));
	p = copy_p;
	while (i != 0)
	{
		pcb *l;
		l = (pcb *)malloc(sizeof(pcb));
		copy_p->next = l;
		copy_p = l;
		printf("进程的名字：");
		scanf("%s", l->name);
		printf("进程的到达时间：");
		scanf("%d", &l->StartTime);
		printf("进程的运行时间：");
		scanf("%d", &l->RunTime);
		i--;
	}
	copy_p->next = NULL;
	return p;
}

pcb *clear_zeor(int n, pcb *p)//便于选择不同方式之后的计算
{
	pcb *copy_p = p->next;
	while (copy_p != NULL)
	{
		copy_p->EndTime = 0;
		copy_p->TurnTime = 0;
		copy_p->TurnWeiTime = 0.0;
		copy_p = copy_p->next;
	}
	return p;
}


void print(int num, pcb *p)
{
	int i = 0;
	pcb *n = NULL;
	n = (pcb *)malloc(sizeof(pcb));
	n = p->next;
	for (i = 0; i < num; i++)
	{
		printf("name     start     Run     End     Turn     TurnWeigh\n");
		printf("%s%10d%11d%7d%10d%14lf\n", \
			n->name, n->StartTime, n->RunTime, n->EndTime, n->TurnTime, n->TurnWeiTime);
		n = n->next;
	}
}

pcb *count(int n, pcb *p)//计算完成时间等等，时间片轮转有另一个计算方法
{
	pcb *a = NULL;
	pcb *b = NULL;
	int i = 0;
	int flag = 0;
	a = p->next;
	b = a;
	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			a->EndTime = a->RunTime + a->StartTime;
			flag = a->StartTime;
			a->TurnTime = a->EndTime - a->StartTime;
			a->TurnWeiTime = a->TurnTime / a->RunTime;
		}
		else
		{
			b = a;
			a = a->next;
			if (a->StartTime > b->EndTime)
			{
				flag = a->StartTime;
			}
			else
			{
				flag = b->EndTime;
			}
			a->EndTime = flag + a->RunTime;
			a->TurnTime = a->EndTime - a->StartTime;
			a->TurnWeiTime = (double)a->TurnTime / a->RunTime;
		}
	}
	return p;
}

pcb *Fcfs(int n, pcb *p)
{
	int i = 0;
	int j = 0;
	pcb *a = NULL;
	pcb *b = NULL;
	pcb * tmp = NULL;
	tmp = p;
	pcb * prev_a = NULL;
	a = tmp->next;// tmp从头结点开始，让a成为tmp的下一个结点
	prev_a = tmp; //prev_a总是指向a的前一个结点
	while (a != NULL)//最小的先冒上来
	{
		b = a; //让b成为a下一个结点
		while (b->next != NULL)
		{
			pcb * prev_b = b;
			b = b->next;                   
			if ((a->StartTime > b->StartTime)||\
				((a->StartTime == b->StartTime) && (a->RunTime > b->RunTime)))//如果a的开始时间>b的开始时间交换他们
			{	
				prev_a->next = b;				//交换      
				prev_b->next = b->next;
				b->next = a;
				
				a = b;       //如果交换继续用前一个和后面的比较
				b = a->next;     
			}
		}
		prev_a = a;
		a = a->next;
	}
	return p;
}

pcb *Sjf(int n, pcb *p)
{
	Fcfs(n, p);//先按照Fcfs排序
	int i = 0;
	int j = 0;	
	int count_time = 0;
	pcb *a = NULL;
	pcb *b = NULL;
	pcb * tmp = NULL;
	tmp = p->next;         //第一个到达的总是先执行，所以不用判断第一个（从第二个开始）
	pcb * prev_a = NULL;
	a = tmp->next;// tmp从头结点开始，让a成为tmp的下一个结点
	prev_a = tmp;
	while(a != NULL)//第一次不用排，所以i从1开始,把小的先冒上来
	{
		b = a;     
		if (i == 1)
		{
			//用count_time记录已经排好的任务总共的花费时间
			count_time += tmp->StartTime + tmp->RunTime;
		}
		else
		{
			count_time += a->StartTime + a->RunTime;
		}
		while (b->next != NULL)
		{
			pcb * prev_b = b;
			b = b->next;    //让b成为b下一个结点
			if ((b->StartTime <= count_time) && (b->RunTime < a->RunTime))
		//当前进程到达时间小于前面进程的花费时间(说明在前面进程执行完后他已经到达)\
		并且这个进程的运行时间小于前一个的运行时间交换他
			{
				prev_a->next = b;				//交换      
				prev_b->next = b->next;          
				b->next = a;

				a = b;           //继续用当前的比较下一个;因为b与a交换所以让A=B
				b = a->next;     //B= A的下一个
			}
		}
		prev_a = a;
		a = a->next;
	}
	return p;
}


pcb *RoundR(int n, pcb*p)
{
	*Fcfs(n, p);
	int i = 0;
	pcb * tmp;
	pcb * a;
	pcb * b;
	tmp = p;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	b = tmp;
	tmp = p;
	int count = 0;//用来记录已经用的时间
	while (tmp->next != NULL)
	{
		pcb *l;
		l = (pcb *)malloc(sizeof(pcb));
		a = tmp->next;
		pcb *aftera = a->next;
		if (a->RunTime > TIME_SLICE)
		{
			count += TIME_SLICE;          //如果时间片内不能完成当前进程，已经用过的时间等于时间片
			l = (pcb *)malloc(sizeof(pcb));
			strcpy(l->name, a->name);
			l->RunTime = a->RunTime - TIME_SLICE;
			if ((a->next != NULL)&&(a->next->StartTime > count))//a完成时间片后，下一个还没到达
			{
				l->next = a->next;     //把它插在a的后面
				a->next = l;
			}
			else  //a完时间片完了，把a插到末尾执行下一个；a时间片完了，而且a是最后一个，把a插到末尾
			{
				b->next = l;             
				b = l;
				l->next = NULL;
			}
			a->EndTime = count;
		}
		else
		{ 
			count += a->RunTime;//时间片内可以完成，用过的时间等于进程的执行时间
			a->EndTime = count;
		}
		tmp = tmp->next;
	}
	tmp = p->next;
	i = 0;
	while (tmp != NULL)
	{
		
		if ((tmp->RunTime > TIME_SLICE))
		{
			pcb *preva = tmp;
			a = preva->next;
			while (a != NULL)
			{
				
				if (strcmp(a->name ,tmp->name) == 0)
				{
					tmp->EndTime = a->EndTime;
					preva->next = a->next;
					
				}
				else
				{
					preva = a;
				}
				a = a->next;
			}
		}
		tmp = tmp->next;
	}
	return p;
}
pcb *RRcount(int n, pcb *p)
{
	pcb *a = NULL;
	pcb *b = NULL;
	int i = 0;
	a = p->next;
	b = a;
	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			a->TurnTime = a->EndTime - a->StartTime;
			a->TurnWeiTime = a->TurnTime / a->RunTime;
		}
		else
		{
			b = a;
			a = a->next;
			a->TurnTime = a->EndTime - a->StartTime;
			a->TurnWeiTime = (double)a->TurnTime / a->RunTime;
		}
	}
	return p;
}