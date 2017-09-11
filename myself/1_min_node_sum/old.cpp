#include <iostream>
#include <stdio.h>
#define N 4

void FindMinSum (int *A, int i, int &MinSum, int &CurrSum)
{
    if (i == 0)
    {
        if (MinSum > CurrSum)
            MinSum = CurrSum;
        return;
    }

    CurrSum += A[0];
    FindMinSum(A+N,i-1,MinSum,CurrSum); // A+N就跑到正下方去了，A+N+1就是正下方的右侧一个邻位，由于规定了只能走这2个位置，所以每次矩阵都是一个下三角矩阵，而且维度减一。
    FindMinSum(A+N+1,i-1,MinSum,CurrSum);
    CurrSum -= A[0]; // 注意回溯法的状态复原
}

int main(int argc, char** argv)
{
    int A[N*N] = {13,0,0,0,5,7,0,0,21,12,40,0,3,5,22,33};
    int i = 0;
    int j = 0;
    printf("nodes:\n");
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            printf("%d\t",A[i*N+j]);
        }
        printf("\n");
    }

    int MinSum = 1000;
    int CurrSum = 0;
    FindMinSum(A,N,MinSum,CurrSum);
    printf("min node sum: %d\n", MinSum);

    return 0;
}
