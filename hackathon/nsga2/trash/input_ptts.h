#include <stdio.h>
#include <string.h>

#include "global.h"

#define task_num 20

typedef struct
{
    int m[6]; // 方案最多 6-1=5 个
    int r[6][4]; // 每个方案最多 4-1=3 个仪器
    int time[6]; // 每个方案对应的时间

}method;

typedef struct
{
    int t[task_num];
    int m[task_num];

}chr;

extern method meth[task_num+1], *meth_ptr;
extern chr chri, *chri_ptr;

extern int restraint[task_num][task_num];
extern int restraint_comp[task_num][task_num];
extern int restraint_comp2[task_num][task_num];

void input();
