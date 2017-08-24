#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 题目有假设：
// （1）每个输入只有一个 solution
// （2）每个元素只使用一次

// simplest, brute force
class Solution1
{
    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            vector<int> result;
            int i = 0;
            int j = 0;
            int size = nums.size();
            for (i = 0; i < size; i++)
            {
                for (j = i + 1; j < size; j++)
                {
                    if (nums[i] + nums[j] == target)
                    {
                        result.push_back(i);
                        result.push_back(j);
                        return result;
                    }
                }
            }
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
};

// use hash to search
class Solution2
{
    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            vector<int> result;
            unordered_map<int, int> int_map;
            int i = 0;
            int size = nums.size();
            for (i = 0; i < size; i++)
            {
                int_map[nums[i]] = i;
            }
            for (i = 0; i < size; i++)
            {
                int other = target - nums[i];
                unordered_map<int, int>::iterator iter = int_map.find(other);
                if (iter != int_map.end() && iter->second != i)
                {
                    result.push_back(i);
                    result.push_back(iter->second);
                    return result;
                }
            }
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
};

// use hash to search inverse
class Solution3
{
    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            vector<int> result;
            unordered_map<int, int> int_map;
            int i = 0;
            int size = nums.size();
            for (i = 0; i < size; i++)
            {
                int other = target - nums[i];
                unordered_map<int, int>::iterator iter = int_map.find(other);
                if (iter != int_map.end())
                {
                    result.push_back(i);
                    result.push_back(iter->second);
                    return result;
                }
                int_map[nums[i]] = i;
            }
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
};

int main(int argc, char** argv)
{
    int target = 9;

    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    
    cout << "target: " << target << endl;
    cout << "nums: ";
    vector<int>::iterator iter;
    for (iter = nums.begin(); iter < nums.end() - 1; iter++)
    {
        cout << *iter << ", ";
    }
    cout << *iter << endl;

    vector<int> result(2);
    Solution1 s1;
    result = s1.twoSum(nums, target);
    cout << "result1: " << result[0] << ", " << result[1] << endl;

    Solution2 s2;
    result = s2.twoSum(nums, target);
    cout << "result2: " << result[0] << ", " << result[1] << endl;

    Solution3 s3;
    result = s3.twoSum(nums, target);
    cout << "result3: " << result[0] << ", " << result[1] << endl;

    return 0;
}
