#include "Process.h"
int main()
{
	int n = 0;
	int i = 0;
	printf("��������̵ĸ�����");
	scanf("%d", &n);
flag:
	p = init(n, p);	
	pcb *copyp = NULL;
	printf("*************************\n");
	printf("*****��ѡ������㷨:*****\n");
	printf("*****1.�����ȷ��� *****\n");
	printf("*****2.����ҵ���ȣ� *****\n");
	printf("*****3.ʱ��Ƭ��ת�� *****\n");
	printf("*****4.��������  �� *****\n");
	printf("*****0.�˳�����  �� *****\n");
	printf("*************************\n");
	scanf("%d", &i);
	while (i)
	{
		switch (i)
		{
		case 1:
			printf("�����ȷ���\n");
			clear_zeor(n, p);
			Fcfs(n, p);
			count(n, p);
			print(n, p);
			break;
		case 2:
			printf("����ҵ���ȣ�\n");
			clear_zeor(n, p);
			Sjf(n, p);
			count(n, p);
			print(n, p);
			break;
		case 3:
			printf("ʱ��Ƭ��ת��\n");
			clear_zeor(n, p);
			RoundR(n, p);
			RRcount(n, p);
			print(n, p);
			break;
		case 4:
			goto flag;
		case 0:
			exit(0);
		default:
			printf("����������������룡\n");
			break;
		}
		scanf("%d", &i);
	}
	
	system("pause");
	return 0;
}



