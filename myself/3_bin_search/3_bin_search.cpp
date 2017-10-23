#include <iostream>
#include <vector>

using namespace std;

class Solution1
{
    public:
        int BinarySearch(vector<int> &num_list_sorted, int value)
        {
            int left = 0;
            int right = num_list_sorted.size() - 1;
            int middle = 0;
            while(left <= right)
            {
                //middle = (left + right) / 2;
                // 上面的写法也可以，但是有溢出的风险
                middle = left + ((right - left) / 2);
                if(num_list_sorted[middle] == value)
                    return middle;
                if(num_list_sorted[middle] > value)
                    right = middle - 1;
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
        int BinarySearch(vector<int> &num_list_sorted, int value)
        {
            int left = 0;
            int right = num_list_sorted.size() - 1;
            while (left <= right)
            {
                // 用移位的方法代替除法也挺好，就是可读性会差一些。
                int middle = left + ((right - left) >> 1);
                if (num_list_sorted[middle] > value)
                    right = middle - 1;
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
        int BinarySearch(vector<int> &num_list_sorted, int value)
        {
            int left = 0;
            int right = num_list_sorted.size() - 1;
            if (right == -1) return -1;
            while (left <= right)
            {
                int middle = left + ((right - left) >> 1);
                if (num_list_sorted[middle] >= value)
                    right = middle - 1;
                else
                    left = middle + 1;
            }
            //return num_list_sorted[right + 1] == value ? right + 1 : -1;
            // 注意到循环结束之后 left 和 right 的关系一定是 left > right，也就是 left = right + 1。所以下面的写法会比上面的简洁一些。至于哪个写法更好理解就看个人了。
            return num_list_sorted[left] == value ? left : -1;
        }
};

// 如果数组中有重复元素，返回最后一次出现的下标
class Solution4
{
    public:
        int BinarySearch(vector<int> &num_list_sorted, int value)
        {
            int left = 0;
            int right = num_list_sorted.size() - 1;
            if (right == -1) return -1;
            while (left <= right)
            {
                int middle = left + ((right - left) >> 1);
                if (num_list_sorted[middle] > value)
                    right = middle - 1;
                else
                    left = middle + 1;
            }
            return num_list_sorted[right] == value ? right : -1;
        }
};

// 查找最接近且大于 value 的元素的下标
class Solution5
{
    public:
        int BinarySearch(vector<int> &num_list_sorted, int value)
        {
            int left = 0;
            int right = num_list_sorted.size() - 1;
            if (right == -1) return -1;
            while (left <= right)
            {
                int middle = left + ((right - left) >> 1);
                if (num_list_sorted[middle] > value)
                    right = middle - 1;
                else
                    left = middle + 1;
            }
            //return num_list_sorted[left] > value ? left : -1;
            return left;
        }
};

// 查找第一个等于或大于 value 的元素的下标
class Solution6
{
    public:
        int BinarySearch(vector<int> &num_list_sorted, int value)
        {
            int left = 0;
            int right = num_list_sorted.size() - 1;
            if (right == -1) return -1;
            while (left <= right)
            {
                int middle = left + ((right - left) >> 1);
                if (num_list_sorted[middle] >= value)
                    right = middle - 1;
                else
                    left = middle + 1;
            }
            return left;
        }
};

// 查找最接近且小于 value 的元素的下标
class Solution7
{
    public:
        int BinarySearch(vector<int> &num_list_sorted, int value)
        {
            int left = 0;
            int right = num_list_sorted.size() - 1;
            if (right == -1) return -1;
            while (left <= right)
            {
                int middle = left + ((right - left) >> 1);
                if (num_list_sorted[middle] >= value)
                    right = middle - 1;
                else
                    left = middle + 1;
            }
            //return num_list_sorted[right] < value ? right : -1;
            return right;
        }
};

// 查找最后一个小于等于 value 的元素的下标
class Solution8
{
    public:
        int BinarySearch(vector<int> &num_list_sorted, int value)
        {
            int left = 0;
            int right = num_list_sorted.size() - 1;
            //if (right == -1) return -1;
            while (left <= right)
            {
                int middle = left + ((right - left) >> 1);
                if (num_list_sorted[middle] > value)
                    right = middle - 1;
                else
                    left = middle + 1;
            }
            return right;
        }
};

template <class T> void cal_out (T & solution)
{
    vector <int> num_list_sorted = {0, 1, 2, 4, 4, 4, 4, 4, 4, 5, 6, 7, 8, 9};
    vector <int> value_l = {3, 4, 8};
    int result = 0;
    int i = 0;
    cout << "result: ";
    // 为了防止 size 的无符号型减法出类型转换错误的问题，这里使用加法来做判断条件。
    while (i + 1 < value_l.size())
    {
        result = solution.BinarySearch(num_list_sorted, value_l[i]);
        cout << result << ", ";
        i++;
    }
    result = solution.BinarySearch(num_list_sorted, value_l[i]);
    cout << result << endl;
    return;
}

int main(int argc, char** argv)
{
    Solution1 s1;
    cout << "s1 ";
    cal_out(s1);
    Solution2 s2;
    cout << "s2 ";
    cal_out(s2);
    Solution3 s3;
    cout << "s3 ";
    cal_out(s3);
    Solution4 s4;
    cout << "s4 ";
    cal_out(s4);
    Solution5 s5;
    cout << "s5 ";
    cal_out(s5);
    Solution6 s6;
    cout << "s6 ";
    cal_out(s6);
    Solution7 s7;
    cout << "s7 ";
    cal_out(s7);
    Solution8 s8;
    cout << "s8 ";
    cal_out(s8);
    return 0;
}
