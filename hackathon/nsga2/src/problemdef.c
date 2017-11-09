/* Test problem definitions */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "global.h"
# include "rand.h"
# include "read_conf.h"

# define sch1
# define sch2
# define fon 
# define kur 
# define pol 
# define vnt 
# define zdt1
# define zdt2
# define zdt3
# define zdt4
# define zdt5
# define zdt6
# define bnh 
# define osy 
# define srn 
# define tnk 
# define ctp1 
# define ctp2
# define ctp3
# define ctp4
# define ctp5
# define ctp6
# define ctp7
# define ctp8

#define task_num 20

typedef struct
{
    int m[6];
    int r[6][4];
    int time[6];

}method;

typedef struct
{
    int t[task_num];
    int m[task_num];

}chr;

/*  Test problem SCH1
# of real variables = 1
# of bin variables = 0
# of objectives = 2
# of constraints = 0
*/

void input_ptts(method * meth, int * restraint_comp)
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

    int restraint[task_num][task_num];

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

    int rest_i=0;
    int rest_j=0;
    int rest_k=0;
    int rest_flag=1;
    int restraint_comp2[task_num][task_num];
    //计算完全约束矩阵
    for (rest_i = 0;rest_i<task_num;rest_i++)
        for (rest_j = 0;rest_j<task_num;rest_j++)
            restraint_comp[rest_i * task_num + rest_j] = restraint[rest_i][rest_j];//初始化完全约束矩阵

    while (rest_flag)//若完全约束矩阵改变，则继续改变
    {
        rest_flag = 1;
        for (rest_i = 0;rest_i<task_num;rest_i++)
            for (rest_j = 0;rest_j<task_num;rest_j++)//完全约束矩阵改变前先暂存入完全约束矩阵2中                       
                restraint_comp2[rest_i][rest_j] = restraint_comp[rest_i * task_num + rest_j];

        for (rest_i = 0;rest_i<task_num;rest_i++)
        {
            for (rest_j = 0;rest_j<task_num;rest_j++)//遍历完全约束矩阵                     
            {
                if (restraint_comp[rest_i * task_num + rest_j] == 1)//将下属约束中的子约束关系加入i的完全约束矩阵中
                {
                    for (rest_k = 0;rest_k<task_num;rest_k++)
                    {
                        if (restraint_comp[rest_j * task_num + rest_k] == 1)
                        {
                            restraint_comp[rest_i * task_num + rest_k] = 1;
                            restraint_comp[rest_k * task_num + rest_i] = -1;
                        }
                    }
                }
            }
        }
        for (rest_i = 0;rest_i<task_num;rest_i++)
            for (rest_j = 0;rest_j<task_num;rest_j++)
                if (restraint_comp2[rest_i][rest_j] == restraint_comp[rest_i * task_num + rest_j])
                    rest_flag++;
        if (rest_flag == task_num*task_num + 1)
            rest_flag = 0;

    }//while循环结束时，完全约束矩阵(2)已不再变化
}

#ifdef sch1
void test_problem_sch1 (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    obj[0] = pow(xreal[0],2.0);
    obj[1] = pow((xreal[0]-2.0),2.0);
    return;
}
#endif

/*  Test problem SCH2
# of real variables = 1
# of bin variables = 0
# of objectives = 2
# of constraints = 0
*/

#ifdef sch2
void test_problem_sch2 (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    if (xreal[0]<=1.0)
    {
        obj[0] = -xreal[0];
        obj[1] = pow((xreal[0]-5.0),2.0);
        return;
    }
    if (xreal[0]<=3.0)
    {
        obj[0] = xreal[0]-2.0;
        obj[1] = pow((xreal[0]-5.0),2.0);
        return;
    }
    if (xreal[0]<=4.0)
    {
        obj[0] = 4.0-xreal[0];
        obj[1] = pow((xreal[0]-5.0),2.0);
        return;
    }
    obj[0] = xreal[0]-4.0;
    obj[1] = pow((xreal[0]-5.0),2.0);
    return;
}
#endif

/*  Test problem FON
# of real variables = n
# of bin variables = 0
# of objectives = 2
# of constraints = 0
*/

