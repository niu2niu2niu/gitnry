/*This is a file to get the input for the GA program*/
#include <stdio.h>
#include <string.h>

#include "global.h"
#include "input_ptts.h"
#include "read_conf.h"

//#define task_num 20
//
//typedef struct
//{
//    int m[6]; // 方案最多 6-1=5 个
//    int r[6][4]; // 每个方案最多 4-1=3 个仪器
//    int time[6]; // 每个方案对应的时间
//
//}method;
//
//typedef struct
//{
//    int t[task_num];
//    int m[task_num];
//
//}chr;
//
method meth[task_num+1], *meth_ptr;
chr chri, *chri_ptr;

int restraint[task_num][task_num];
int restraint_comp[task_num][task_num];
int restraint_comp2[task_num][task_num];

//void input(FILE *rep_ptr)
void input()
{
    if (!strcmp(prob_name,"ptts\n"))
    {
        /***********************方案***********************/
        meth[1].m[1] = 1;  meth[1].m[2] = 2;  meth[1].m[3] = 3;  meth[1].m[4] = 0;  meth[1].m[5] = 0;

        meth[2].m[1] = 1;  meth[2].m[2] = 2;  meth[2].m[3] = 3;  meth[2].m[4] = 4;  meth[2].m[5] = 0;

        meth[3].m[1] = 1;  meth[3].m[2] = 2;  meth[3].m[3] = 0;  meth[3].m[4] = 0;  meth[3].m[5] = 0;

        meth[4].m[1] = 1;  meth[4].m[2] = 2;  meth[4].m[3] = 0;  meth[4].m[4] = 0;  meth[4].m[5] = 0;

        meth[5].m[1] = 1;  meth[5].m[2] = 0;  meth[5].m[3] = 0;  meth[5].m[4] = 0;  meth[5].m[5] = 0;

        meth[6].m[1] = 1;  meth[6].m[2] = 2;  meth[6].m[3] = 3;  meth[6].m[4] = 0;  meth[6].m[5] = 0;

        meth[7].m[1] = 1;  meth[7].m[2] = 2;  meth[7].m[3] = 3;  meth[7].m[4] = 0;  meth[7].m[5] = 0;

        meth[8].m[1] = 1;  meth[8].m[2] = 2;  meth[8].m[3] = 3;  meth[8].m[4] = 0;  meth[8].m[5] = 0;

        meth[9].m[1] = 1;  meth[9].m[2] = 2;  meth[9].m[3] = 3;  meth[9].m[4] = 0;  meth[9].m[5] = 0;

        meth[10].m[1] = 1;  meth[10].m[2] = 2;  meth[10].m[3] = 3;  meth[10].m[4] = 0;  meth[10].m[5] = 0;

        meth[11].m[1] = 1;  meth[11].m[2] = 2;  meth[11].m[3] = 3;  meth[11].m[4] = 0;  meth[11].m[5] = 0;

        meth[12].m[1] = 1;  meth[12].m[2] = 2;  meth[12].m[3] = 3;  meth[12].m[4] = 0;  meth[12].m[5] = 0;

        meth[13].m[1] = 1;  meth[13].m[2] = 2;  meth[13].m[3] = 3;  meth[13].m[4] = 0;  meth[13].m[5] = 0;

        meth[14].m[1] = 1;  meth[14].m[2] = 2;  meth[14].m[3] = 3;  meth[14].m[4] = 0;  meth[14].m[5] = 0;

        meth[15].m[1] = 1;  meth[15].m[2] = 0;  meth[15].m[3] = 0;  meth[15].m[4] = 0;  meth[15].m[5] = 0;

        meth[16].m[1] = 1;  meth[16].m[2] = 2;  meth[16].m[3] = 3;  meth[16].m[4] = 0;  meth[16].m[5] = 0;

        meth[17].m[1] = 1;  meth[17].m[2] = 2;  meth[17].m[3] = 3;  meth[17].m[4] = 0;  meth[17].m[5] = 0;

        meth[18].m[1] = 1;  meth[18].m[2] = 0;  meth[18].m[3] = 0;  meth[18].m[4] = 0;  meth[18].m[5] = 0;

        meth[19].m[1] = 1;  meth[19].m[2] = 2;  meth[19].m[3] = 3;  meth[19].m[4] = 4;  meth[19].m[5] = 0;

        meth[20].m[1] = 1;  meth[20].m[2] = 2;  meth[20].m[3] = 3;  meth[20].m[4] = 0;  meth[20].m[5] = 0;

        /***********************资源***********************/
        meth[1].r[1][1] = 1;  meth[1].r[1][2] = 4;  meth[1].r[1][3] = 0;
        meth[1].r[2][1] = 3;  meth[1].r[2][2] = 5;  meth[1].r[2][3] = 0;
        meth[1].r[3][1] = 6;  meth[1].r[3][2] = 8;  meth[1].r[3][3] = 0;
        meth[1].r[4][1] = 0;  meth[1].r[4][2] = 0;  meth[1].r[4][3] = 0;
        meth[1].r[5][1] = 0;  meth[1].r[5][2] = 0;  meth[1].r[5][3] = 0;

        meth[2].r[1][1] = 2;  meth[2].r[1][2] = 0;  meth[2].r[1][3] = 0;
        meth[2].r[2][1] = 4;  meth[2].r[2][2] = 0;  meth[2].r[2][3] = 0;
        meth[2].r[3][1] = 6;  meth[2].r[3][2] = 0;  meth[2].r[3][3] = 0;
        meth[2].r[4][1] = 7;  meth[2].r[4][2] = 0;  meth[2].r[4][3] = 0;
        meth[2].r[5][1] = 0;  meth[2].r[5][2] = 0;  meth[2].r[5][3] = 0;

        meth[3].r[1][1] = 3;  meth[3].r[1][2] = 0;  meth[3].r[1][3] = 0;
        meth[3].r[2][1] = 5;  meth[3].r[2][2] = 0;  meth[3].r[2][3] = 0;
        meth[3].r[3][1] = 0;  meth[3].r[3][2] = 0;  meth[3].r[3][3] = 0;
        meth[3].r[4][1] = 0;  meth[3].r[4][2] = 0;  meth[3].r[4][3] = 0;
        meth[3].r[5][1] = 0;  meth[3].r[5][2] = 0;  meth[3].r[5][3] = 0;

        meth[4].r[1][1] = 4;  meth[4].r[1][2] = 0;  meth[4].r[1][3] = 0;
        meth[4].r[2][1] = 8;  meth[4].r[2][2] = 0;  meth[4].r[2][3] = 0;
        meth[4].r[3][1] = 0;  meth[4].r[3][2] = 0;  meth[4].r[3][3] = 0;
        meth[4].r[4][1] = 0;  meth[4].r[4][2] = 0;  meth[4].r[4][3] = 0;
        meth[4].r[5][1] = 0;  meth[4].r[5][2] = 0;  meth[4].r[5][3] = 0;

        meth[5].r[1][1] = 7;  meth[5].r[1][2] = 0;  meth[5].r[1][3] = 0;
        meth[5].r[2][1] = 0;  meth[5].r[2][2] = 0;  meth[5].r[2][3] = 0;
        meth[5].r[3][1] = 0;  meth[5].r[3][2] = 0;  meth[5].r[3][3] = 0;
        meth[5].r[4][1] = 0;  meth[5].r[4][2] = 0;  meth[5].r[4][3] = 0;
        meth[5].r[5][1] = 0;  meth[5].r[5][2] = 0;  meth[5].r[5][3] = 0;

        meth[6].r[1][1] = 1;  meth[6].r[1][2] = 4;  meth[6].r[1][3] = 0;
        meth[6].r[2][1] = 3;  meth[6].r[2][2] = 7;  meth[6].r[2][3] = 0;
        meth[6].r[3][1] = 6;  meth[6].r[3][2] = 8;  meth[6].r[3][3] = 0;
        meth[6].r[4][1] = 0;  meth[6].r[4][2] = 0;  meth[6].r[4][3] = 0;
        meth[6].r[5][1] = 0;  meth[6].r[5][2] = 0;  meth[6].r[5][3] = 0;

        meth[7].r[1][1] = 1;  meth[7].r[1][2] = 2;  meth[7].r[1][3] = 0;
        meth[7].r[2][1] = 1;  meth[7].r[2][2] = 7;  meth[7].r[2][3] = 0;
        meth[7].r[3][1] = 3;  meth[7].r[3][2] = 8;  meth[7].r[3][3] = 0;
        meth[7].r[4][1] = 0;  meth[7].r[4][2] = 0;  meth[7].r[4][3] = 0;
        meth[7].r[5][1] = 0;  meth[7].r[5][2] = 0;  meth[7].r[5][3] = 0;

        meth[8].r[1][1] = 1;  meth[8].r[1][2] = 3;  meth[8].r[1][3] = 0;
        meth[8].r[2][1] = 1;  meth[8].r[2][2] = 5;  meth[8].r[2][3] = 0;
        meth[8].r[3][1] = 4;  meth[8].r[3][2] = 7;  meth[8].r[3][3] = 0;
        meth[8].r[4][1] = 0;  meth[8].r[4][2] = 0;  meth[8].r[4][3] = 0;
        meth[8].r[5][1] = 0;  meth[8].r[5][2] = 0;  meth[8].r[5][3] = 0;

        meth[9].r[1][1] = 1;  meth[9].r[1][2] = 4;  meth[9].r[1][3] = 0;
        meth[9].r[2][1] = 3;  meth[9].r[2][2] = 4;  meth[9].r[2][3] = 0;
        meth[9].r[3][1] = 7;  meth[9].r[3][2] = 8;  meth[9].r[3][3] = 0;
        meth[9].r[4][1] = 0;  meth[9].r[4][2] = 0;  meth[9].r[4][3] = 0;
        meth[9].r[5][1] = 0;  meth[9].r[5][2] = 0;  meth[9].r[5][3] = 0;

        meth[10].r[1][1] = 1;  meth[10].r[1][2] = 0;  meth[10].r[1][3] = 0;
        meth[10].r[2][1] = 4;  meth[10].r[2][2] = 0;  meth[10].r[2][3] = 0;
        meth[10].r[3][1] = 8;  meth[10].r[3][2] = 0;  meth[10].r[3][3] = 0;
        meth[10].r[4][1] = 0;  meth[10].r[4][2] = 0;  meth[10].r[4][3] = 0;
        meth[10].r[5][1] = 0;  meth[10].r[5][2] = 0;  meth[10].r[5][3] = 0;

        meth[11].r[1][1] = 2;  meth[11].r[1][2] = 3;  meth[11].r[1][3] = 0;
        meth[11].r[2][1] = 2;  meth[11].r[2][2] = 5;  meth[11].r[2][3] = 0;
        meth[11].r[3][1] = 6;  meth[11].r[3][2] = 7;  meth[11].r[3][3] = 0;
        meth[11].r[4][1] = 0;  meth[11].r[4][2] = 0;  meth[11].r[4][3] = 0;
        meth[11].r[5][1] = 0;  meth[11].r[5][2] = 0;  meth[11].r[5][3] = 0;

        meth[12].r[1][1] = 2;  meth[12].r[1][2] = 0;  meth[12].r[1][3] = 0;
        meth[12].r[2][1] = 5;  meth[12].r[2][2] = 0;  meth[12].r[2][3] = 0;
        meth[12].r[3][1] = 6;  meth[12].r[3][2] = 0;  meth[12].r[3][3] = 0;
        meth[12].r[4][1] = 0;  meth[12].r[4][2] = 0;  meth[12].r[4][3] = 0;
        meth[12].r[5][1] = 0;  meth[12].r[5][2] = 0;  meth[12].r[5][3] = 0;

        meth[13].r[1][1] = 2;  meth[13].r[1][2] = 0;  meth[13].r[1][3] = 0;
        meth[13].r[2][1] = 6;  meth[13].r[2][2] = 0;  meth[13].r[2][3] = 0;
        meth[13].r[3][1] = 8;  meth[13].r[3][2] = 0;  meth[13].r[3][3] = 0;
        meth[13].r[4][1] = 0;  meth[13].r[4][2] = 0;  meth[13].r[4][3] = 0;
        meth[13].r[5][1] = 0;  meth[13].r[5][2] = 0;  meth[13].r[5][3] = 0;

        meth[14].r[1][1] = 3;  meth[14].r[1][2] = 0;  meth[14].r[1][3] = 0;
        meth[14].r[2][1] = 5;  meth[14].r[2][2] = 0;  meth[14].r[2][3] = 0;
        meth[14].r[3][1] = 7;  meth[14].r[3][2] = 0;  meth[14].r[3][3] = 0;
        meth[14].r[4][1] = 0;  meth[14].r[4][2] = 0;  meth[14].r[4][3] = 0;
        meth[14].r[5][1] = 0;  meth[14].r[5][2] = 0;  meth[14].r[5][3] = 0;

        meth[15].r[1][1] = 8;  meth[15].r[1][2] = 0;  meth[15].r[1][3] = 0;
        meth[15].r[2][1] = 0;  meth[15].r[2][2] = 0;  meth[15].r[2][3] = 0;
        meth[15].r[3][1] = 0;  meth[15].r[3][2] = 0;  meth[15].r[3][3] = 0;
        meth[15].r[4][1] = 0;  meth[15].r[4][2] = 0;  meth[15].r[4][3] = 0;
        meth[15].r[5][1] = 0;  meth[15].r[5][2] = 0;  meth[15].r[5][3] = 0;

        meth[16].r[1][1] = 2;  meth[16].r[1][2] = 0;  meth[16].r[1][3] = 0;
        meth[16].r[2][1] = 5;  meth[16].r[2][2] = 0;  meth[16].r[2][3] = 0;
        meth[16].r[3][1] = 8;  meth[16].r[3][2] = 0;  meth[16].r[3][3] = 0;
        meth[16].r[4][1] = 0;  meth[16].r[4][2] = 0;  meth[16].r[4][3] = 0;
        meth[16].r[5][1] = 0;  meth[16].r[5][2] = 0;  meth[16].r[5][3] = 0;

        meth[17].r[1][1] = 1;  meth[17].r[1][2] = 2;  meth[17].r[1][3] = 0;
        meth[17].r[2][1] = 5;  meth[17].r[2][2] = 7;  meth[17].r[2][3] = 0;
        meth[17].r[3][1] = 5;  meth[17].r[3][2] = 8;  meth[17].r[3][3] = 0;
        meth[17].r[4][1] = 0;  meth[17].r[4][2] = 0;  meth[17].r[4][3] = 0;
        meth[17].r[5][1] = 0;  meth[17].r[5][2] = 0;  meth[17].r[5][3] = 0;

        meth[18].r[1][1] = 6;  meth[18].r[1][2] = 0;  meth[18].r[1][3] = 0;
        meth[18].r[2][1] = 0;  meth[18].r[2][2] = 0;  meth[18].r[2][3] = 0;
        meth[18].r[3][1] = 0;  meth[18].r[3][2] = 0;  meth[18].r[3][3] = 0;
        meth[18].r[4][1] = 0;  meth[18].r[4][2] = 0;  meth[18].r[4][3] = 0;
        meth[18].r[5][1] = 0;  meth[18].r[5][2] = 0;  meth[18].r[5][3] = 0;

        meth[19].r[1][1] = 2;  meth[19].r[1][2] = 0;  meth[19].r[1][3] = 0;
        meth[19].r[2][1] = 4;  meth[19].r[2][2] = 0;  meth[19].r[2][3] = 0;
        meth[19].r[3][1] = 5;  meth[19].r[3][2] = 0;  meth[19].r[3][3] = 0;
        meth[19].r[4][1] = 8;  meth[19].r[4][2] = 0;  meth[19].r[4][3] = 0;
        meth[19].r[5][1] = 0;  meth[19].r[5][2] = 0;  meth[19].r[5][3] = 0;

        meth[20].r[1][1] = 3;  meth[20].r[1][2] = 0;  meth[20].r[1][3] = 0;
        meth[20].r[2][1] = 6;  meth[20].r[2][2] = 0;  meth[20].r[2][3] = 0;
        meth[20].r[3][1] = 8;  meth[20].r[3][2] = 0;  meth[20].r[3][3] = 0;
        meth[20].r[4][1] = 0;  meth[20].r[4][2] = 0;  meth[20].r[4][3] = 0;
        meth[20].r[5][1] = 0;  meth[20].r[5][2] = 0;  meth[20].r[5][3] = 0;

        /***********************时间***********************/
        meth[1].time[1] = 2;  meth[1].time[2] = 5;  meth[1].time[3] = 3;  meth[1].time[4] = 0;  meth[1].time[5] = 0;

        meth[2].time[1] = 3;  meth[2].time[2] = 4;  meth[2].time[3] = 3;  meth[2].time[4] = 4;  meth[2].time[5] = 0;

        meth[3].time[1] = 5;  meth[3].time[2] = 5;  meth[3].time[3] = 0;  meth[3].time[4] = 0;  meth[3].time[5] = 0;

        meth[4].time[1] = 22;  meth[4].time[2] = 20;  meth[4].time[3] = 0;  meth[4].time[4] = 0;  meth[4].time[5] = 0;

        meth[5].time[1] = 23;  meth[5].time[2] = 0;  meth[5].time[3] = 0;  meth[5].time[4] = 0;  meth[5].time[5] = 0;

        meth[6].time[1] = 7;  meth[6].time[2] = 8;  meth[6].time[3] = 8;  meth[6].time[4] = 0;  meth[6].time[5] = 0;

        meth[7].time[1] = 2;  meth[7].time[2] = 2;  meth[7].time[3] = 3;  meth[7].time[4] = 0;  meth[7].time[5] = 0;

        meth[8].time[1] = 5;  meth[8].time[2] = 4;  meth[8].time[3] = 2;  meth[8].time[4] = 0;  meth[8].time[5] = 0;

        meth[9].time[1] = 11;  meth[9].time[2] = 13;  meth[9].time[3] = 12;  meth[9].time[4] = 0;  meth[9].time[5] = 0;

        meth[10].time[1] = 9;  meth[10].time[2] = 10;  meth[10].time[3] = 10;  meth[10].time[4] = 0;  meth[10].time[5] = 0;

        meth[11].time[1] = 6;  meth[11].time[2] = 8;  meth[11].time[3] = 8;  meth[11].time[4] = 0;  meth[11].time[5] = 0;

        meth[12].time[1] = 11;  meth[12].time[2] = 13;  meth[12].time[3] = 13;  meth[12].time[4] = 0;  meth[12].time[5] = 0;

        meth[13].time[1] = 4;  meth[13].time[2] = 5;  meth[13].time[3] = 4;  meth[13].time[4] = 0;  meth[13].time[5] = 0;

        meth[14].time[1] = 7;  meth[14].time[2] = 8;  meth[14].time[3] = 8;  meth[14].time[4] = 0;  meth[14].time[5] = 0;

        meth[15].time[1] = 2;  meth[15].time[2] = 0;  meth[15].time[3] = 0;  meth[15].time[4] = 0;  meth[15].time[5] = 0;

        meth[16].time[1] = 9;  meth[16].time[2] = 7;  meth[16].time[3] = 6;  meth[16].time[4] = 0;  meth[16].time[5] = 0;

        meth[17].time[1] = 10;  meth[17].time[2] = 12;  meth[17].time[3] = 11;  meth[17].time[4] = 0;  meth[17].time[5] = 0;

        meth[18].time[1] = 15;  meth[18].time[2] = 0;  meth[18].time[3] = 0;  meth[18].time[4] = 0;  meth[18].time[5] = 0;

        meth[19].time[1] = 8;  meth[19].time[2] = 7;  meth[19].time[3] = 7;  meth[19].time[4] = 6;  meth[19].time[5] = 0;

        meth[20].time[1] = 4;  meth[20].time[2] = 4;  meth[20].time[3] = 5;  meth[20].time[4] = 0;  meth[20].time[5] = 0;

        /*************约束关系******************/
        restraint[2-1][1-1] = 1;// t2 > t1
        restraint[1-1][2-1] = -1;

        restraint[15-1][1-1] = 1;// t15 > t1
        restraint[1-1][15-1] = -1;

        restraint[6-1][3-1] = 1;// t6 > t3
        restraint[3-1][6-1] = -1;

        restraint[11-1][3-1] = 1;// t11 > t3
        restraint[3-1][11-1] = -1;

        restraint[18-1][3-1] = 1;// t18 > t3
        restraint[3-1][18-1] = -1;

        restraint[3-1][4-1] = 1;// t3 > t4
        restraint[4-1][3-1] = -1;

        restraint[14-1][5-1] = 1;// t14 > t5
        restraint[5-1][14-1] = -1;

        restraint[1-1][6-1] = 1;// t1 > t6
        restraint[6-1][1-1] = -1;

        restraint[9-1][6-1] = 1;// t9 > t6
        restraint[6-1][9-1] = -1;

        restraint[19-1][6-1] = 1;// t19 > t6
        restraint[6-1][19-1] = -1;

        restraint[6-1][7-1] = 1;// t6 > t7
        restraint[7-1][6-1] = -1;

        restraint[2-1][9-1] = 1;// t2 > t9
        restraint[9-1][2-1] = -1;

        restraint[14-1][9-1] = 1;// t14 > t9
        restraint[9-1][14-1] = -1;

        restraint[7-1][12-1] = 1;// t7 > t12
        restraint[12-1][7-1] = -1;

        restraint[10-1][12-1] = 1;// t10 > t12
        restraint[12-1][10-1] = -1;

        restraint[19-1][12-1] = 1;// t19 > t12
        restraint[12-1][19-1] = -1;

        restraint[4-1][13-1] = 1;// t4 > t13
        restraint[13-1][4-1] = -1;

        restraint[17-1][13-1] = 1;// t17 > t13
        restraint[13-1][17-1] = -1;

        restraint[14-1][15-1] = 1;// t14 > t15
        restraint[15-1][14-1] = -1;

        restraint[19-1][15-1] = 1;// t19 > t15
        restraint[15-1][19-1] = -1;

        restraint[1-1][17-1] = 1;// t1 > t17
        restraint[17-1][1-1] = -1;

        restraint[9-1][17-1] = 1;// t9 > t17
        restraint[17-1][9-1] = -1;

        restraint[5-1][18-1] = 1;// t5 > t18
        restraint[18-1][5-1] = -1;

        restraint[11-1][19-1] = 1;// t11 > t19
        restraint[19-1][11-1] = -1;

        restraint[16-1][20-1] = 1;// t16 > t20
        restraint[20-1][16-1] = -1;
    }

    int rest_i=0;
    int rest_j=0;
    int rest_k=0;
    int rest_flag=1;
    //计算完全约束矩阵
    for (rest_i = 0;rest_i<task_num;rest_i++)
        for (rest_j = 0;rest_j<task_num;rest_j++)
            restraint_comp[rest_i][rest_j] = restraint[rest_i][rest_j];//初始化完全约束矩阵

    while (rest_flag)//若完全约束矩阵改变，则继续改变
    {
        rest_flag = 1;
        for (rest_i = 0;rest_i<task_num;rest_i++)
            for (rest_j = 0;rest_j<task_num;rest_j++)//完全约束矩阵改变前先暂存入完全约束矩阵2中                       
                restraint_comp2[rest_i][rest_j] = restraint_comp[rest_i][rest_j];

        for (rest_i = 0;rest_i<task_num;rest_i++)
        {
            for (rest_j = 0;rest_j<task_num;rest_j++)//遍历完全约束矩阵                     
            {
                if (restraint_comp[rest_i][rest_j] == 1)//将下属约束中的子约束关系加入i的完全约束矩阵中
                {
                    for (rest_k = 0;rest_k<task_num;rest_k++)
                    {
                        if (restraint_comp[rest_j][rest_k] == 1)
                        {
                            restraint_comp[rest_i][rest_k] = 1;
                            restraint_comp[rest_k][rest_i] = -1;
                        }
                    }
                }
            }
        }
        for (rest_i = 0;rest_i<task_num;rest_i++)
            for (rest_j = 0;rest_j<task_num;rest_j++)
                if (restraint_comp2[rest_i][rest_j] == restraint_comp[rest_i][rest_j])
                    rest_flag++;
        if (rest_flag == task_num*task_num + 1)
            rest_flag = 0;

    }//while循环结束时，完全约束矩阵(2)已不再变化
    return;
}
