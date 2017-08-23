/*************************************************************************
   > File Name: longest_substring_without_repeating_characters.cpp
   > Author: MT_NLP_Team
   > Mail: tne.nlp@meituan.com
   > Created Time: 09:15:18 2017-08-14
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

// myself
class Solution1
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            int result = 0;
            int len = s.length();
            int i = 0;
            int j = 0;
            // i is the start pos of substring
            for (i = 0; i < len; i++)
            {
                unordered_map<char, int> s_i_map;
                unordered_map<char, int>::iterator iter;
                // j is the end pos of substring
                for (j = i + 1; j < len; j++)
                {
                    // everytime you store the (j-1) element into map
                    s_i_map[s[j - 1]] = j - 1;
                    iter = s_i_map.find(s[j]);
                    // has duplicate character
                    if (iter != s_i_map.end())
                        break;
                }
                // be careful about the num of map without duplicate char is (j-i)
                result = (result > j - i) ? result : (j - i);
            }
            return result;
        }
};

// myself optimize
// solution1 update i by one step
class Solution2
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            int result = 0;
            int len = s.length();
            int i = 0;
            int j = 0;
            // i is the start pos of substring
            while (i < len)
            {
                unordered_map<char, int> s_i_map;
                unordered_map<char, int>::iterator iter;
                int j_dup = 0;
                // j is the end pos of substring
                for (j = i + 1; j < len; j++)
                {
                    // everytime you store the (j-1) element into map
                    s_i_map[s[j - 1]] = j - 1;
                    iter = s_i_map.find(s[j]);
                    // has duplicate character
                    if (iter != s_i_map.end())
                    {
                        // j_dup is the pos of duplicate character
                        j_dup = iter->second;
                        break;
                    }
                }
                // be careful about the num of map without duplicate char is (j-i)
                result = (result > j - i) ? result : (j - i);
                //i = (j_dup > i) ? (j_dup + 1) : (i + 1);
                // more simple
                i = max(j_dup, i) + 1;
            }
            return result;
        }
};

class Solution3
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            int result = 0;
            return result;
        }
};

// code in discuss
// same as approach #3 in solution page
// note now the interval is (i, j]
class Solution4
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            vector<int> dict(256, -1);
            int result = 0, i = -1;
            for (int j = 0; j != s.length(); j++)
            {
                // is more simple, but hard to understand
//                if (dict[s[j]] > i)
//                    i = dict[s[j]];
                // this one is easy to understand
                if (dict[s[j]] > -1)
                    i = max(dict[s[j]], i);
                dict[s[j]] = j;
                result = max(result, j - i);
            }
            return result;
        }
};

int main(int argc, char** argv)
{
    string str1 = "pwwkew";
    string str2 = "abba";
    string str3 = "aab";
    string str4 = "";
    int result = 0;

    Solution1 s1;
    result = s1.lengthOfLongestSubstring(str1);
    cout << "s1 max len: " << result << ", ";
    result = s1.lengthOfLongestSubstring(str2);
    cout << result << ", ";
    result = s1.lengthOfLongestSubstring(str3);
    cout << result << ", ";
    result = s1.lengthOfLongestSubstring(str4);
    cout << result << endl;

    Solution2 s2;
    result = s2.lengthOfLongestSubstring(str1);
    cout << "s2 max len: " << result << ", ";
    result = s2.lengthOfLongestSubstring(str2);
    cout << result << ", ";
    result = s2.lengthOfLongestSubstring(str3);
    cout << result << ", ";
    result = s2.lengthOfLongestSubstring(str4);
    cout << result << endl;

    Solution3 s3;
    result = s3.lengthOfLongestSubstring(str1);
    cout << "s3 max len: " << result << ", ";
    result = s3.lengthOfLongestSubstring(str2);
    cout << result << ", ";
    result = s3.lengthOfLongestSubstring(str3);
    cout << result << ", ";
    result = s3.lengthOfLongestSubstring(str4);
    cout << result << endl;

    Solution4 s4;
    result = s4.lengthOfLongestSubstring(str1);
    cout << "s4 max len: " << result << ", ";
    result = s4.lengthOfLongestSubstring(str2);
    cout << result << ", ";
    result = s4.lengthOfLongestSubstring(str3);
    cout << result << ", ";
    result = s4.lengthOfLongestSubstring(str4);
    cout << result << endl;
    
    return 0;
}
