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

/**********************************ͷ�ļ�****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

/**********************************�궨��********************************************************/

#define square(x) ((x)*(x))
#define maxpop   300  /*Max population */
//�����Ⱥ��
//#define maxchrom 200  /*Max chromosome length*/
#define maxchrom 50  /*Max chromosome length*/
//���Ⱦɫ�峤�ȣ������Ʊ��������
//�����߱�������*��ʾһ�����߱�����Ҫ�Ķ�����λ����
//#define maxvar    20  /*Max no. of variables*/
#define maxvar    40  /*Max no. of variables*/
//�����߱�����
#define maxfun    3  /*Max no. of functions */
//Ŀ�꺯������
#define maxcons   1  /*Max no. of Constraints*/
//Լ����������
#define pi 3.1415926
#define task_num 40 //PTTSʱ��20��6��PTTS2ʱ��30��PTTS40��40
#define maxgen 300 //����������
#define maxrun 10 //�㷨���д�������������10�Σ�ֻ��PTTS2��20��

/***************************************ȫ�ֱ�������������***********************************************/

char prob[]="PTTS40";//���� ZDT1,ZDT2,ZDT3,ZDT4,ZDT6,PTTS,PTTS2(˫UUT),PTTS40
char cross_proba_mod[] = "random";//�������
char mutation_proba_mod[] = "random";//�������

//random,logistic,cat,ICMIC,circle,bakers,tinker,zasla
char init_mod[] = "random";//��ʼ��Ⱥ
char cross_mod[] = "random";//��������
char mutation_mod[] = "random";//��������

clock_t start, finish;//��¼�㷨���п�ʼ�ͽ���ʱ��
double duration;//��¼�㷨����ʱ��

int gener,       /*No of generations*/
    //�ܵ�������
    nvar,//ʵ�ʾ��߱�������
    nchrom,          /*No of variables*///ʵ��Ⱦɫ������������Ʊ��룩
    ncons,         /*No of Constraints*///ʵ��Լ������
    vlen[maxvar],  /*Array to store no of bits for each variable*/
    //�����Ʊ���ÿ�����߱�����Ҫ�Ķ�����λ��
    nmut,          /* No of Mutations *///�������
    ncross,        /*No of crossovers*///�������
    ans,//�Ƿ����ϸ�Լ����1�ǣ�
    run;//�㷨�������м�����

float seed,      /*Random Seed*///���������ֵ
    pcross,        /*Cross-over Probability*///�������
    pmut_b,//�����Ʊ���������
    pmut_r,          /*Mutation Probability*///ʵ������������
    lim_b[maxvar][2],//�����Ʊ�����߱���ȡֵ��Χ
    lim_r[maxvar][2];/*Limits of variable in array*///ʵ��������߱���ȡֵ��Χ

float di,        /*Distribution Index for the Cross-over*///����ֲ�ָ��
    dim,           /*Distribution Index for the Mutation*///����ֲ�ָ��
    delta_fit,     /* variables required forfitness for fitness sharing */
    //��Ӧ�ȹ������
    min_fit,//?
    front_ratio;//?

int optype,      /*Cross-over type*///���淽ʽ�������ƣ�1�򵥽��棬2���Ƚ��棩
    nfunc,         /*No of functions*///ʵ�ʵ�Ŀ�꺯������
    sharespace;    /*Sharing space (either parameter or fitness)*/

double coef[maxvar]; /*Variable used for decoding*///��������ı���?

static int popsize,  /*Population Size*///��Ⱥ��С
    chrom;             /*Chromosome size*///Ⱦɫ���С

typedef struct       /*individual properties*/
{
    int genes[maxchrom], /*bianry chromosome*///������Ⱦɫ��
        rank,              /*Rank of the individual*///����
        flag;              /*Flag for ranking*///�Ƿ���伶����

    float xreal[maxvar], /*list of real variables*///ʵ��������߱�����
        xbin[maxvar];      /*list of decoded value of the chromosome */
    //�����Ķ�����Ⱦɫ��ֵ

    float fitness[maxfun],/*Fitness values *///Ŀ�꺯��ֵ
        constr[maxcons],     /*Constraints values*///Լ��ֵ
        cub_len,             /*crowding distance of the individual*///������
        error;              /* overall constraint violation for the individual*/
    //����Υ��Լ����ֵ
}individual;        /*Structure defining individual*/


