#define ROW 12
#define COLU 12
#define SET_NUM_MINE 99
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
void play();
void pt_show(char arr[ROW - 2][COLU - 2], int x, int y);//���������
void init_game(char m_arr[ROW][COLU], char s_arr[ROW - 2][COLU - 2], int x, int y);
//��ʼ�������������
void set_mine(char arr[ROW][COLU]);
//����
void print(char arr[ROW][COLU], int x, int y);
//�������
void f_decide(char arr[ROW][COLU], int x, int y);
//�жϵ�һ���ǲ����ף������������
int printf_get(int flag, char arr[ROW][COLU], char show_a[ROW - 2][COLU - 2], int x, int y);
//����ŵ�λ�ò����ף���������Χ����
int win(char arr[ROW-2][COLU-2], int x, int y);