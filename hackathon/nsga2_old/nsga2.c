/* This is a Multi-Objective GA program.
**********************************************************************
*  This program is the implementation of the NSGA-2 proposed by      *
*                                                                    *
*  Prof. Kalyanmoy Deb and his students .                            *
*                                                                    *
*  copyright Kalyanmoy Deb
**********************************************************************

18.08.2003: The keepaliven.h file is modified to have normalized
crowding distance calculation. The previous version of 
the code did not have this feature. This way, maintaining
a good distribution of solutions in problems having quite
a different range of objective functions were difficult.
Hopefully, with this modification, such difficulties will
not appear. --  K. Deb
18.08.2003: Also the dfit.h file is deleted. It was not needed any way.

The user have to give the input manualy or through a data file.

The user needs to enter objective functions in func-con.h
The code can also take care of the constraints. Enter the constraints
in the space provided in the func-con.h file.
Constraints must be of the following type:
g(x) >= 0.0
Also normalize all constraints (see the example problem in func-con.h)

If your program asks you to increase the values of some parameters in the
program come to main program and accordingly changed the values which are
defined against #define ...

The program generates few output files. These are described as
1.output.out
*           This file has the detailed record for all the variables,
*           the fitness values, constraint values, overall constraint
violation (penalty)  and their ranks for all the members
*           of old population in the left hand side of the |**|
*           and of new population in the right hand side.

2.all_fitness.out
*         This file prints the record of all the fitness values for
*         different individual of new popultion created at all
*         generations.

3.g_rank_record.out
*        This file maintains the record of individuals in global pop-
*        -ulation at different ranks for all the generations.

4.ranks.out
*         This file prints the number of individual at different ranks
*          in old and new population and finds rank ratios

5.final_fitness.out
*                 This file has the fitness value of all feasible and
non-dominated individuals at the final generation

6.final_var.out
*                 This file has the all the variables of the feasible
and non-dominated individuals at the final generation.
The i-th solutions here corresponds to the i-th solution
in the final_fitness.out file. 

7.plot.out        This file contains gnuplot-based file for plotting
the non-dominated feasible solutions obtained by the code.
*************************************************************************
*         This is recommended to delete or rename all the *.out files
*         obtained from the previous runs as some files are opened in
*         append mode so they give false resemblence of data if the
*         user is not careful

Compilation procedure:  gcc nsga2.c -lm
Run ./a.out with or without an input file

Input data files: Three files are included, but at one time one is needed
depending on the type of variables used:
inp-r (template file input-real)  : All variables are real-coded
inp-b (template file input-binary): All variables are binary-coded
inp-rb(template file input-rl+bin): Some variables are real and some are binary  
*/

/**********************************头文件****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

/**********************************宏定义********************************************************/

#define square(x) ((x)*(x))
#define maxpop   300  /*Max population */
//最大种群数
//#define maxchrom 200  /*Max chromosome length*/
#define maxchrom 50  /*Max chromosome length*/
//最大染色体长度（二进制编码参数）
//（决策变量个数*表示一个决策变量需要的二进制位数）
//#define maxvar    20  /*Max no. of variables*/
#define maxvar    40  /*Max no. of variables*/
//最大决策变量数
#define maxfun    3  /*Max no. of functions */
//目标函数个数
#define maxcons   1  /*Max no. of Constraints*/
//约束条件个数
#define pi 3.1415926
#define task_num 40 //PTTS时是20或6，PTTS2时是30，PTTS40是40
#define maxgen 300 //最大迭代次数
#define maxrun 10 //算法运行次数，基本都是10次，只有PTTS2是20次

/***************************************全局变量声明、定义***********************************************/

char prob[]="PTTS40";//问题 ZDT1,ZDT2,ZDT3,ZDT4,ZDT6,PTTS,PTTS2(双UUT),PTTS40
char cross_proba_mod[] = "random";//交叉概率
char mutation_proba_mod[] = "random";//变异概率

//random,logistic,cat,ICMIC,circle,bakers,tinker,zasla
char init_mod[] = "random";//初始种群
char cross_mod[] = "random";//交叉算子
char mutation_mod[] = "random";//变异算子

clock_t start, finish;//记录算法运行开始和结束时间
double duration;//记录算法运行时间

