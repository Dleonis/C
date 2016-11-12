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
		printf("���̵����֣�");
		scanf("%s", l->name);
		printf("���̵ĵ���ʱ�䣺");
		scanf("%d", &l->StartTime);
		printf("���̵�����ʱ�䣺");
		scanf("%d", &l->RunTime);
		i--;
	}
	copy_p->next = NULL;
	return p;
}

pcb *clear_zeor(int n, pcb *p)//����ѡ��ͬ��ʽ֮��ļ���
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

pcb *count(int n, pcb *p)//�������ʱ��ȵȣ�ʱ��Ƭ��ת����һ�����㷽��
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
	a = tmp->next;// tmp��ͷ��㿪ʼ����a��Ϊtmp����һ�����
	prev_a = tmp; //prev_a����ָ��a��ǰһ�����
	while (a != NULL)//��С����ð����
	{
		b = a; //��b��Ϊa��һ�����
		while (b->next != NULL)
		{
			pcb * prev_b = b;
			b = b->next;                   
			if ((a->StartTime > b->StartTime)||\
				((a->StartTime == b->StartTime) && (a->RunTime > b->RunTime)))//���a�Ŀ�ʼʱ��>b�Ŀ�ʼʱ�佻������
			{	
				prev_a->next = b;				//����      
				prev_b->next = b->next;
				b->next = a;
				
				a = b;       //�������������ǰһ���ͺ���ıȽ�
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
	Fcfs(n, p);//�Ȱ���Fcfs����
	int i = 0;
	int j = 0;	
	int count_time = 0;
	pcb *a = NULL;
	pcb *b = NULL;
	pcb * tmp = NULL;
	tmp = p->next;         //��һ�������������ִ�У����Բ����жϵ�һ�����ӵڶ�����ʼ��
	pcb * prev_a = NULL;
	a = tmp->next;// tmp��ͷ��㿪ʼ����a��Ϊtmp����һ�����
	prev_a = tmp;
	while(a != NULL)//��һ�β����ţ�����i��1��ʼ,��С����ð����
	{
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
		while (b->next != NULL)
		{
			pcb * prev_b = b;
			b = b->next;    //��b��Ϊb��һ�����
			if ((b->StartTime <= count_time) && (b->RunTime < a->RunTime))
		//��ǰ���̵���ʱ��С��ǰ����̵Ļ���ʱ��(˵����ǰ�����ִ��������Ѿ�����)\
		����������̵�����ʱ��С��ǰһ��������ʱ�佻����
			{
				prev_a->next = b;				//����      
				prev_b->next = b->next;          
				b->next = a;

				a = b;           //�����õ�ǰ�ıȽ���һ��;��Ϊb��a����������A=B
				b = a->next;     //B= A����һ��
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
			if ((a->next != NULL)&&(a->next->StartTime > count))//a���ʱ��Ƭ����һ����û����
			{
				l->next = a->next;     //��������a�ĺ���
				a->next = l;
			}
			else  //a��ʱ��Ƭ���ˣ���a�嵽ĩβִ����һ����aʱ��Ƭ���ˣ�����a�����һ������a�嵽ĩβ
			{
				b->next = l;             
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