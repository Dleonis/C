
#include "hehe.h"

int main()
{
	int n = 0;
	printf("��������̵ĸ�����");
	scanf("%d", &n);
	p = init(n, p);
	//Fcfs(n, p);
	//Sjf(n, p);
	RoundR(n, p);
	//count(n, p);
	RRcount(n, p);
	print(n, p);
	//free(p);
	//p = NULL;
	system("pause");
	return 0;
}



