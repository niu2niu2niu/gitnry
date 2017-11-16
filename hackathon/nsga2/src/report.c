/* Routines for storing population data into files */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "global.h"
# include "rand.h"

/* Function to print the information of a population in a file */
void report_pop (population *pop, FILE *fpt)
{
    int i, j, k;
    for (i=0; i<popsize; i++)
    {
        for (j=0; j<nobj; j++)
        {
            fprintf(fpt,"%f\t",pop->ind[i].obj[j]);
        }
        if (ncon!=0)
        {
            for (j=0; j<ncon; j++)
            {
                fprintf(fpt,"%f\t",pop->ind[i].constr[j]);
            }
        }
        if (nreal!=0)
        {
            for (j=0; j<nreal; j++)
            {
                fprintf(fpt,"%f\t",pop->ind[i].xreal[j]);
            }
        }
        if (nbin!=0)
        {
            for (j=0; j<nbin; j++)
            {
                for (k=0; k<nbits[j]; k++)
                {
                    fprintf(fpt,"%d\t",pop->ind[i].gene[j][k]);
                }
            }
        }
        fprintf(fpt,"%f\t",pop->ind[i].constr_violation);
        fprintf(fpt,"%d\t",pop->ind[i].rank);
        fprintf(fpt,"%f\n",pop->ind[i].crowd_dist);
    }
    return;
}

/* Function to print the information of feasible and non-dominated population in a file */
void report_feasible (population *pop, FILE *fpt)
{
    int i, j, k;
    for (i=0; i<popsize; i++)
    {
        if (pop->ind[i].constr_violation == 0.0 && pop->ind[i].rank==1)
        {
            for (j=0; j<nobj; j++)
            {
                fprintf(fpt,"%f\t",pop->ind[i].obj[j]);
            }
            if (ncon!=0)
            {
                for (j=0; j<ncon; j++)
                {
                    fprintf(fpt,"%f\t",pop->ind[i].constr[j]);
                }
            }
            if (nreal!=0)
            {
                for (j=0; j<nreal; j++)
                {
                    fprintf(fpt,"%f\t",pop->ind[i].xreal[j]);
                }
            }
            if (nbin!=0)
            {
                for (j=0; j<nbin; j++)
                {
                    for (k=0; k<nbits[j]; k++)
                    {
                        fprintf(fpt,"%d\t",pop->ind[i].gene[j][k]);
                    }
                }
            }
            fprintf(fpt,"%f\t",pop->ind[i].constr_violation);
            fprintf(fpt,"%d\t",pop->ind[i].rank);
            fprintf(fpt,"%f\n",pop->ind[i].crowd_dist);
        }
    }
    return;
}

void report_pop_task (population *pop, FILE *fpt)
{
    int i, j, k;
    for (i=0; i<popsize; i++)
    {
        for (j=0; j<nobj; j++)
            fprintf(fpt,"%f\t",pop->ind[i].obj[j]);
        for (j=0; j<t_param.t_num; j++)
        {
            int task_id = pop->ind[i].chri.t[j];
            int method_id = pop->ind[i].chri.m[j];
            int time = meth[task_id].time[method_id];
            fprintf(fpt,"(t:%d m:%d time:%d ", task_id, method_id, time);
            for (k = 1; k < t_param.r_max_num; k++)
            {
                int r = meth[task_id].r[method_id][k];
                if (r == 0) break;
                else fprintf(fpt, "r:%d ", r);
            }
            int t_time = pop->ind[i].chri.t_time[j];
            fprintf(fpt,"t_time:%d),", t_time);
        }
        fprintf(fpt,"\n");
    }
    return;
}
