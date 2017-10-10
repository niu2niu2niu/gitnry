#include <iostream>
#include <stdio.h>
#include <string.h>
#include <assert.h>

using namespace std;

char *my_strcpy(char *dst,const char *src)  
{  
    assert(dst != NULL);  
    assert(src != NULL);  
    char *ret = dst;  
    while((* dst++ = * src++) != '\0');
    return ret;  
}  

//int main(int argc, char** argv)
//{
//    char str[10]="abc";  
//    strcpy(str+1, str);
//    printf("strcpy: %s\n", str+1);
//    my_strcpy(str+1,str);
//    printf("my strcpy: %s\n", str+1);
//    return 0;
//}

int main(int argc, char** argv)
{
    int a = 3/2;
    cout << a << endl;
    return 0;
}
