#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "global.h"
#include "rand.h"
#include "read_file.h"


//char prob_name[MAX_LINE];

//task_param t_param;

void read_run_param()
{
    FILE *f;
    f = fopen("input_data_param/run_param.txt","r");
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, f))
    {
        if (line[0] == '#') continue;
        char *name = strtok(line, "=");
        char *value = strtok(NULL, "=");
        if (strcmp(name, "seed") == 0)
            seed = atof(value);
        if (strcmp(name, "popsize") == 0)
            popsize = atoi(value);
        if (strcmp(name, "ngen") == 0)
            ngen = atoi(value);
        if (strcmp(name, "nobj") == 0)
            nobj = atoi(value);
        if (strcmp(name, "ncon") == 0)
            ncon = atoi(value);
        if (strcmp(name, "nreal") == 0)
            nreal = atoi(value);
        if (strcmp(name, "pcross_real") == 0)
            pcross_real = atof(value);
        if (strcmp(name, "pmut_real") == 0)
            pmut_real = atof(value);
        if (strcmp(name, "eta_c") == 0)
            eta_c = atoi(value);
        if (strcmp(name, "eta_m") == 0)
            eta_m = atoi(value);
        if (strcmp(name, "nbin") == 0)
            nbin = atoi(value);
        if (strcmp(name, "prob_name") == 0)
            strcpy(prob_name, value);
    }
    //printf("prob_name: %s\n", prob_name);
    fclose(f);
    return;
}

void read_prob_param()
{
    FILE *f;
    if (strcmp(prob_name, "ptts\n") == 0)
        f = fopen("input_data_param/ptts_param.txt", "r");
    else if (strcmp(prob_name, "cook\n") == 0)
        f = fopen("input_data_param/cook_param.txt", "r");
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, f))
    {
        char *name = strtok(line, "=");
        char *value = strtok(NULL, "=");
        if (strcmp(name, "t_num") == 0)
            t_param.t_num = atoi(value);
        if (strcmp(name, "meth_max_num") == 0)
            t_param.meth_max_num = atoi(value);
        if (strcmp(name, "r_max_num") == 0)
            t_param.r_max_num = atoi(value);
    }
    printf("t_num: %d\n", t_param.t_num);
    printf("meth_max_num: %d\n", t_param.meth_max_num);
    printf("r_max_num: %d\n", t_param.r_max_num);
    fclose(f);
    return;
}