typedef struct
{
    int maxrank;            /*Maximum rank present in the population*/
    //��Ⱥ����󼶱�

    float rankrat[maxpop];  /*Rank Ratio*///���������

    int rankno[maxpop];     /*Individual at different ranks*///��������壿
    individual ind[maxpop], /*Different Individuals*/
        *ind_ptr; //individual�͸��壬ָ��

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

float logistic_a = 3.99,//�������
    key_li,//�����ֵ,logistic��ʼ��Ⱥ
    key_lc,//logistic��������
    key_lm;//logistic��������

float catx_ci,//cat��ʼ��Ⱥ
    caty_ci,
    temp_ci,
    catx_cc,//cat��������
    caty_cc,
    temp_cc,
    catx_cm,//cat��������
    caty_cm,
    temp_cm;

float ICMIC_a = 2,//�������
    ICMICi,//ICMIC��ʼ��Ⱥ
    ICMICc,//ICMIC��������
    ICMICm;//ICMIC��������

float circle_a = 0.5,
    circle_b = 0.2,//�������
    circlei,//circle��ʼ��Ⱥ
    circlec,//circle��������
    circlem;//circle��������

float bakers_xi,//bakers��ʼ��Ⱥ
    bakers_yi,  
    bakers_xc,//bakers��������
    bakers_yc,
    bakers_xm,//bakers��������
    bakers_ym;

float zasla_zi,//zasla��ʼ��Ⱥ
    zasla_yi,   
    zasla_zc,//zasla��������
    zasla_yc,
    zasla_zm,//zasla��������
    zasla_ym;
/***********************************�㷨����ͷ�ļ�*******************************************************/

#include "random.h"       /*Random Number Generator*/
//�����������

#include "input.h"        /*File Takes Input from user*/
//��������

#include "realinit.h"     /*Random Initialization of the populaiton*/
//ʵ�����������ʼ��Ⱥ

#include "init.h"         /*Random Initialization of the population*/
//�����Ʊ��������ʼ��Ⱥ

#include "decode.h"       /*File decoding the binary dtrings*/
//�����ƽ���

#include "ranking.h"      /*File Creating the Pareto Fronts*/
//�������paretoǰ��

#include "rancon.h"       /*File Creating the Pareto Fronts when
Constraints are specified*/
//��Լ��ʱ�������ǰ��

#include "func-con.h"     /*File Having the Function*/
//��Ŀ�꺯��ֵ

#include "select.h"       /*File for Tournament Selection*/
//����ѡ��

#include "crossover.h"    /*Binary Cross-over*/
//�����ƽ���

#include "uniformxr.h"    /*Uniform Cross-over*/
//�����ƽ���

#include "realcross2.h"   /*Real Cross-over*/
//ʵ�����뽻��

#include "mut.h"          /*Binary Mutation*/
//�����Ʊ���

#include "realmut1.h"     /*Real Mutation*/
//ʵ���������

#include "keepaliven.h"   /*File For Elitism and Sharing Scheme*/
//��Ӣ�����͹������

#include "report.h"       /*Printing the report*/
//���ɱ���

population oldpop,//����Ⱥ��������
    newpop,//����Ⱥ���Ӵ���
    matepop,//�����Ⱥ
    *old_pop_ptr,//����ָ��
    *new_pop_ptr,//�Ӵ�ָ��
    *mate_pop_ptr;//�����Ⱥָ��
/*Defining the population Structures*/

/*************************************������*****************************************************/

main()
{
    /**********************��������*********************************************************************/
    /*Some Local variables to this Problem (Counters And some other pointers*/
    //�ֲ������Ķ��壨������������ָ�룩
    int i,j,l,f,maxrank1;
    float *ptr,tot;

    FILE 
        *rep_ptr,//ָ��output�ļ���
        ////����㷨�������ã�������Ⱥ����Ӧ�Ⱥ���ֵ

        //*gen_ptr,//ָ��gen_fitness�ļ���
        ////������д��ľ��߱�������Ӧ�Ⱥ���ֵ��Լ��Υ����ȫ���ͷ���

        //*rep2_ptr,//ָ��ranks�ļ���
        ////������������¾ɼ���ͼ���ȣ�

        //*end_ptr,//ָ��final_fitness�ļ���
        ////������һ������Ӧ�Ⱥ���ֵ

        //*g_var,//ָ��final_var�ļ���
        ////������һ���ľ��߱���

        *lastit,//ָ��plot�ļ���
        //������һ������Ӧ�Ⱥ���ֵ����final_fitness��ࣩ
        *run_time;
    /*File Pointers*/  

    srand((unsigned)time(NULL));//����ϵͳʱ������������

    //�����ݼ�¼�ļ�
    rep_ptr = fopen("output.txt","w");
    //gen_ptr =fopen("gen_fitness_c.txt","w");
    //rep2_ptr = fopen("ranks.txt","w");
    //end_ptr = fopen("final_fitness.txt","w");
    //g_var = fopen("final_var.txt","w");
    lastit = fopen("plot.txt","w");
    run_time = fopen("run_time.txt","w");
    /*Opening the files*/
    //��ָ��������ļ�

    /****************************�㷨��������**************************************************************/
    for (run=0;run<maxrun;run++)
    {
        /****************************��ʼ��������*******************************/
        start = clock();//��¼�㷨��ʼʱ��
        old_pop_ptr = &(oldpop);//��ʼ��old_pop_ptrָ��Ϊoldpop�ĵ�ַ

        nmut = 0;
        ncross = 0;//�������ͽ�������ʼ��Ϊ0

        /*Get the input from the file input.h*/
        input(rep_ptr);//��input������������input.hͷ�ļ��У��ж�ȡ���㷨�Ĳ�������

        /*Initialize the random no generator*/
        warmup_random(seed);//����������У�ֻ��55��Ԫ�أ���������Ǹ�ʲô�õģ�

        //fprintf(rep_ptr,"Results in a file\n");
        //fprintf(end_ptr,"# Last generation population (Feasible and non-dominated)\n");
        //fprintf(end_ptr,"# Fitness_vector (first %d)  Constraint_violation (next %d)  Overall_penalty\n",nfunc,ncons);
        //fprintf(g_var,"#Feasible Variable_vectors for non-dominated solutions at last generation\n");
        //fprintf(g_var,"# Real (first %d)  Binary (next %d)\n",nvar,nchrom);
        //fprintf(lastit,"# Feasible and Non-dominated Objective Vector\n");

        /******************��������Ԥ����**********************/

        //logistic�����ֵ
        if (!strcmp(init_mod,"logistic"))
            key_li = randomperc();  
        if (!strcmp(cross_mod,"logistic"))
            key_lc = randomperc();
        if (!strcmp(mutation_mod,"logistic"))
            key_lm = randomperc();

        //cat�����ֵ
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
        //ICMIC�����ֵ
        if (!strcmp(init_mod,"ICMIC"))
            ICMICi = randomperc();          

        if (!strcmp(cross_mod,"ICMIC"))
            ICMICc = randomperc();

        if (!strcmp(mutation_mod,"ICMIC"))
            ICMICm = randomperc();
        //circle�����ֵ
        if (!strcmp(init_mod,"circle"))
            circlei = randomperc();         

        if (!strcmp(cross_mod,"circle"))
            circlec = randomperc();

        if (!strcmp(mutation_mod,"circle"))
            circlem = randomperc();
        //bakers�����ֵ
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

        //zasla�����ֵ
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
        /**********************************�Ŵ�����*****************************************************/     
        
        /*Binary Initializaton*/
        /*-------------��ʼ����Ⱥ---------------------*/
        if (nchrom > 0)
            init(old_pop_ptr);  //�����Ƴ�ʼ��
        if (nvar > 0)
            realinit(old_pop_ptr);//ʵ�������ʼ��

        old_pop_ptr = &(oldpop);//��ʼ��old_pop_ptrָ��Ϊoldpop�ĵ�ַ

        // decode binary strings
        decode(old_pop_ptr); //���������

        old_pop_ptr = &(oldpop);//��ʼ��old_pop_ptrָ��Ϊoldpop�ĵ�ַ
        new_pop_ptr = &(newpop);//��ʼ��new_pop_ptrָ��Ϊnewpop�ĵ�ַ

        for(j = 0;j < popsize;j++)
        {
            /*Initializing the Rank array having different individuals
            at a particular  rank to zero*/
            old_pop_ptr->rankno[j] = 0;
            new_pop_ptr->rankno[j] = 0;//��ʼ����Ⱥ�ļ���Ϊ0
        }

        old_pop_ptr = &(oldpop);//��ʼ��old_pop_ptrָ��Ϊoldpop�ĵ�ַ

        func(old_pop_ptr); //�������Ⱥ����Ӧ�Ⱥ���ֵ
        /*Function Calculaiton*/

        //fprintf(rep_ptr,"----------------------------------------------------\n");
        //fprintf(rep_ptr,"Statistics at Generation 0 ->\n");
        //fprintf(rep_ptr,"--------------------------------------------------\n");

        /********************************************************************/
        /*----------------------GENERATION STARTS HERE----------------------*/
        /*----------------------��ʼ����----------------------*/

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
            /*--------ѡ��----------------*/

            nselect(old_pop_ptr ,mate_pop_ptr );

            new_pop_ptr = &(newpop);
            mate_pop_ptr = &(matepop);

            /*CROSSOVER----------------------------*/   
            /*-------------------����--------------------*/

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
            /*-----------------����-----------------*/

            new_pop_ptr = &(newpop);

            if (nchrom > 0)
                mutate(new_pop_ptr );
            /*Binary Mutation */

            if (nvar > 0)
                real_mutate(new_pop_ptr );
            /*Real Mutation*/

            new_pop_ptr = &(newpop);

            /*-------DECODING----------*/
            /*--------����-----------*/
            if(nchrom > 0)
                decode(new_pop_ptr );
            /*Decoding for binary strings*/

            /*----------FUNCTION EVALUATION-----------*/
            /*---------��Ӧ�Ⱥ�������----------*/     
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
            /*------------------���ɱ���--------------------------------*/ 
            //report(i ,old_pop_ptr ,mate_pop_ptr ,rep_ptr ,gen_ptr, lastit ,run);
            report(i ,old_pop_ptr ,mate_pop_ptr, lastit ,run);

            /*==================================================================*/

            /*----------------Rank Ratio Calculation------------------------*/
            /*----------------���㼶�����------------------------*/
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
    //�ر����ݼ�¼�ļ�
    fclose(rep_ptr);
    //fclose(gen_ptr);
    //fclose(rep2_ptr);
    //fclose(end_ptr);
    //fclose(g_var);
    fclose(lastit);
    fclose(run_time);
}
