#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define task_num 20

typedef struct
{
    int *m;
    int r[6][4];
    int time[6];

}method;
method *meth;

int main(int argc, char** argv)
{
    //    char a[] = "nreal=20";
    ////    char *tmp = strtok(a, "=");
    ////    printf("%s\n", tmp);
    ////    tmp = strtok(NULL, "=");
    ////    printf("%s\n", tmp);
    //    char b[] = "nreal=20";
    //    if (strcmp(a,b) == 0)
    //        printf("true\n");
    int meth_num = 6;
    meth = (method*)malloc(sizeof(method) * (task_num + 1));
    meth->m = (int*)malloc(sizeof(int) * meth_num);

    meth[1].m[1] = 1;
    meth[1].m[2] = 2;
    meth[1].m[3] = 3;
    meth[1].m[4] = 0;
    meth[1].m[5] = 0;

    free(meth->m);
    free(meth);
    return 0;
}
