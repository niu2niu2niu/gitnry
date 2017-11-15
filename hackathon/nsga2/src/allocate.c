/* Memory allocation and deallocation routines */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <memory.h>

# include "global.h"
# include "rand.h"

method *meth;
int **restraint;
int **restraint_comp;

/* Function to allocate memory to a population */
void allocate_memory_pop (population *pop, int size)
{
    int i;
    pop->ind = (individual *)malloc(size*sizeof(individual));
    for (i=0; i<size; i++)
    {
        allocate_memory_ind (&(pop->ind[i]));
    }
    return;
}

/* Function to allocate memory to an individual */
void allocate_memory_ind (individual *ind)
{
    int j;
    if (nreal != 0)
    {
        ind->xreal = (double *)malloc(nreal*sizeof(double));
        ind->chri.t = (int*)malloc(sizeof(int) * t_param.t_num);
        memset(ind->chri.t, 0, (sizeof(int) * t_param.t_num));
        ind->chri.m = (int*)malloc(sizeof(int) * t_param.t_num);
        memset(ind->chri.m, 0, (sizeof(int) * t_param.t_num));
        ind->chri.t_time = (int*)malloc(sizeof(int) * t_param.t_num);
        memset(ind->chri.t_time, 0, (sizeof(int) * t_param.t_num));
    }
    if (nbin != 0)
    {
        ind->xbin = (double *)malloc(nbin*sizeof(double));
        ind->gene = (int **)malloc(nbin*sizeof(int *));
        for (j=0; j<nbin; j++)
        {
            ind->gene[j] = (int *)malloc(nbits[j]*sizeof(int));
        }
    }
    ind->obj = (double *)malloc(nobj*sizeof(double));
    if (ncon != 0)
    {
        ind->constr = (double *)malloc(ncon*sizeof(double));
    }
    return;
}

/* Function to deallocate memory to a population */
void deallocate_memory_pop (population *pop, int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        deallocate_memory_ind (&(pop->ind[i]));
    }
    free (pop->ind);
    return;
}

/* Function to deallocate memory to an individual */
void deallocate_memory_ind (individual *ind)
{
    int j;
    if (nreal != 0)
    {
        free(ind->xreal);
        free(ind->chri.t);
        free(ind->chri.m);
        free(ind->chri.t_time);
    }
    if (nbin != 0)
    {
        for (j=0; j<nbin; j++)
        {
            free(ind->gene[j]);
        }
        free(ind->xbin);
        free(ind->gene);
    }
    free(ind->obj);
    if (ncon != 0)
    {
        free(ind->constr);
    }
    return;
}

void allocate_prob()
{
    int i = 0;
    meth = (method*)malloc(sizeof(method) * (t_param.t_num + 1));
    for(i = 0; i < t_param.t_num + 1; i++)
    {
        meth[i].m = (int*)malloc(sizeof(int) * (t_param.meth_num + 1));
        memset(meth[i].m, 0, (sizeof(int) * (t_param.meth_num + 1)));
        meth[i].time = (int*)malloc(sizeof(int) * (t_param.meth_num + 1));
        memset(meth[i].time, 0, (sizeof(int) * (t_param.meth_num + 1)));
        meth[i].r = (int**)malloc(sizeof(int*) * (t_param.meth_num + 1));
        memset(meth[i].r, 0, (sizeof(int*) * (t_param.meth_num + 1)));
        for(int j = 0; j < t_param.meth_num + 1; j++)
        {
            meth[i].r[j] = (int*)malloc(sizeof(int) * (t_param.r_max_num + 1));
            memset(meth[i].r[j], 0, sizeof(int) * (t_param.r_max_num + 1));
        }
    }

    restraint = (int**)malloc(sizeof(int*) * t_param.t_num);
    restraint[0] = (int*)malloc(sizeof(int) * t_param.t_num * t_param.t_num);
    for(i = 1; i < t_param.t_num; i++)
        restraint[i] = restraint[i - 1] + t_param.t_num;

    restraint_comp = (int**)malloc(sizeof(int*) * t_param.t_num);
    restraint_comp[0] = (int*)malloc(sizeof(int) * t_param.t_num * t_param.t_num);
    for (i = 1; i < t_param.t_num; i++)
        restraint_comp[i] = restraint_comp[i - 1] + t_param.t_num;
}

void deallocate_prob()
{
    int i = 0;
    for(i = 0; i < t_param.t_num + 1; i++)
    {
        free(meth[i].m);
        free(meth[i].time);
        for(int j = 0; j < t_param.meth_num + 1; j++)
            free(meth[i].r[j]);
        free(meth[i].r);
    }
    free(meth);
    free(restraint[0]);
    free(restraint);
    free(restraint_comp[0]);
    free(restraint_comp);
}
