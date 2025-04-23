#include<bits/stdc++.h>

using namespace std;

// LC : AC : V fEasy : Good : https://leetcode.com/problems/unique-number-of-occurrences/

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        map<int, int> freq;
        for (int i = 0; i < arr.size(); i++)
        {
            freq[arr[i]]++;
        }
        set<int> freq_count_set;
        for (map<int, int>::iterator it = freq.begin(); it != freq.end(); it++)
        {
            if (freq_count_set.find(it->second) == freq_count_set.end())
            {
                freq_count_set.insert(it->second);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};