int gener,       /*No of generations*/
    //总迭代次数
    nvar,//实际决策变量个数
    nchrom,          /*No of variables*///实际染色体个数（二进制编码）
    ncons,         /*No of Constraints*///实际约束个数
    vlen[maxvar],  /*Array to store no of bits for each variable*/
    //二进制编码每个决策变量需要的二进制位数
    nmut,          /* No of Mutations *///变异个数
    ncross,        /*No of crossovers*///交叉个数
    ans,//是否是严格约束（1是）
    run;//算法独立运行计数器

float seed,      /*Random Seed*///随机数种子值
    pcross,        /*Cross-over Probability*///交叉概率
    pmut_b,//二进制编码变异概率
    pmut_r,          /*Mutation Probability*///实数编码变异概率
    lim_b[maxvar][2],//二进制编码决策变量取值范围
    lim_r[maxvar][2];/*Limits of variable in array*///实数编码决策变量取值范围

float di,        /*Distribution Index for the Cross-over*///交叉分布指数
    dim,           /*Distribution Index for the Mutation*///变异分布指数
    delta_fit,     /* variables required forfitness for fitness sharing */
    //适应度共享变量
    min_fit,//?
    front_ratio;//?

int optype,      /*Cross-over type*///交叉方式（二进制，1简单交叉，2均匀交叉）
    nfunc,         /*No of functions*///实际的目标函数个数
    sharespace;    /*Sharing space (either parameter or fitness)*/

double coef[maxvar]; /*Variable used for decoding*///用来解码的变量?

static int popsize,  /*Population Size*///种群大小
    chrom;             /*Chromosome size*///染色体大小

typedef struct       /*individual properties*/
{
    int genes[maxchrom], /*bianry chromosome*///二进制染色体
        rank,              /*Rank of the individual*///级别
        flag;              /*Flag for ranking*///是否分配级别标记

    float xreal[maxvar], /*list of real variables*///实数编码决策变量表
        xbin[maxvar];      /*list of decoded value of the chromosome */
    //解码后的二进制染色体值

    float fitness[maxfun],/*Fitness values *///目标函数值
        constr[maxcons],     /*Constraints values*///约束值
        cub_len,             /*crowding distance of the individual*///个体间距
        error;              /* overall constraint violation for the individual*/
    //个体违反约束总值
}individual;        /*Structure defining individual*/


typedef struct
{
    int maxrank;            /*Maximum rank present in the population*/
    //种群中最大级别

    float rankrat[maxpop];  /*Rank Ratio*///级别比例？

    int rankno[maxpop];     /*Individual at different ranks*///各级别个体？
    individual ind[maxpop], /*Different Individuals*/
        *ind_ptr; //individual型个体，指针

}population ;             /*Popuation Structure*/

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

method meth[task_num+1],
    *meth_ptr;

chr chri,
    *chri_ptr;

int restraint[task_num][task_num];
int restraint_comp[task_num][task_num];
int restraint_comp2[task_num][task_num];

float logistic_a = 3.99,//混沌参数
    key_li,//混沌初值,logistic初始种群
    key_lc,//logistic交叉算子
    key_lm;//logistic变异算子

float catx_ci,//cat初始种群
    caty_ci,
    temp_ci,
    catx_cc,//cat交叉算子
    caty_cc,
    temp_cc,
    catx_cm,//cat变异算子
    caty_cm,
    temp_cm;

float ICMIC_a = 2,//混沌参数
    ICMICi,//ICMIC初始种群
    ICMICc,//ICMIC交叉算子
    ICMICm;//ICMIC变异算子

float circle_a = 0.5,
    circle_b = 0.2,//混沌参数
    circlei,//circle初始种群
    circlec,//circle交叉算子
    circlem;//circle变异算子

float bakers_xi,//bakers初始种群
    bakers_yi,  
    bakers_xc,//bakers交叉算子
    bakers_yc,
    bakers_xm,//bakers变异算子
    bakers_ym;

float zasla_zi,//zasla初始种群
    zasla_yi,   
    zasla_zc,//zasla交叉算子
    zasla_yc,
    zasla_zm,//zasla变异算子
    zasla_ym;
/***********************************算法包含头文件*******************************************************/

#include "random.h"       /*Random Number Generator*/
//随机数产生器

#include "input.h"        /*File Takes Input from user*/
//参数设置

#include "realinit.h"     /*Random Initialization of the populaiton*/
//实数编码随机初始种群