#ifdef fon
void test_problem_fon (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    double s1, s2;
    int i;
    s1 = s2 = 0.0;
    for (i=0; i<nreal; i++)
    {
        s1 += pow((xreal[i]-(1.0/sqrt((double)nreal))),2.0);
        s2 += pow((xreal[i]+(1.0/sqrt((double)nreal))),2.0);
    }
    obj[0] = 1.0 - exp(-s1);
    obj[1] = 1.0 - exp(-s2);
    return;
}
#endif

/*  Test problem KUR
# of real variables = 3
# of bin variables = 0
# of objectives = 2
# of constraints = 0
*/

#ifdef kur
void test_problem_kur (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    int i;
    double res1, res2;
    res1 = -0.2*sqrt((xreal[0]*xreal[0]) + (xreal[1]*xreal[1]));
    res2 = -0.2*sqrt((xreal[1]*xreal[1]) + (xreal[2]*xreal[2]));
    obj[0] = -10.0*( exp(res1) + exp(res2));
    obj[1] = 0.0;
    for (i=0; i<3; i++)
    {
        obj[1] += pow(fabs(xreal[i]),0.8) + 5.0*sin(pow(xreal[i],3.0));
    }
    return;
}
#endif

/*  Test problem POL
# of real variables = 2
# of bin variables = 0
# of objectives = 2
# of constraints = 0
*/

#ifdef pol
void test_problem_pol (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    double a1, a2, b1, b2;
    a1 = 0.5*sin(1.0) - 2.0*cos(1.0) + sin(2.0) - 1.5*cos(2.0);
    a2 = 1.5*sin(1.0) - cos(1.0) + 2.0*sin(2.0) - 0.5*cos(2.0);
    b1 = 0.5*sin(xreal[0]) - 2.0*cos(xreal[0]) + sin(xreal[1]) - 1.5*cos(xreal[1]);
    b2 = 1.5*sin(xreal[0]) - cos(xreal[0]) + 2.0*sin(xreal[1]) - 0.5*cos(xreal[1]);
    obj[0] = 1.0 + pow((a1-b1),2.0) + pow((a2-b2),2.0);
    obj[1] = pow((xreal[0]+3.0),2.0) + pow((xreal[1]+1.0),2.0);
    return;
}
#endif

/*  Test problem VNT
# of real variables = 2
# of bin variables = 0
# of objectives = 3
# of constraints = 0
*/

#ifdef vnt
void test_problem_vnt (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    obj[0] = 0.5*(xreal[0]*xreal[0] + xreal[1]*xreal[1]) + sin(xreal[0]*xreal[0] + xreal[1]*xreal[1]);
    obj[1] = (pow((3.0*xreal[0] - 2.0*xreal[1] + 4.0),2.0))/8.0 + (pow((xreal[0]-xreal[1]+1.0),2.0))/27.0 + 15.0;
    obj[2] = 1.0/(xreal[0]*xreal[0] + xreal[1]*xreal[1] + 1.0) - 1.1*exp(-(xreal[0]*xreal[0] + xreal[1]*xreal[1]));
    return;
}
#endif

/*  Test problem ZDT1
# of real variables = 30
# of bin variables = 0
# of objectives = 2
# of constraints = 0
*/

#ifdef zdt1
void test_problem_zdt1 (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    double f1, f2, g, h;
    int i;
    f1 = xreal[0];
    g = 0.0;
    for (i=1; i<30; i++)
    {
        g += xreal[i];
    }
    g = 9.0*g/29.0;
    g += 1.0;
    h = 1.0 - sqrt(f1/g);
    f2 = g*h;
    obj[0] = f1;
    obj[1] = f2;
    return;
}
#endif

/*  Test problem ZDT2
# of real variables = 30
# of bin variables = 0
# of objectives = 2
# of constraints = 0
*/

