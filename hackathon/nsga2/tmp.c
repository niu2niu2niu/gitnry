#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define task_num 20

typedef struct
{
    int t_num;
}task_param;

task_param t_param;

int main(int argc, char** argv)
{
    t_param.t_num = 20;
    //    char a[] = "nreal=20";
    ////    char *tmp = strtok(a, "=");
    ////    printf("%s\n", tmp);
    ////    tmp = strtok(NULL, "=");
    ////    printf("%s\n", tmp);
    //    char b[] = "nreal=20";
    //    if (strcmp(a,b) == 0)
    //        printf("true\n");
    return 0;
}
