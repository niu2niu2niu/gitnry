#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution1
{
    public:
        int BinarySearch(int *num_list_sorted, int len, int value)
        {
            int left = 0;
            int right = len;
            while(left < right)
            {
                //int middle = (left + right) / 2;
                // 上面的写法也可以，但是有溢出的风险
                int middle = left + ((right - left) / 2);
                if(num_list_sorted[middle] == value)
                    return middle;
                if(num_list_sorted[middle] > value)
                    right = middle;
                else
                    left = middle + 1;
            }
            return -1;
        }
};

// 代码细节上的一些小优化
class Solution2
{
    public:
        int BinarySearch(int *num_list_sorted, int len, int value)
        {
            int left = 0;
            int right = len;
            while (left < right)
            {
                // 用移位的方法代替除法也挺好，就是可读性会差一些。
                int middle = left + ((right - left) >> 1);
                if (num_list_sorted[middle] > value)
                    right = middle;
                else if (num_list_sorted[middle] < value)
                    left = middle + 1;
                else
                    return middle;
                // 可能会有读者认为刚开始时就要判断相等，但毕竟数组中不相等的情况更多
                // 如果每次循环都判断一下是否相等，将耗费时间
            }
            return -1;
        }
};

// 如果数组中有重复元素，返回第一次出现的下标
class Solution3
{
    public:
        int BinarySearch(int *num_list_sorted, int len, int value)
        {
            int left = 0;
            int right = len;
            if (len == 0) return -1;
            while (left < right)
            {
                int middle = left + ((right - left) >> 1);
                if (num_list_sorted[middle] >= value)
                    right = middle;
                else
                    left = middle + 1;
            }
            if (right < len && num_list_sorted[right] == value)
                return right;
            else
                return -1;
        }
};

// 如果数组中有重复元素，返回最后一次出现的下标
class Solution4
{
    public:
        int BinarySearch(int *num_list_sorted, int len, int value)
        {
            int left = 0;
            int right = len;
            if (len == 0) return -1;
            while (left < right)
            {
                int middle = left + ((right - left) >> 1);
                if (num_list_sorted[middle] > value)
                    right = middle;
                else
                    left = middle + 1;
            }
            if (right - 1 > -1 && num_list_sorted[right - 1] == value)
                return right - 1;
            else
                return -1;
        }
};

// 查找第一个大于 value 的元素的下标
class Solution5
{
    public:
        int BinarySearch(int *num_list_sorted, int len, int value)
        {
            int left = 0;
            int right = len;
            if (len == 0) return -1;
            while (left < right)
            {
                int middle = left + ((right - left) >> 1);
                if (num_list_sorted[middle] > value)
                    right = middle;
                else
                    left = middle + 1;
            }
            if (right < len)
                return right;
            else
                return -1;
        }
};

// 查找第一个等于或大于 value 的元素的下标
class Solution6
{
    public:
        int BinarySearch(int *num_list_sorted, int len, int value)
        {
            int left = 0;
            int right = len;
            if (len == 0) return -1;
            while (left < right)
            {
                int middle = left + ((right - left) >> 1);
                if (num_list_sorted[middle] >= value)
                    right = middle;
                else
                    left = middle + 1;
            }
            if (right < len)
                return right;
            else
                return -1;
        }
};

// 查找最后一个小于 value 的元素的下标
class Solution7
{
    public:
        int BinarySearch(int *num_list_sorted, int len, int value)
        {
            int left = 0;
            int right = len;
            if (len == 0) return -1;
            while (left < right)
            {
                int middle = left + ((right - left) >> 1);
                if (num_list_sorted[middle] >= value)
                    right = middle;
                else
                    left = middle + 1;
            }
            //if (right - 1 > -1)
            //    return right - 1;
            //else
            //    return -1;
            return right - 1;
        }
};

// 查找最后一个小于或等于 value 的元素的下标
class Solution8
{
    public:
        int BinarySearch(int *num_list_sorted, int len, int value)
        {
            int left = 0;
            int right = len;
            if (len == 0) return -1;
            while (left < right)
            {
                int middle = left + ((right - left) >> 1);
                if (num_list_sorted[middle] > value)
                    right = middle;
                else
                    left = middle + 1;
            }
            //if (right - 1 > -1)
            //    return right - 1;
            //else
            //    return -1;
            return right - 1;
        }
};

template <class T> void cal_out (T & solution)
{
    int case_size = 2;
    int a1[14] = {0, 1, 2, 4, 4, 4, 4, 4, 4, 5, 6, 7, 8, 9};
    int a2[1] = {0};
    int size_arr[] = {14, 1};
    int **p;
    p = new int*[case_size];
    p[0] = a1;
    p[1] = a2;
    vector <int> value_l = {-2, 0, 3, 4, 8, 20};
    cout << " result:" << endl;
    for (int i = 0; i < case_size; i++)
    {
        int result = 0;
        // 为了防止 size 的无符号型减法出类型转换错误的问题，这里使用加法来做判断条件。
        int j = 0;
        while (j + 1 < value_l.size())
        {
            result = solution.BinarySearch(p[i], size_arr[i], value_l[j]);
            cout << result << ", ";
            j++;
        }
        result = solution.BinarySearch(p[i], size_arr[i], value_l[j]);
        cout << result << endl;
    }
    delete [] p;
    cout << endl;
    return;
}

int main(int argc, char** argv)
{
    Solution1 s1;
    cout << "s1：简单二分查找";
    cal_out(s1);
    Solution2 s2;
    cout << "s2：简单二分查找 - 代码优化";
    cal_out(s2);
    Solution3 s3;
    cout << "s3：如果数组中有重复元素，返回第一次出现的下标";
    cal_out(s3);
    Solution4 s4;
    cout << "s4：如果数组中有重复元素，返回最后一次出现的下标";
    cal_out(s4);
    Solution5 s5;
    cout << "s5：查找第一个大于 value 的元素的下标";
    cal_out(s5);
    Solution6 s6;
    cout << "s6：查找第一个等于或大于 value 的元素的下标";
    cal_out(s6);
    Solution7 s7;
    cout << "s7：查找第一个小于 value 的元素的下标";
    cal_out(s7);
    Solution8 s8;
    cout << "s8：查找最后一个小于等于 value 的元素的下标";
    cal_out(s8);
    return 0;
}
