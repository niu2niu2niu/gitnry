#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    char a[] = "nreal=20";
//    char *tmp = strtok(a, "=");
//    printf("%s\n", tmp);
//    tmp = strtok(NULL, "=");
//    printf("%s\n", tmp);
    char b[] = "nreal=20";
    if (strcmp(a,b) == 0)
        printf("true\n");
    return 0;
}
