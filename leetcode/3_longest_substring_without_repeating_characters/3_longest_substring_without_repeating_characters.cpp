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
            int i = 0;
            int j = 0;
            unordered_map<char, int> s_i_map;
            unordered_map<char, int>::iterator iter;
            for (j = 0; j < s.length(); j++)
            {
                result = max(result, j - i);
                iter = s_i_map.find(s[j]);
                if (iter != s_i_map.end() && iter->second >= i)
                    i = iter->second + 1;
                s_i_map[s[j]] = j;
            }
            result = max(result, j - i);
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

template <class T> void cal_out (T & solution)
{
    vector <string> str_list;
    str_list.push_back("pwwkew");
    str_list.push_back("abba");
    str_list.push_back("aab");
    str_list.push_back("abcabcbb");
    str_list.push_back("");
    int result = 0;
    int i = 0;
    cout << "result: ";
    for (i = 0; i < str_list.size() - 1; i++)
    {
        string &str = str_list[i];
        result = solution.lengthOfLongestSubstring(str);
        cout << str << ":" << result << ", ";
    }
    string &str = str_list[i];
    result = solution.lengthOfLongestSubstring(str);
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
    
    return 0;
}
