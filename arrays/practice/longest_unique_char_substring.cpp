#include<bits/stdc++.h>

using namespace std;

// Easy : V.Good : GFG : https://www.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1

class Solution
{
public:
    int longestUniqueSubstring(string &s)
    {
        int left = 0;
        unordered_map<char, int> last_occur;
        last_occur[s[0]] = 0;
        int max_len = 1;

        for (int i = 1; i < s.size(); i++)
        {
            if (last_occur.find(s[i]) == last_occur.end())
            {
                max_len = max(max_len, i - left + 1);
            }
            else
            {
                left = max(left, last_occur[s[i]] + 1);
                max_len = max(max_len, i - left + 1);
            }
            last_occur[s[i]] = i;
        }
        return max_len;
    }
};