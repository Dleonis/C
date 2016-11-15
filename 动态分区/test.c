#define _CRT_SECURE_NO_WARNINGS
#include "memory.h"
int main()
{
	Node *cop = NULL;
	int nums = 0;
	int i = 0;
	int start = 0;
	int end = 0;
flag:
	p = init(p);
	cop = p;
	mnue();
	scanf("%d", &i);
	while (1)
	{
		switch (i)
		{
			case 1:
				FirstFit(p);
				mnue();
				break;
			case 2:
				NextFit(p);
				mnue();
				break;
			case 3:
				BestFit(p);
				mnue();
				break;
			case 4:
				WorstFit(p);
				mnue();
				break;
			case 5:
				goto flag;
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("«Î÷ÿ–¬ ‰»Î\n");
		}	
		scanf("%d", &i);
	}	
	system("pause");
	return 0;
}



