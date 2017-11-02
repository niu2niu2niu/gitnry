#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "global.h"
#include "rand.h"
#include "read_conf.h"

#define MAX_LINE 1024

char prob_name[MAX_LINE];

void read_conf(FILE *f)
{
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, f))
    {
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
    return;
}