#ifdef zdt2
void test_problem_zdt2 (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    double f1, f2, g, h;
    int i;
    f1 = xreal[0];
    g = 0.0;
    for (i=1; i<30; i++)
    {
        g += xreal[i];
    }
    g = 9.0*g/29.0;
    g += 1.0;
    h = 1.0 - pow((f1/g),2.0);
    f2 = g*h;
    obj[0] = f1;
    obj[1] = f2;
    return;
}
#endif

/*  Test problem ZDT3
# of real variables = 30
# of bin variables = 0
# of objectives = 2
# of constraints = 0
*/

#ifdef zdt3
void test_problem_zdt3 (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    double f1, f2, g, h;
    int i;
    f1 = xreal[0];
    g = 0.0;
    for (i=1; i<30; i++)
    {
        g += xreal[i];
    }
    g = 9.0*g/29.0;
    g += 1.0;
    h = 1.0 - sqrt(f1/g) - (f1/g)*sin(10.0*PI*f1);
    f2 = g*h;
    obj[0] = f1;
    obj[1] = f2;
    return;
}
#endif

/*  Test problem ZDT4
# of real variables = 10
# of bin variables = 0
# of objectives = 2
# of constraints = 0
*/

#ifdef zdt4
void test_problem_zdt4 (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    double f1, f2, g, h;
    int i;
    f1 = xreal[0];
    g = 0.0;
    for (i=1; i<10; i++)
    {
        g += xreal[i]*xreal[i] - 10.0*cos(4.0*PI*xreal[i]);
    }
    g += 91.0;
    h = 1.0 - sqrt(f1/g);
    f2 = g*h;
    obj[0] = f1;
    obj[1] = f2;
    return;
}
#endif

/*  Test problem ZDT5
# of real variables = 0
# of bin variables = 11
# of bits for binvar1 = 30
# of bits for binvar2-11 = 5
# of objectives = 2
# of constraints = 0
*/

#ifdef zdt5
void test_problem_zdt5 (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    int i, j;
    int u[11];
    int v[11];
    double f1, f2, g, h;
    for (i=0; i<11; i++)
    {
        u[i] = 0;
    }
    for (j=0; j<30; j++)
    {
        if (gene[0][j] == 1)
        {
            u[0]++;
        }
    }
    for (i=1; i<11; i++)
    {
        for (j=0; j<4; j++)
        {
            if (gene[i][j] == 1)
            {
                u[i]++;
            }
        }
    }
    f1 = 1.0 + u[0];
    for (i=1; i<11; i++)
    {
        if (u[i] < 5)
        {
            v[i] = 2 + u[i];
        }
        else
        {
            v[i] = 1;
        }
    }
    g = 0;
    for (i=1; i<11; i++)
    {
        g += v[i];
    }
    h = 1.0/f1;
    f2 = g*h;
    obj[0] = f1;
    obj[1] = f2;
    return;
}
#endif

/*  Test problem ZDT6
# of real variables = 10
# of bin variables = 0
# of objectives = 2
# of constraints = 0
*/

#ifdef zdt6
void test_problem_zdt6 (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    double f1, f2, g, h;
    int i;
    f1 = 1.0 - ( exp(-4.0*xreal[0]) ) * pow( (sin(6.0*PI*xreal[0])),6.0 );
    g = 0.0;
    for (i=1; i<10; i++)
    {
        g += xreal[i];
    }
    g = g/9.0;
    g = pow(g,0.25);
    g = 1.0 + 9.0*g;
    h = 1.0 - pow((f1/g),2.0);
    f2 = g*h;
    obj[0] = f1;
    obj[1] = f2;
    return;
}
#endif

/*  Test problem BNH
# of real variables = 2
# of bin variables = 0
# of objectives = 2
# of constraints = 2
*/

#ifdef bnh
void test_problem_bnh (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    obj[0] = 4.0*(xreal[0]*xreal[0] + xreal[1]*xreal[1]);
    obj[1] = pow((xreal[0]-5.0),2.0) + pow((xreal[1]-5.0),2.0);
    constr[0] = 1.0 - (pow((xreal[0]-5.0),2.0) + xreal[1]*xreal[1])/25.0;
    constr[1] = (pow((xreal[0]-8.0),2.0) + pow((xreal[1]+3.0),2.0))/7.7 - 1.0;
    return;
}
#endif