#include "init.h"         /*Random Initialization of the population*/
//二进制编码随机初始种群

#include "decode.h"       /*File decoding the binary dtrings*/
//二进制解码

#include "ranking.h"      /*File Creating the Pareto Fronts*/
//排序产生pareto前沿

#include "rancon.h"       /*File Creating the Pareto Fronts when
Constraints are specified*/
//含约束时排序产生前沿

#include "func-con.h"     /*File Having the Function*/
//算目标函数值

#include "select.h"       /*File for Tournament Selection*/
//联赛选择

#include "crossover.h"    /*Binary Cross-over*/
//二进制交叉

#include "uniformxr.h"    /*Uniform Cross-over*/
//二进制交叉

#include "realcross2.h"   /*Real Cross-over*/
//实数编码交叉

#include "mut.h"          /*Binary Mutation*/
//二进制变异

#include "realmut1.h"     /*Real Mutation*/
//实数编码变异

#include "keepaliven.h"   /*File For Elitism and Sharing Scheme*/
//精英保留和共享策略

#include "report.h"       /*Printing the report*/
//生成报告

population oldpop,//旧种群（父代）
    newpop,//新种群（子代）
    matepop,//混合种群
    *old_pop_ptr,//父代指针
    *new_pop_ptr,//子代指针
    *mate_pop_ptr;//混合种群指针
/*Defining the population Structures*/

/*************************************主程序*****************************************************/

