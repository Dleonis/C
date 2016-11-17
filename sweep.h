#define ROW 12
#define COLU 12
#define SET_NUM_MINE 99
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
void play();
void pt_show(char arr[ROW - 2][COLU - 2], int x, int y);//输出排雷阵
void init_game(char m_arr[ROW][COLU], char s_arr[ROW - 2][COLU - 2], int x, int y);
//初始化雷阵和排雷阵
void set_mine(char arr[ROW][COLU]);
//放雷
void print(char arr[ROW][COLU], int x, int y);
//输出雷阵
void f_decide(char arr[ROW][COLU], int x, int y);
//判断第一次是不是雷，如果是移走它
int printf_get(int flag, char arr[ROW][COLU], char show_a[ROW - 2][COLU - 2], int x, int y);
//如果排的位置不是雷，计算它周围的雷
int win(char arr[ROW-2][COLU-2], int x, int y);