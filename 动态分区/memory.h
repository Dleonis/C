#ifndef _MEMORYH_
#define _CRT_SECURE_NO_WARNINGS
#define _MEMORYH_
#include<stdio.h>
#include<malloc.h>
#include<windows.h>

#define MIN 1

typedef struct NODE{
	int start;
	int end;
	int size;
	int flag;
	struct NODE *next;
}Node;
Node *p;

Node *init(Node *p);
void print(Node *p);
void FF(Node *p);
Node *NF(Node *p);
void BF(Node *p);
void WF(Node *p);
void myfree(Node *p);
void FirstFit(Node *p);
void NextFit(Node *p);
void BestFit(Node *p);
void WorstFit(Node *p);
void menu();
#endif