main()
{
    /**********************变量声明*********************************************************************/
    /*Some Local variables to this Problem (Counters And some other pointers*/
    //局部变量的定义（计数器和其他指针）
    int i,j,l,f,maxrank1;
    float *ptr,tot;

    FILE 
        *rep_ptr,//指向output文件，
        ////输出算法参数设置，各代种群和适应度函数值

        //*gen_ptr,//指向gen_fitness文件，
        ////输出所有代的决策变量、适应度函数值，约束违反和全部惩罚？

        //*rep2_ptr,//指向ranks文件，
        ////输出各代级别，新旧级别和级别比？

        //*end_ptr,//指向final_fitness文件，
        ////输出最后一代的适应度函数值

        //*g_var,//指向final_var文件，
        ////输出最后一代的决策变量

        *lastit,//指向plot文件，
        //输出最后一代的适应度函数值（与final_fitness差不多）
        *run_time;
    /*File Pointers*/  

    srand((unsigned)time(NULL));//利用系统时间产生随机种子

    //打开数据记录文件
    rep_ptr = fopen("output.txt","w");
    //gen_ptr =fopen("gen_fitness_c.txt","w");
    //rep2_ptr = fopen("ranks.txt","w");
    //end_ptr = fopen("final_fitness.txt","w");
    //g_var = fopen("final_var.txt","w");
    lastit = fopen("plot.txt","w");
    run_time = fopen("run_time.txt","w");
    /*Opening the files*/
    //用指针打开所有文件

    /****************************算法独立运行**************************************************************/
    for (run=0;run<maxrun;run++)
    {
        /****************************初始参数设置*******************************/
        start = clock();//记录算法开始时间
        old_pop_ptr = &(oldpop);//初始化old_pop_ptr指针为oldpop的地址

        nmut = 0;
        ncross = 0;//变异数和交叉数初始化为0

        /*Get the input from the file input.h*/
        input(rep_ptr);//从input函数（包含在input.h头文件中）中读取对算法的参数设置

        /*Initialize the random no generator*/
        warmup_random(seed);//生成随机序列？只有55个元素？这个序列是干什么用的？

        //fprintf(rep_ptr,"Results in a file\n");
        //fprintf(end_ptr,"# Last generation population (Feasible and non-dominated)\n");
        //fprintf(end_ptr,"# Fitness_vector (first %d)  Constraint_violation (next %d)  Overall_penalty\n",nfunc,ncons);
        //fprintf(g_var,"#Feasible Variable_vectors for non-dominated solutions at last generation\n");
        //fprintf(g_var,"# Real (first %d)  Binary (next %d)\n",nvar,nchrom);
        //fprintf(lastit,"# Feasible and Non-dominated Objective Vector\n");

        /******************混沌序列预生成**********************/

        //logistic混沌初值
        if (!strcmp(init_mod,"logistic"))
            key_li = randomperc();  
        if (!strcmp(cross_mod,"logistic"))
            key_lc = randomperc();
        if (!strcmp(mutation_mod,"logistic"))
            key_lm = randomperc();

        //cat混沌初值
        if (!strcmp(init_mod,"cat"))
        {
            catx_ci = randomperc();
            caty_ci = randomperc();
        }
        if (!strcmp(cross_mod,"cat"))
        {
            catx_cc = randomperc();
            caty_cc = randomperc();
        }
        if (!strcmp(mutation_mod,"cat"))
        {
            catx_cm = randomperc();
            caty_cm = randomperc();
        }
        //ICMIC混沌初值
        if (!strcmp(init_mod,"ICMIC"))
            ICMICi = randomperc();          

        if (!strcmp(cross_mod,"ICMIC"))
            ICMICc = randomperc();

        if (!strcmp(mutation_mod,"ICMIC"))
            ICMICm = randomperc();
        //circle混沌初值
        if (!strcmp(init_mod,"circle"))
            circlei = randomperc();         

        if (!strcmp(cross_mod,"circle"))
            circlec = randomperc();

        if (!strcmp(mutation_mod,"circle"))
            circlem = randomperc();
        //bakers混沌初值
        if (!strcmp(init_mod,"bakers"))
        {
            bakers_xi = randomperc();
            bakers_yi = randomperc();
        }
        if (!strcmp(cross_mod,"bakers"))
        {
            bakers_xc = randomperc();
            bakers_yc = randomperc();
        }
        if (!strcmp(mutation_mod,"bakers"))
        {
            bakers_xm = randomperc();
            bakers_ym = randomperc();
        }

        //zasla混沌初值
        if (!strcmp(init_mod,"zasla"))
        {
            zasla_zi = randomperc();
            zasla_yi = randomperc();
        }
        if (!strcmp(cross_mod,"zasla"))
        {
            zasla_zc = randomperc();
            zasla_yc = randomperc();
        }
        if (!strcmp(mutation_mod,"zasla"))
        {
            zasla_zm = randomperc();
            zasla_ym = randomperc();
        }
        /**********************************遗传操作*****************************************************/     
        
        /*Binary Initializaton*/
        /*-------------初始化种群---------------------*/
        if (nchrom > 0)
            init(old_pop_ptr);  //二进制初始化
        if (nvar > 0)
            realinit(old_pop_ptr);//实数编码初始化

        old_pop_ptr = &(oldpop);//初始化old_pop_ptr指针为oldpop的地址

        // decode binary strings
        decode(old_pop_ptr); //解码二进制

        old_pop_ptr = &(oldpop);//初始化old_pop_ptr指针为oldpop的地址
        new_pop_ptr = &(newpop);//初始化new_pop_ptr指针为newpop的地址

        for(j = 0;j < popsize;j++)
        {
            /*Initializing the Rank array having different individuals
            at a particular  rank to zero*/
            old_pop_ptr->rankno[j] = 0;
            new_pop_ptr->rankno[j] = 0;//初始化种群的级别为0
        }

        old_pop_ptr = &(oldpop);//初始化old_pop_ptr指针为oldpop的地址

        func(old_pop_ptr); //计算旧种群的适应度函数值
        /*Function Calculaiton*/

        //fprintf(rep_ptr,"----------------------------------------------------\n");
        //fprintf(rep_ptr,"Statistics at Generation 0 ->\n");
        //fprintf(rep_ptr,"--------------------------------------------------\n");

        /********************************************************************/
        /*----------------------GENERATION STARTS HERE----------------------*/
        /*----------------------开始迭代----------------------*/

        for (i = 0;i < gener;i++)
        {
            if (i == gener-1)
                printf("Generation = %d\n",i+1);
            old_pop_ptr = &(oldpop);
            mate_pop_ptr = &(matepop);
            /*fprintf(rep_ptr,"Population at generation no. -->%d\n",i+1);*/
            //fprintf(gen_ptr,"#Generation No. -->%d\n",i+1);
            //fprintf(gen_ptr,"#Variable_vector  Fitness_vector Constraint_violation Overall_penalty\n");

            /*--------SELECT----------------*/
            /*--------选择----------------*/

            nselect(old_pop_ptr ,mate_pop_ptr );

            new_pop_ptr = &(newpop);
            mate_pop_ptr = &(matepop);

            /*CROSSOVER----------------------------*/   
            /*-------------------交叉--------------------*/

            if (nchrom > 0) 
            {

                if(optype == 1)
                {
                    crossover(new_pop_ptr ,mate_pop_ptr );
                    /*Binary Cross-over*/
                }

                if(optype == 2)
                {
                    unicross(new_pop_ptr ,mate_pop_ptr );
                    /*Binary Uniform Cross-over*/
                }
            }
            if (nvar > 0) 
                realcross(new_pop_ptr ,mate_pop_ptr );
            /*Real Cross-over*/


            /*------MUTATION-------------------*/
            /*-----------------变异-----------------*/

            new_pop_ptr = &(newpop);

            if (nchrom > 0)
                mutate(new_pop_ptr );
            /*Binary Mutation */

            if (nvar > 0)
                real_mutate(new_pop_ptr );
            /*Real Mutation*/

            new_pop_ptr = &(newpop);

            /*-------DECODING----------*/
            /*--------解码-----------*/
            if(nchrom > 0)
                decode(new_pop_ptr );
            /*Decoding for binary strings*/

            /*----------FUNCTION EVALUATION-----------*/
            /*---------适应度函数计算----------*/     
            new_pop_ptr = &(newpop);
            func(new_pop_ptr);

            /*-------------------SELECTION KEEPING FRONTS ALIVE--------------*/
            old_pop_ptr = &(oldpop);
            new_pop_ptr = &(newpop);
            mate_pop_ptr = &(matepop);

            /*Elitism And Sharing Implemented*/
            keepalive(old_pop_ptr ,new_pop_ptr ,mate_pop_ptr,i+1);      

            mate_pop_ptr = &(matepop);
            if(nchrom > 0)
                decode(mate_pop_ptr );

            mate_pop_ptr = &(matepop);
            /*------------------REPORT PRINTING--------------------------------*/  
            /*------------------生成报告--------------------------------*/ 
            //report(i ,old_pop_ptr ,mate_pop_ptr ,rep_ptr ,gen_ptr, lastit ,run);
            report(i ,old_pop_ptr ,mate_pop_ptr, lastit ,run);

            /*==================================================================*/

            /*----------------Rank Ratio Calculation------------------------*/
            /*----------------计算级别比例------------------------*/
            new_pop_ptr = &(matepop);
            old_pop_ptr = &(oldpop);

            /*Finding the greater maxrank among the two populations*/

            if(old_pop_ptr->maxrank > new_pop_ptr->maxrank)
                maxrank1 = old_pop_ptr->maxrank;
            else 
                maxrank1 = new_pop_ptr->maxrank;

            //fprintf(rep2_ptr,"--------RANK AT GENERATION %d--------------\n",i+1);
            //fprintf(rep2_ptr,"Rank old ranks   new ranks     rankratio\n");

            for(j = 0;j < maxrank1 ; j++)
            { 
                /*Sum of the no of individuals at any rank in old population 
                and the new populaion*/

                tot = (old_pop_ptr->rankno[j])+ (new_pop_ptr->rankno[j]);

                /*Finding the rank ratio for new population at this rank*/

                new_pop_ptr->rankrat[j] = (new_pop_ptr->rankno[j])/tot;

                /*Printing this rank ratio to a file called ranks.dat*/

                //fprintf(rep2_ptr," %d\t  %d\t\t %d\t %f\n",j+1,old_pop_ptr->rankno[j],new_pop_ptr->rankno[j],new_pop_ptr->rankrat[j]);

            }

            //fprintf(rep2_ptr,"-----------------Rank Ratio-------------------\n");
            /*==================================================================*/

            /*=======Copying the new population to old population======*/

            old_pop_ptr = &(oldpop);
            new_pop_ptr = &(matepop);

            for(j = 0;j < popsize;j++)
            {
                old_pop_ptr->ind_ptr = &(old_pop_ptr->ind[j]);
                new_pop_ptr->ind_ptr = &(new_pop_ptr->ind[j]);
                if(nchrom > 0)
                {
                    /*For Binary GA copying of the chromosome*/

                    for(l = 0;l < chrom;l++)
                        old_pop_ptr->ind_ptr->genes[l]=new_pop_ptr->ind_ptr->genes[l];

                    for(l = 0;l < nchrom;l++)
                        old_pop_ptr->ind_ptr->xbin[l] = new_pop_ptr->ind_ptr->xbin[l];
                }
                if(nvar > 0)
                {
                    /*For Real Coded GA copying of the chromosomes*/
                    for(l = 0;l < nvar;l++)
                        old_pop_ptr->ind_ptr->xreal[l] = new_pop_ptr->ind_ptr->xreal[l];
                }

                /*Copying the fitness vector */   
                for(l = 0 ; l < nfunc ;l++)
                    old_pop_ptr->ind_ptr->fitness[l] = new_pop_ptr->ind_ptr->fitness[l];

                /*Copying the dummy fitness*/
                old_pop_ptr->ind_ptr->cub_len = new_pop_ptr->ind_ptr->cub_len;

                /*Copying the rank of the individuals*/
                old_pop_ptr->ind_ptr->rank = new_pop_ptr->ind_ptr->rank;

                /*Copying the error and constraints of the individual*/

                old_pop_ptr->ind_ptr->error = new_pop_ptr->ind_ptr->error;
                for(l = 0;l < ncons;l++)
                {
                    old_pop_ptr->ind_ptr->constr[l] = new_pop_ptr->ind_ptr->constr[l];
                }

                /*Copying the flag of the individuals*/
                old_pop_ptr->ind_ptr->flag = new_pop_ptr->ind_ptr->flag;
            }   // end of j

            maxrank1 = new_pop_ptr->maxrank ;

            /*Copying the array having the record of the individual 
            at different ranks */
            for(l = 0;l < popsize;l++)
            {
                old_pop_ptr->rankno[l] = new_pop_ptr->rankno[l];
            }

            /*Copying the maxrank */
            old_pop_ptr->maxrank = new_pop_ptr->maxrank;

            /*Printing the fitness record for last generation in a file last*/
            if(i == gener-1)
            {  // for the last generation 
                old_pop_ptr = &(matepop);
                for(f = 0;f < popsize ; f++) // for printing
                {
                    old_pop_ptr->ind_ptr = &(old_pop_ptr->ind[f]);

                    if ((old_pop_ptr->ind_ptr->error <= 0.0) && (old_pop_ptr->ind_ptr->rank == 1))  // for all feasible solutions and non-dominated solutions
                    {
                        //for(l = 0;l < nfunc;l++)
                        //  fprintf(end_ptr,"%f\t",old_pop_ptr->ind_ptr->fitness[l]);
                        //for(l = 0;l < ncons;l++)
                        //{
                        //  fprintf(end_ptr,"%f\t",old_pop_ptr->ind_ptr->constr[l]);
                        //}
                        //if (ncons > 0)
                        //  fprintf(end_ptr,"%f\t",old_pop_ptr->ind_ptr->error);
                        //fprintf(end_ptr,"\n");

                        //if (nvar > 0)
                        //{
                        //  for(l = 0;l < nvar ;l++)
                        //  {
                        //      fprintf(g_var,"%f\t",old_pop_ptr->ind_ptr->xreal[l]);
                        //  }
                        //  fprintf(g_var,"  ");
                        //}

                        //if(nchrom > 0)
                        //{
                        //  for(l = 0;l < nchrom;l++)
                        //  {
                        //      fprintf(g_var,"%f\t",old_pop_ptr->ind_ptr->xbin[l]);
                        //  }
                        //}
                        //fprintf(g_var,"\n");
                    }  // feasibility check
                } // end of f (printing)

            } // for the last generation
        }  // end of i 
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        //fprintf(end_ptr,"The runtime is %f\n",duration);
        fprintf(run_time,"%f\n",duration);
    }

    /*                   Generation Loop Ends                                */
    /************************************************************************/

    //fprintf(rep_ptr,"NO. OF CROSSOVER = %d\n",ncross);
    //fprintf(rep_ptr,"NO. OF MUTATION = %d\n",nmut);
    //fprintf(rep_ptr,"------------------------------------------------------------\n");
    //fprintf(rep_ptr,"---------------------------------Thanks---------------------\n");
    //fprintf(rep_ptr,"-------------------------------------------------------------\n");
    printf("NOW YOU CAN LOOK IN THE FILE OUTPUT2.DAT\n");

    /*Closing the files*/
    //关闭数据记录文件
    fclose(rep_ptr);
    //fclose(gen_ptr);
    //fclose(rep2_ptr);
    //fclose(end_ptr);
    //fclose(g_var);
    fclose(lastit);
    fclose(run_time);
}