/*  Test problem OSY
# of real variables = 6
# of bin variables = 0
# of objectives = 2
# of constraints = 6
*/

#ifdef osy
void test_problem_osy (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    obj[0] = -(25.0*pow((xreal[0]-2.0),2.0) + pow((xreal[1]-2.0),2.0) + pow((xreal[2]-1.0),2.0) + pow((xreal[3]-4.0),2.0) + pow((xreal[4]-1.0),2.0));
    obj[1] = xreal[0]*xreal[0] +  xreal[1]*xreal[1] + xreal[2]*xreal[2] + xreal[3]*xreal[3] + xreal[4]*xreal[4] + xreal[5]*xreal[5];
    constr[0] = (xreal[0]+xreal[1])/2.0 - 1.0;
    constr[1] = 1.0 - (xreal[0]+xreal[1])/6.0;
    constr[2] = 1.0 - xreal[1]/2.0 + xreal[0]/2.0;
    constr[3] = 1.0 - xreal[0]/2.0 + 3.0*xreal[1]/2.0;
    constr[4] = 1.0 - (pow((xreal[2]-3.0),2.0))/4.0 - xreal[3]/4.0;
    constr[5] = (pow((xreal[4]-3.0),2.0))/4.0 + xreal[5]/4.0 - 1.0;
    return;
}
#endif

/*  Test problem SRN
# of real variables = 2
# of bin variables = 0
# of objectives = 2
# of constraints = 2
*/

#ifdef srn
void test_problem_srn (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    obj[0] = 2.0 + pow((xreal[0]-2.0),2.0) + pow((xreal[1]-1.0),2.0);
    obj[1] = 9.0*xreal[0] - pow((xreal[1]-1.0),2.0);
    constr[0] = 1.0 - (pow(xreal[0],2.0) + pow(xreal[1],2.0))/225.0;
    constr[1] = 3.0*xreal[1]/10.0 - xreal[0]/10.0 - 1.0;
    return;
}
#endif

/*  Test problem TNK
# of real variables = 2
# of bin variables = 0
# of objectives = 2
# of constraints = 2
*/

#ifdef tnk
void test_problem_tnk (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    obj[0] = xreal[0];
    obj[1] = xreal[1];
    if (xreal[1] == 0.0)
    {
        constr[0] = -1.0;
    }
    else
    {
        constr[0] = xreal[0]*xreal[0] + xreal[1]*xreal[1] - 0.1*cos(16.0*atan(xreal[0]/xreal[1])) - 1.0;
    }
    constr[1] = 1.0 - 2.0*pow((xreal[0]-0.5),2.0) + 2.0*pow((xreal[1]-0.5),2.0);
    return;
}
#endif

/*  Test problem CTP1
# of real variables = 2
# of bin variables = 0
# of objectives = 2
# of constraints = 2
*/

#ifdef ctp1
void test_problem_ctp1 (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    double g;
    g = 1.0 + xreal[1];
    obj[0] = xreal[0];
    obj[1] = g*exp(-obj[0]/g);
    constr[0] = obj[1]/(0.858*exp(-0.541*obj[0]))-1.0;
    constr[1] = obj[1]/(0.728*exp(-0.295*obj[0]))-1.0;
    return;
}
#endif

/*  Test problem CTP2
# of real variables = 2
# of bin variables = 0
# of objectives = 2
# of constraints = 1
*/

#ifdef ctp2
void test_problem_ctp2 (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    double g;
    double theta, a, b, c, d, e;
    double exp1, exp2;
    theta = -0.2*PI;
    a = 0.2;
    b = 10.0;
    c = 1.0;
    d = 6.0;
    e = 1.0;
    g = 1.0 + xreal[1];
    obj[0] = xreal[0];
    obj[1] = g*(1.0  - sqrt(obj[0]/g));
    exp1 = (obj[1]-e)*cos(theta) - obj[0]*sin(theta);
    exp2 = (obj[1]-e)*sin(theta) + obj[0]*cos(theta);
    exp2 = b*PI*pow(exp2,c);
    exp2 = fabs(sin(exp2));
    exp2 = a*pow(exp2,d);
    constr[0] = exp1/exp2 - 1.0;
    return;
}
#endif

