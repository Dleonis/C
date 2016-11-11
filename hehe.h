
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TIME_SLICE 1
typedef struct PCB{
	char name[4];     
	int StartTime;
	int RunTime;
	int EndTime;
	int TurnTime;
	int WiteTime;
	double TurnWeiTime;
	struct PCB *next;
}pcb;
pcb *p;
pcb *init(int n,pcb *p);
pcb *Fcfs(int n, pcb *p);
pcb *Sjf(int n, pcb *p);
pcb *RoundR(int n, pcb*p);
pcb *count(int n, pcb *p);
pcb *RRcount(int n, pcb *p);
void print(int n, pcb *p);