#include <iostream>
#include <vector>

using namespace std;

// 最简单的递归代码，时间复杂度贼高。
int solution1(int n)
{
    if (n < 2)
        return n;
    return solution1(n - 1) + solution1(n - 2);
}

// 记录已经计算出来的结果，降低时间复杂度。
int solution2(int n, vector<int> &fn)
{
    if (fn[n] != -1)
        return fn[n];
    if (n < 2)
        fn[n] = n;
    else
        fn[n] = solution2(n - 1, fn) + solution2(n - 2, fn);
    return fn[n];
}

// 上面的 2 种方法依然用到了递归，有栈溢出的风险，而且 solution2 的空间复杂度略高。
// 尝试用循环的方式替代递归。
int solution3(int n, vector<int> &fn)
{
    fn[0] = 0;
    fn[1] = 1;
    for (int i = 2; i <= n; i++)
        fn[i] = fn[i - 1] + fn[i - 2];
    return fn[n];
}

// 但是 solution3 的空间复杂度依旧比较大，其实可以不必所有结果都存储的，因为每次只需要前面 2 个结果。
int solution4(int n)
{
    int f_n1 = 1;
    int f_n2 = 0;
    int f_n = 0;
    for (int i = 2; i <= n; i++)
    {
        f_n = f_n1 + f_n2;
        f_n2 = f_n1;
        f_n1 = f_n;
    }
    return f_n;
}

int main(int argc, char** argv)
{
    int n = 8;
    int result = 0;
    result = solution1(n);
    cout << result << endl;

    // 注意，n = 8 说明需要计算 f(8)，所以是从 f(0)~f(8) 一共 9 个数。
    vector<int> fn(n + 1, -1);
    result = solution2(n, fn);
    cout << result << endl;

    for (int i = 0; i < n + 1; i++)
        fn[i] = -1;
    result = solution3(n, fn);
    cout << result << endl;

    result = solution4(n);
    cout << result << endl;

    return 0;
}