/*  Test problem CTP3
# of real variables = 2
# of bin variables = 0
# of objectives = 2
# of constraints = 1
*/

#ifdef ctp3
void test_problem_ctp3 (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    double g;
    double theta, a, b, c, d, e;
    double exp1, exp2;
    theta = -0.2*PI;
    a = 0.1;
    b = 10.0;
    c = 1.0;
    d = 0.5;
    e = 1.0;
    g = 1.0 + xreal[1];
    obj[0] = xreal[0];
    obj[1] = g*(1.0  - sqrt(obj[0]/g));
    exp1 = (obj[1]-e)*cos(theta) - obj[0]*sin(theta);
    exp2 = (obj[1]-e)*sin(theta) + obj[0]*cos(theta);
    exp2 = b*PI*pow(exp2,c);
    exp2 = fabs(sin(exp2));
    exp2 = a*pow(exp2,d);
    constr[0] = exp1/exp2 - 1.0;
    return;
}
#endif

/*  Test problem CTP4
# of real variables = 2
# of bin variables = 0
# of objectives = 2
# of constraints = 1
*/

#ifdef ctp4
void test_problem_ctp4 (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    double g;
    double theta, a, b, c, d, e;
    double exp1, exp2;
    theta = -0.2*PI;
    a = 0.75;
    b = 10.0;
    c = 1.0;
    d = 0.5;
    e = 1.0;
    g = 1.0 + xreal[1];
    obj[0] = xreal[0];
    obj[1] = g*(1.0  - sqrt(obj[0]/g));
    exp1 = (obj[1]-e)*cos(theta) - obj[0]*sin(theta);
    exp2 = (obj[1]-e)*sin(theta) + obj[0]*cos(theta);
    exp2 = b*PI*pow(exp2,c);
    exp2 = fabs(sin(exp2));
    exp2 = a*pow(exp2,d);
    constr[0] = exp1/exp2 - 1.0;
    return;
}
#endif

/*  Test problem CTP5
# of real variables = 2
# of bin variables = 0
# of objectives = 2
# of constraints = 1
*/

#ifdef ctp5
void test_problem_ctp5 (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    double g;
    double theta, a, b, c, d, e;
    double exp1, exp2;
    theta = -0.2*PI;
    a = 0.1;
    b = 10.0;
    c = 2.0;
    d = 0.5;
    e = 1.0;
    g = 1.0 + xreal[1];
    obj[0] = xreal[0];
    obj[1] = g*(1.0  - sqrt(obj[0]/g));
    exp1 = (obj[1]-e)*cos(theta) - obj[0]*sin(theta);
    exp2 = (obj[1]-e)*sin(theta) + obj[0]*cos(theta);
    exp2 = b*PI*pow(exp2,c);
    exp2 = fabs(sin(exp2));
    exp2 = a*pow(exp2,d);
    constr[0] = exp1/exp2 - 1.0;
    return;
}
#endif

/*  Test problem CTP6
# of real variables = 2
# of bin variables = 0
# of objectives = 2
# of constraints = 1
*/

#ifdef ctp6
void test_problem_ctp6 (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    double g;
    double theta, a, b, c, d, e;
    double exp1, exp2;
    theta = 0.1*PI;
    a = 40.0;
    b = 0.5;
    c = 1.0;
    d = 2.0;
    e = -2.0;
    g = 1.0 + xreal[1];
    obj[0] = xreal[0];
    obj[1] = g*(1.0  - sqrt(obj[0]/g));
    exp1 = (obj[1]-e)*cos(theta) - obj[0]*sin(theta);
    exp2 = (obj[1]-e)*sin(theta) + obj[0]*cos(theta);
    exp2 = b*PI*pow(exp2,c);
    exp2 = fabs(sin(exp2));
    exp2 = a*pow(exp2,d);
    constr[0] = exp1/exp2 - 1.0;
    return;
}
#endif

/*  Test problem CTP7
# of real variables = 2
# of bin variables = 0
# of objectives = 2
# of constraints = 1
*/

