//#include <iostream>
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//using namespace std;
//
//char *my_strcpy(char *dst,const char *src)  
//{  
//    assert(dst != NULL);  
//    assert(src != NULL);  
//    char *ret = dst;  
//    while((* dst++ = * src++) != '\0');
//    return ret;  
//}  

//int main(int argc, char** argv)
//{
//    char str[10]="abc";  
//    strcpy(str+1, str);
//    printf("strcpy: %s\n", str+1);
//    my_strcpy(str+1,str);
//    printf("my strcpy: %s\n", str+1);
//    return 0;
//}

//long long res = 0;
//void gz(int last, long long val)
//{
//    for(int i=9;i>0;--i)
//    {
//        if(i>last) continue;
//        if(i==val%10) continue;
//        val = val*10 + i;
//        gz(last - i, val);
//        if(val> res) 
//            res = val;
//        val /=10;
//    }
//}
//
//int main(int argc, char** argv)
//{
//    int num;
//    cin>>num;
//    gz(num, 0);
//    cout<<res<<endl;
//    return 0;
//}

//void big(int x)
//{
//    //2 start
//    int n=0,two=1,s=0,start;
//    while(s<x){
//        n++;
//        if(two ==1){
//            s+=2;
//            two=0;
//        }
//        else{
//            s+=1;
//            two=1;
//        }
//    }
//    if(s==x)
//        start=2;
//    else
//        start=1;
//    //cout<<"n:"<<n<<"S:"<<start<<"r:  ";
//    //cout<<"P:"<<pow(10,0);
//    while(n>0){
//        cout<<start;
//        start+=1;
//        if(start==3)start=1;
//        n--;
//    }
//    //return res;
//}
//
//int main()
//{
//    int s;
//    cin >>s;
//    big(s);
//    //cout << res<< endl;
//    return 0;
//}

//int main(){
//    int n;
//    while(cin>>n)
//    {
//
//    int ar[1000] = {0};
//if(n%3==1){
//    ar[0] = 1;
//    n -= 1;
//}
//else{
//    ar[0] = 2;
//    n -= 2;
//}
//int i = 0;
//while(n > 0){
//    if(ar[i] == 1){
//        ar[i+1] = 2;n -= 2;}
//    else{
//        ar[i+1] = 1; n -= 1;
//    }
//    i++;
//}
//
//for(int j = 0; j <=i; j++){
//    cout<<ar[j];
//}
//    }
//return 0;
//}

//int main(){
//    int s, i,j,k,t;
//    int a[28];
//    printf("请输入数字之和");
//    scanf("%d",&s);
//    if(s==1) 
//        printf("1");
//    else if (s==2)
//        printf("2");
//         else { i=s % 3;
//                j = s/3;
//               if(i==2){
//                  a[0]=2;
//                  for(k=1;k<=j;k++){
//                     t=2*k-1;
//                     a[t]=1;
//                     a[t+1]=2;
//                 } } if(i==0){ 
//                      for(k=1;k<=j;k++){
//                          t=2*k-2;
//                          a[t]=2;
//                          a[t+1]=1;
//                      } 
//                 } else { 
//                     a[0]=1;
//                     for(k=1;k<=j;k++){
//                      t=2*k-1;
//                      a[t]=2;
//                      a[t+1]=1;
//                     }
//                 }
//              }
//   i=0;
//while(a[i])
//printf("%d", a[i++]); 
//        
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[43][10];
int getVal(int n, int tail)
{
    if (n <= 0)
        return 0;
    else
        return A[n][tail];
}

int bignum = 0;

void find(int n, int tail)
{
    if (n <= 0)
        return;
    int tempmax = 0;
    for (int i = 1; i <= 9; ++i)
    {
            if (i == tail)
                continue;
            if (getVal(n - tail, i) == 0)
                find(n - tail, i);
            if (getVal(n - tail, i) > tempmax)
                tempmax = getVal(n - tail, i);
        }
        A[n][tail] = tempmax * 10 + tail;
            if (A[n][tail] > bignum)
                        bignum = A[n][tail];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 9; ++i)
        find(n, i);
    cout << bignum << endl;
    return 0;
}
