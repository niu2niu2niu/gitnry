#include <iostream>
#include <vector>

using namespace std;

int BinSearch(int* R, int n, int K)
{
    int low = 0, high = n - 1, mid;
    while(low<=high)
    {
        mid=low+((high-low)/2);
        /*使用(low+high)/2会有整数溢出的问题
          （问题会出现在当low+high的结果大于表达式结果类型所能表示的最大值时，
          这样，产生溢出后再/2是不会产生正确结果的，而low+((high-low)/2)
          不存在这个问题*/
        if(R[mid]==K)
            return mid;             //查找成功返回
        if(R[mid]<K)
            low=mid+1;              //继续在R[mid+1..high]中查找
        else
            high=mid-1;             //继续在R[low..mid-1]中查找
    }
    return -1;//当low>high时表示所查找区间内没有结果，查找失败
}

int main(int argc, char** argv)
{
    int l[] = {0, 1, 2, 4, 5, 6, 7, 8, 9};
    int res;
    res = BinSearch(l, 7, 3);
    cout << res << endl;
    res = BinSearch(l, 7, 4);
    cout << res << endl;
    return 0;
}