#ifdef ctp7
void test_problem_ctp7 (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    double g;
    double theta, a, b, c, d, e;
    double exp1, exp2;
    theta = -0.05*PI;
    a = 40.0;
    b = 5.0;
    c = 1.0;
    d = 6.0;
    e = 0.0;
    g = 1.0 + xreal[1];
    obj[0] = xreal[0];
    obj[1] = g*(1.0  - sqrt(obj[0]/g));
    exp1 = (obj[1]-e)*cos(theta) - obj[0]*sin(theta);
    exp2 = (obj[1]-e)*sin(theta) + obj[0]*cos(theta);
    exp2 = b*PI*pow(exp2,c);
    exp2 = fabs(sin(exp2));
    exp2 = a*pow(exp2,d);
    constr[0] = exp1/exp2 - 1.0;
    return;
}
#endif

/*  Test problem CTP8
# of real variables = 2
# of bin variables = 0
# of objectives = 2
# of constraints = 2
*/

#ifdef ctp8
void test_problem_ctp8 (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    double g;
    double theta, a, b, c, d, e;
    double exp1, exp2;
    g = 1.0 + xreal[1];
    obj[0] = xreal[0];
    obj[1] = g*(1.0  - sqrt(obj[0]/g));
    theta = 0.1*PI;
    a = 40.0;
    b = 0.5;
    c = 1.0;
    d = 2.0;
    e = -2.0;
    exp1 = (obj[1]-e)*cos(theta) - obj[0]*sin(theta);
    exp2 = (obj[1]-e)*sin(theta) + obj[0]*cos(theta);
    exp2 = b*PI*pow(exp2,c);
    exp2 = fabs(sin(exp2));
    exp2 = a*pow(exp2,d);
    constr[0] = exp1/exp2 - 1.0;
    theta = -0.05*PI;
    a = 40.0;
    b = 2.0;
    c = 1.0;
    d = 6.0;
    e = 0.0;
    exp1 = (obj[1]-e)*cos(theta) - obj[0]*sin(theta);
    exp2 = (obj[1]-e)*sin(theta) + obj[0]*cos(theta);
    exp2 = b*PI*pow(exp2,c);
    exp2 = fabs(sin(exp2));
    exp2 = a*pow(exp2,d);
    constr[1] = exp1/exp2 - 1.0;
    return;
}
#endif

void test_problem_ptts(double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    method meth[task_num+1];
    int restraint_comp[task_num][task_num];

    input_ptts(meth, (int *)restraint_comp);
    cal_obj(xreal, xbin, gene, obj, constr, meth, restraint_comp);
}

