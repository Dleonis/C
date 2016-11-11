#include "hehe.h"
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
		printf("���̵����֣�");
		scanf("%s", l->name);
		printf("���̵ĵ���ʱ�䣺");
		scanf("%d", &l->StartTime);
		printf("���̵�����ʱ�䣺");
		scanf("%d", &l->RunTime);
		l->WiteTime = 0;
		l->EndTime = 0;
		l->TurnTime = 0;
		l->TurnWeiTime = 0.0;
		i--;
	}
	copy_p->next = NULL;
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
		printf("name     start     Wait     Run     End     Turn     TurnWeigh\n");
		printf("%s%10d%11d%8d%7d%10d%14lf\n", \
			n->name, n->StartTime, n->WiteTime, n->RunTime, n->EndTime, n->TurnTime, n->TurnWeiTime);
		n = n->next;
	}
}

pcb *count(int n, pcb *p)
{
	pcb *a = NULL;
	pcb *b = NULL;
	int i = 0;
	a = (pcb *)malloc(sizeof(pcb));
	b = (pcb *)malloc(sizeof(pcb));
	a = p->next;
	b = a;
	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			a->EndTime = a->RunTime + a->StartTime;
			a->WiteTime = a->StartTime;
			a->TurnTime = a->EndTime - a->StartTime;
			a->TurnWeiTime = a->TurnTime / a->RunTime;
		}
		else
		{
			b = a;
			a = a->next;
			if (a->StartTime > b->EndTime)
			{
				a->WiteTime = a->StartTime;
			}
			else
			{
				a->WiteTime = b->EndTime;
			}
			a->EndTime = a->WiteTime + a->RunTime;
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
	for (i = 0; i < n; i++)//���ĳ���
	{
		pcb * prev_a = NULL;
		a = tmp->next;// tmp��ͷ��㿪ʼ����a��Ϊtmp����һ�����
		prev_a = tmp; //copy_a����ָ��a��ǰһ�����
		b = a;
		for (j = 1; j < n; j++)
		{
			pcb * prev_b = b;
			b = b->next;                    //��b��Ϊa��һ�����
			if ((a->StartTime > b->StartTime)||\
				(a->StartTime == b->StartTime) && (a->RunTime > b->RunTime))//���a�Ŀ�ʼʱ��>b�Ŀ�ʼʱ�佻������
			{
				prev_a->next = b;
				if (a->next == b)           //a��b����ʱ������a��b
				{
					a->next = b->next;
				}
				else
				{
					prev_b = b->next;       // a��b������ʱ������a��b

				}
				b->next = a;                //����	

				prev_a = b;                  //����֮��a��ǰһ��������b
				b = a;                       //�����õ�ǰ�ıȽ���һ��;��Ϊb��a����������b=a
			}
		}
	}
	return p;
}


pcb *Sjf(int n, pcb *p)
{
	Fcfs(n, p);//�Ȱ���Fcfs����
	int i = 0;
	int j = 0;	
	int count_time = 0;
	pcb *a = NULL;
	pcb *b = NULL;
	pcb * tmp = NULL;
	tmp = p->next;         //��һ�������������ִ�У����Բ����жϵ�һ�����ӵڶ�����ʼ��
	for (i = 1; i < n; i++)//��һ�β����ţ�����i��1��ʼ
	{
		pcb * prev_a = NULL;
		a = tmp->next;// tmp��ͷ��㿪ʼ����a��Ϊtmp����һ�����
		prev_a = tmp;
		b = a;
		if (i == 1)
		{
			//��count_time��¼�Ѿ��źõ������ܹ��Ļ���ʱ��
			count_time += tmp->StartTime + tmp->RunTime;
		}
		else
		{
			count_time += a->StartTime + a->RunTime;
		}
		for (j = 2; j < n; j++)
		{
			pcb * prev_b = b;
			b = b->next;    //��b��Ϊa��һ�����
			if ((b->StartTime <= count_time) && (b->RunTime < a->RunTime))
		//��ǰ���̵���ʱ��С��ǰ����̵Ļ���ʱ��(˵����ǰ�����ִ��������Ѿ�����)\
		����������̵�����ʱ��С��ǰһ��������ʱ�佻����
			{
				prev_a->next = b;				//����
				if (a->next == b)           //a��b����ʱ������a��b
				{
					a->next = b->next;
				}
				else
				{
					prev_b = b->next;       // a��b������ʱ������a��b

				}
				b->next = a;

				prev_a = b;
				b = a;                     //�����õ�ǰ�ıȽ���һ��;��Ϊb��a����������b=a
			}
		}
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
	for (i = 0; i < n; i++)
	{
		tmp = tmp->next;
	}
	b = tmp;
	tmp = p;
	int count = 0;//������¼�Ѿ��õ�ʱ��
	while (tmp->next != NULL)
	{
		pcb *l;
		l = (pcb *)malloc(sizeof(pcb));

		a = tmp->next;
		pcb *aftera = a->next;

		if (a->RunTime > TIME_SLICE)
		{
			count += TIME_SLICE;          //���ʱ��Ƭ�ڲ�����ɵ�ǰ���̣��Ѿ��ù���ʱ�����ʱ��Ƭ
			l = (pcb *)malloc(sizeof(pcb));
			strcpy(l->name, a->name);
			l->RunTime = a->RunTime - TIME_SLICE;
			if ((a->next->StartTime > count)&&(a->next != NULL))//a���ʱ��Ƭ����һ����û����
			{
				l->next = a->next;
				a->next = l;//����ִ��
			}
			else if ((a->next->StartTime <= count) || ((a->next->StartTime > count) && (a->next != NULL)))
			{
				b->next = l;             //��һ�������a�嵽ĩβ��ִ����һ��
				b = l;
				l->next = NULL;
			}
			a->EndTime = count;
		}
		else
		{ 
			count += a->RunTime;//ʱ��Ƭ�ڿ�����ɣ��ù���ʱ����ڽ��̵�ִ��ʱ��
			a->EndTime = count;
		}
		tmp = tmp->next;
	}
	tmp = p;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		if ((tmp != NULL) && (tmp->RunTime > TIME_SLICE))
		{
			pcb *a = tmp->next;
			while (a != NULL)
			{
				if (strcmp(a->name ,tmp->name) == 0)
				{
					tmp->EndTime = a->EndTime;
					if (a->next != NULL)
					{
						tmp->next = a->next;
					}
				}
				a = a->next;
			}
		}
	}
	return p;
}
pcb *RRcount(int n, pcb *p)
{
	pcb *a = NULL;
	pcb *b = NULL;
	int i = 0;
	a = (pcb *)malloc(sizeof(pcb));
	b = (pcb *)malloc(sizeof(pcb));
	a = p->next;
	b = a;
	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			a->WiteTime = a->StartTime;
			a->TurnTime = a->EndTime - a->StartTime;
			a->TurnWeiTime = a->TurnTime / a->RunTime;
		}
		else
		{
			b = a;
			a = a->next;
			if (a->StartTime > b->EndTime)
			{
				a->WiteTime = a->StartTime;
			}
			else
			{
				a->WiteTime = b->EndTime;
			}
			a->TurnTime = a->EndTime - a->StartTime;
			a->TurnWeiTime = (double)a->TurnTime / a->RunTime;
		}
	}
	return p;
}