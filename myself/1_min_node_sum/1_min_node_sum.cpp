#include <iostream>
#include <stdio.h>
#include <vector>
#define N 4

using namespace std;

// 递归的代码挺简单的，但是时间复杂度是2^N，特别容易超时
int MinSum1(vector< vector<int> > &D, int i, int j)
{
    if(i==N)
        return D[i][j];
    int x = MinSum1(D, i+1, j);
    int y = MinSum1(D, i+1, j+1);
    return min(x,y) + D[i][j];
}

// 递归超时的主要原因是有大量重复计算。避免重复计算的一个方法是把中间结果都保存下来。
int MinSum2(vector< vector<int> > &D, vector< vector<int> > &minSum, int i, int j)
{
    if( minSum[i][j] != 0 )
        return minSum[i][j];
    if(i==N)
        minSum[i][j] = D[i][j];
    else
    {
        int x = MinSum2(D, minSum, i+1,j);
        int y = MinSum2(D, minSum, i+1,j+1);
        minSum[i][j] = min(x,y)+ D[i][j];
    }
    return minSum[i][j];
}

// 我们仍然不满足于递归的写法，因为递归非常容易栈溢出，我们希望使用递推（dp）的方法来做。
// 从下往上层层递推。
int MinSum3(vector< vector<int> > &D, vector< vector<int> > &minSum)
{
    for( int i = 1;i <= N; ++ i )
        minSum[N][i] = D[N][i];
    for( int i = N-1; i>= 1;  --i )
        for( int j = 1; j <= i; ++j )
            minSum[i][j] = min(minSum[i+1][j],minSum[i+1][j+1]) + D[i][j];
    return minSum[1][1];
}

// 虽然 dp 的方法效率很好，但是空间复杂度上去了。
// 仔细想想其实不需要这么多空间，只要一维数组记录每层的最值即可。
int MinSum4(vector< vector<int> > &D)
{
    vector<int> dp(N+1, 0);
    for( int i = 1;i <= N; ++ i )
        dp[i] = D[N][i];
    for( int i = N-1; i>= 1;  --i )
        for( int j = 1; j <= i; ++j )
            dp[j] = min(dp[j], dp[j+1]) + D[i][j];
    return dp[1];
}

int main(int argc, char** argv)
{
    int A[N*N] = {13,0,0,0,5,7,0,0,21,12,40,0,3,5,22,33};
    vector< vector<int> > A_v(N+1);
    vector<int> a_v(N+1);
    int i = 0;
    int j = 0;
    printf("nodes:\n");
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            a_v[j+1] = A[i*N+j];
            printf("%d\t",A[i*N+j]);
        }
        A_v[i+1] = a_v;
        printf("\n");
    }
    int min_sum = 0;
    min_sum = MinSum1(A_v, 1, 1);
    printf("min node sum: %d\n", min_sum);

    // 注意这种初始化二维数组的方式。可以匿名内部数组。
    vector< vector<int> > minSum(N+1, vector<int> (N+1, 0));
    min_sum = MinSum2(A_v, minSum, 1, 1);
    printf("min node sum: %d\n", min_sum);

    min_sum = MinSum3(A_v, minSum);
    printf("min node sum: %d\n", min_sum);

    min_sum = MinSum4(A_v);
    printf("min node sum: %d\n", min_sum);

    return 0;
}