void cal_obj(double *xreal, double *xbin, int **gene, double *obj, double *constr,
        method * meth, int * restraint_comp)
{
    chr chri;
    double f[2];
    double *x = xreal;
    int i,j,k,x_i,x_j,chri_i,chri_j,chri_k,r_i,r_j,r_k;
    int m_amount_based_on_t[task_num];//存放对应任务序列的方案可选总数
    int parallel_r[4*task_num] = {0};//变量含义参见matlab程序
    int r[4*task_num] = {0};
    int r_constraint = 0;
    int start = 0;
    int lmd[task_num] = {0};
    int K = 0;//初始化并行步数
    int time[task_num] = {0};
    int r_time[4*task_num] = {0};
    int parallel_time[task_num] = {0};
    int parallel_instrument[task_num] = {0};
    int parallel_time_max[task_num] = {0};
    int max_r_time = 0;
    int t_time[task_num] = {0};//初始化记录任务开始时间的数组,数组的列是任务号
    int t_index[task_num] = {0};//将1~task_num个任务在染色体中的下标记录在t_index数组中

    int dag[task_num][task_num+1] = {0};//定义有向无环图DAG，为拓扑排序准备
    int zero_indegree[task_num] = {0};//存放入度为0的任务编号

    f[0] = 0;
    f[1] = 0;
    r_constraint = 0;
    start = 0;
    K = 0;
    max_r_time = 0;
    for (x_i = 0;x_i < 4*task_num;x_i++)
    {
        parallel_r[x_i] = 0;//变量含义参见matlab程序
        r[x_i] = 0;
        r_time[x_i] = 0;
    }
    for (x_i = 0;x_i < task_num;x_i++)
    {
        lmd[x_i] = 0;
        time[x_i] = 0;
        parallel_time[x_i] = 0;
        parallel_instrument[x_i] = 0;
        parallel_time_max[x_i] = 0;
        t_time[x_i] = 0;
    }
    for (x_i = 0;x_i < task_num;x_i++)//初始化图为空图
    {
        for (x_j = 0;x_j < task_num+1;x_j++)
        {
            dag[x_i][x_j] = 0;
        }
    }
    for (x_i = 0;x_i < task_num;x_i++)//初始化图为约束图
    {
        for (x_j = 0;x_j < task_num;x_j++)
        {
            dag[x_i][x_j] = restraint_comp[x_i * task_num + x_j];
            if (dag[x_i][x_j] == -1)
            {
                dag[x_i][task_num]++;
            }
        }
    }
    /******解码*******/
    //x[0] = 0.66666;
    //x[1] = 0.22222;
    //x[2] = 0.33333;
    //x[3] = 0.44444;
    //x[4] = 0.11111;
    //x[5] = 0.23558;

    //初始化
    for (chri_i=0;chri_i<task_num;chri_i++)
    {
        chri.t[chri_i] = 1;
        chri.m[chri_i] = 0;
    }

    //得到任务序列
    //for (chri_i=0;chri_i<task_num;chri_i++)
    //  for (chri_j=0;chri_j<task_num;chri_j++)
    //      if (x[chri_j]<x[chri_i])
    //          chri.t[chri_i]++;//chri.t中放的是任务号
    for (chri_i=0;chri_i<task_num;chri_i++)//求任务序列
    {
        x_j = 0;//设置zero_indegree数组下标
        for (x_i = 0;x_i < task_num;x_i++)
        {
            if (dag[x_i][task_num] == 0)//记录入度为0的任务编号到zero_indegree
            {
                zero_indegree[x_j] = x_i;
                x_j++;
            }
        }
        chri.t[chri_i] = zero_indegree[0];//先将第一个入度为0的任务放到该位置
        for (x_i = 0;x_i < x_j;x_i++)//遍历zero_indegree数组
        {
            if (x[zero_indegree[x_i]] > x[chri.t[chri_i]])
            {
                //将权值最高的入度为0的任务放到该位置
                chri.t[chri_i] = zero_indegree[x_i];
            }
        }
        dag[chri.t[chri_i]][task_num]--;
        for (x_i = 0;x_i < task_num;x_i++)
        {
            if (dag[x_i][chri.t[chri_i]] == -1)
                dag[x_i][task_num]--;
        }
    }
    for (chri_i=0;chri_i<task_num;chri_i++)
        chri.t[chri_i]++;

    //得到方案号
    for (chri_i=0;chri_i<task_num;chri_i++)
    {
        chri_k = 1;
        while (meth[chri.t[chri_i]].m[chri_k])
        {
            chri_k++;
        }
        m_amount_based_on_t[chri_i] = chri_k-1;
        chri.m[chri_i] = (int)(x[chri_i]*10)%m_amount_based_on_t[chri_i]+1;
    }

    /*chri.t[0] = 1;
      chri.t[1] = 2;
      chri.t[2] = 3;
      chri.t[3] = 4;
      chri.t[4] = 5;
      chri.t[5] = 6;

      chri.m[0] = 1;
      chri.m[1] = 1;
      chri.m[2] = 1;
      chri.m[3] = 1;
      chri.m[4] = 1;
      chri.m[5] = 1;
    */

    /********求目标函数*********/
    for (chri_i=0;chri_i<task_num;chri_i++)//遍历所有任务
    {
        //先按照资源冲突设置任务开始时间    
        chri_k = 0;
        max_r_time = 0;
        while (meth[chri.t[chri_i]].r[chri.m[chri_i]][chri_k+1])//求资源被占用的最大时间
        {                                             
            if (max_r_time < r_time[meth[chri.t[chri_i]].r[chri.m[chri_i]][chri_k+1]])
                max_r_time = r_time[meth[chri.t[chri_i]].r[chri.m[chri_i]][chri_k+1]];
            chri_k++;
        }
        t_time[chri.t[chri_i]-1] =max_r_time;

        //再按照约束设置任务开始时间
        for (chri_j=0;chri_j<chri_i+1;chri_j++)//遍历第i个任务之前的任务
            //若存在约束关系，且目前的开始时间比存在约束关系的任务的完成时间短，
            //则将该任务的开始时间更新为存在约束关系的任务的完成时间
        {
            if (restraint_comp[(chri.t[chri_i]-1) * task_num + (chri.t[chri_j]-1)]!=0 &&
                    t_time[chri.t[chri_i]-1] < t_time[chri.t[chri_j]-1] + meth[chri.t[chri_j]].time[chri.m[chri_j]])
            {
                t_time[chri.t[chri_i]-1] = t_time[chri.t[chri_j]-1] + meth[chri.t[chri_j]].time[chri.m[chri_j]];
            }
        }

        //计算并行步数
        chri_k = 0;
        for (chri_j=0;chri_j<chri_i+1;chri_j++)//遍历第i个任务之前的任务
        {
            if (t_time[chri.t[chri_j]-1] != t_time[chri.t[chri_i]-1])
                chri_k++;
        }
        if (chri_k == chri_i)//如果在任务i之前的所有任务中没有和其开始时间相同的任务，则并行步数加1
            K++;                                    

        //修正仪器时间
        chri_j = 0;
        while (meth[chri.t[chri_i]].r[chri.m[chri_i]][chri_j+1])
        {
            r_time[meth[chri.t[chri_i]].r[chri.m[chri_i]][chri_j+1]]
                =t_time[chri.t[chri_i]-1] + meth[chri.t[chri_i]].time[chri.m[chri_i]];
            chri_j++;
        }
    }

    //目标函数1是最大仪器占用时间，即测试时间
    //f[0] = 0;
    f[0] = r_time[0];
    for (chri_k=0;chri_k<4*task_num;chri_k++)
        if (f[0] < r_time[chri_k])
            f[0] = r_time[chri_k];

    //目标函数2为所有机器的各步平均负荷最小
    //f[1] = 0;                                                             
    //for (chri_i=0;chri_i<task_num;chri_i++)
    //{
    //  //记录任务占用资源总数
    //  chri_k = 0;
    //  while (meth[chri.t[chri_i]].r[chri.m[chri_i]][chri_k+1])
    //      chri_k++;
    //  //计算总负载
    //  parallel_time[0] = parallel_time[0] + meth[chri.t[chri_i]].time[chri.m[chri_i]]*(chri_k);
    //}
    //f[1] = parallel_time[0] / (float)K;//计算各步平均负载

    //目标函数3是约束违反个数
    f[1] = 0;//初始化约束违反个数
    for (chri_i=0;chri_i<task_num;chri_i++)//遍历所有任务
    {
        for (chri_j=0;chri_j<task_num;chri_j++)//遍历染色体的t数组
        {
            if (chri.t[chri_j] == (chri_i + 1))//若找到任务i的位置，则记录其下标
            {
                t_index[chri_i] = chri_j;
            }
        }
    }
    for (chri_i=0;chri_i<task_num;chri_i++)
    {
        for (chri_j=0;chri_j<task_num;chri_j++)//遍历完全约束矩阵
        {
            //若任务i>任务j，且任务i的下标在任务j之后，则说明违反了一条约束关系
            if (restraint_comp[chri_i * task_num + chri_j] == 1 && t_index[chri_i] > t_index[chri_j])
            {
                f[1]++;
            }
        }
    }

    obj[0] = f[0];
    obj[1] = f[1];
    return;
}

void test_problem (double *xreal, double *xbin, int **gene, double *obj, double *constr)
{
    if (strcmp(prob_name, "ptts"))
        test_problem_ptts(xreal, xbin, gene, obj, constr);
    return;
}
