#include "Process.h"
int main()
{
	int n = 0;
	int i = 0;
	printf("请输入进程的个数：");
	scanf("%d", &n);
flag:
	p = init(n, p);	
	pcb *copyp = NULL;
	printf("*************************\n");
	printf("*****请选择调度算法:*****\n");
	printf("*****1.先来先服务： *****\n");
	printf("*****2.短作业优先： *****\n");
	printf("*****3.时间片轮转： *****\n");
	printf("*****4.重新输入  ： *****\n");
	printf("*****0.退出程序  ： *****\n");
	printf("*************************\n");
	scanf("%d", &i);
	while (i)
	{
		switch (i)
		{
		case 1:
			printf("先来先服务：\n");
			clear_zeor(n, p);
			Fcfs(n, p);
			count(n, p);
			print(n, p);
			break;
		case 2:
			printf("短作业优先：\n");
			clear_zeor(n, p);
			Sjf(n, p);
			count(n, p);
			print(n, p);
			break;
		case 3:
			printf("时间片轮转：\n");
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
			printf("输入错误，请重新输入！\n");
			break;
		}
		scanf("%d", &i);
	}
	
	system("pause");
	return 0;
}



