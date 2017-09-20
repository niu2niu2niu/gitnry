#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

// 最简单的方法，归并排序，然后在新的排序后的数组中找中位数，但是时间复杂度是O(m+n)
class Solution1
{
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
        {
            int m = nums1.size();
            int n = nums2.size();
            int total = m + n;
            assert(total != 0);
            int left = 0;
            int right = 0;
            if (total % 2 == 0)
            {
                right = total / 2;
                left = right - 1;
            }
            else
            {
                right = (total - 1) / 2;
                left = right;
            }
            //cout << left << ", " << right << endl;
            int i = 0;
            int j = 0;
            vector <int> total_nums;
            while (i < m && j < n)
            {
                if (nums1[i] < nums2[j])
                    total_nums.push_back(nums1[i++]);
                else
                    total_nums.push_back(nums2[j++]);
            }
            if (i == m)
                while (j < n)
                    total_nums.push_back(nums2[j++]);
            if (j == n)
                while (i < m)
                    total_nums.push_back(nums1[i++]);
            double result = 0.0;
            result = double(total_nums[left] + total_nums[right]) / 2;
            return result;
        }
};

// 跟 solution1 思路差不多，只是已经知道了中位数的位置，可以提前停止。
class Solution2
{
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
        {
            int m = nums1.size();
            int n = nums2.size();
            int total = m + n;
            assert(total != 0);
            int left = 0;
            int right = 0;
            if (total % 2 == 0)
            {
                right = total / 2;
                left = right - 1;
            }
            else
            {
                right = (total - 1) / 2;
                left = right;
            }
            //cout << left << ", " << right << endl;
            int i = 0;
            int j = 0;
            vector <int> total_nums;
            while (i < m && j < n && total_nums.size() <= right + 1)
            {
                if (nums1[i] < nums2[j])
                    total_nums.push_back(nums1[i++]);
                else
                    total_nums.push_back(nums2[j++]);
            }
            if (i == m && total_nums.size() <= right + 1)
                while (j < n)
                    total_nums.push_back(nums2[j++]);
            if (j == n && total_nums.size() <= right + 1)
                while (i < m)
                    total_nums.push_back(nums1[i++]);
            double result = 0.0;
            result = double(total_nums[left] + total_nums[right]) / 2;
            return result;
        }
};

class Solution3
{
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
        {
            int m = nums1.size();
            int n = nums2.size();
            int total = m + n;
            int left = 0;
            int right = 0;
            if (total % 2 == 0)
            {
                right = total / 2;
                left = right - 1;
            }
            else
            {
                right = (total - 1) / 2;
                left = right;
            }
            //cout << left << ", " << right << endl;
            int i = 0;
            int j = 0;
            int num_left = 0;
            int num_right = 0;
            int count = 0;
            while (i < m && j < n && count <= left)
            {
                if (nums1[i] < nums2[j])
                    num_left = nums1[i++], count++;
                else
                    num_left = nums2[j++], count++;
            }
            if (i == m)
                while (j < n && count <= left)
                    num_left = nums2[j++], count++;
            if (j == n)
                while (i < m && count <= left)
                    num_left = nums1[i++], count++;
            //cout << "success" << endl;
            if (left < right)
                if (i == m)
                    num_right = nums2[j];
                else if (j == n)
                    num_right = nums1[i];
                else
                    num_right = min(nums1[i], nums2[j]);
            else
                num_right = num_left;
            double result = 0.0;
            result = double(num_left + num_right) / 2;
            return result;
        }
};

//class Solution4
//{
//    public:
//        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
//        {}
//};
//
template <class T> void cal_out (T & solution)
{
    vector < vector <int> > nums_list;
    // 可以直接这样初始化
//    vector <int> nums1 = {1, 3};
//    vector <int> nums2 = {2};
    vector <int> nums1;
    vector <int> nums2;
    nums1.push_back(1);
    nums1.push_back(3);
    nums2.push_back(2);
    nums_list.push_back(nums1);
    nums_list.push_back(nums2);
    nums1.clear();
    nums2.clear();
    nums1.push_back(1);
    nums1.push_back(2);
    nums2.push_back(3);
    nums2.push_back(4);
    nums_list.push_back(nums1);
    nums_list.push_back(nums2);
    nums1.clear();
    nums2.clear();
    nums1.push_back(3);
    nums1.push_back(4);
    nums_list.push_back(nums1);
    nums_list.push_back(nums2);
    double result = 0.0;
    int i = 0;
    cout << "result: ";
    // 注意 vector.size() 返回的是无符号型，进行比较的时候需要注意负数的情况
    while (i < int(nums_list.size() - 3))
    {
        vector <int> n1 = nums_list[i];
        vector <int> n2 = nums_list[i + 1];
        result = solution.findMedianSortedArrays(n1, n2);
        cout << result << ", ";
        i += 2;
    }
    vector <int> n1 = nums_list[i];
    vector <int> n2 = nums_list[i + 1];
    result = solution.findMedianSortedArrays(n1, n2);
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

//    Solution4 s4;
//    cout << "s4 ";
//    cal_out(s4);
    
    return 0;
}
