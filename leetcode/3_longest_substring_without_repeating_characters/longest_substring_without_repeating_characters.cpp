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
            for (i = 0; i < len; i++)
            {
                unordered_map<char, int> s_i_map;
                unordered_map<char, int>::iterator iter;
                for (j = i + 1; j < len; j++)
                {
                    iter = s_i_map.find(s[j]);
                    // has duplicate character
                    if (iter != s_i_map.end())
                    {
                        result = (result > j - i - 1) ? result : (j - i - 1);
                        break;
                    }
                    s_i_map[s[j]] = j;
                }
            }
            return result;
        }
};

// sliding window
class Solution2
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            int result = 0;
            int len = s.length();
            int i = 0;
            int j = 0;
            unordered_map<char, int> s_i_map;
            unordered_map<char, int>::iterator iter;
            while (i < len && j < len)
            {
                iter = s_i_map.find(s[j]);
                if (iter == s_i_map.end())
                {
                    s_i_map[s[j]] = j;
                    result = (result > j - i) ? result : (j - i);
                    j++;
                }
                else
                {
                    s_i_map.erase(iter);
                    i++;
                }
            }
            return result;
        }
};

// I optimize solution2 by skip i to duplicate index + 1
class Solution3
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            int result = 0;
            int len = s.length();
            int i = 0;
            int j = 0;
            unordered_map<char, int> s_i_map;
            unordered_map<char, int>::iterator iter;
            while (i < len && j < len)
            {
                iter = s_i_map.find(s[j]);
                if (iter == s_i_map.end())
                {
                    s_i_map[s[j]] = j;
                    result = (result > j - i) ? result : (j - i);
                    j++;
                }
                else
                {
                    i = distance(s_i_map.begin(), iter) + 1;
                    s_i_map.erase(iter);
                }
            }
            return result;
        }
};

// code in discuss
class Solution4
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            vector<int> dict(256, -1);
            int result = 0, start = -1;
            for (int i = 0; i != s.length(); i++)
            {
                if (dict[s[i]] > start)
                    start = dict[s[i]];
                dict[s[i]] = i;
                result = max(result, i - start);
            }
            return result;
        }
};

int main(int argc, char** argv)
{
    string str1 = "pwwkew";
    string str2 = "abcabcbb";
    string str3 = "aab";
    int result = 0;

//    Solution1 s1;
//    result = s1.lengthOfLongestSubstring(str1);
//    cout << "s1 max len: " << result << ", ";
//    result = s1.lengthOfLongestSubstring(str2);
//    cout << result << ", ";
//    result = s1.lengthOfLongestSubstring(str3);
//    cout << result << endl;
//
//    Solution2 s2;
//    result = s2.lengthOfLongestSubstring(str1);
//    cout << "s2 max len: " << result << ", ";
//    result = s2.lengthOfLongestSubstring(str2);
//    cout << result << ", ";
//    result = s2.lengthOfLongestSubstring(str3);
//    cout << result << endl;
//
//    Solution3 s3;
//    result = s3.lengthOfLongestSubstring(str1);
//    cout << "s3 max len: " << result << ", ";
//    result = s3.lengthOfLongestSubstring(str2);
//    cout << result << ", ";
//    result = s3.lengthOfLongestSubstring(str3);
//    cout << result << endl;

    Solution4 s4;
//    result = s4.lengthOfLongestSubstring(str1);
//    cout << "s4 max len: " << result << ", ";
//    result = s4.lengthOfLongestSubstring(str2);
//    cout << result << ", ";
    result = s4.lengthOfLongestSubstring(str3);
    cout << result << endl;
    
    return 0;
}
