#include<bits/stdc++.h>
using namespace std;

// LC: Easy(Faster approach is Good Q) : AC : https://leetcode.com/problems/count-elements-with-maximum-frequency/

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        map<int, int> freq;
        int max_freq = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (freq.find(nums[i]) == freq.end())
            {
                freq[nums[i]] = 1;
            }
            else
            {
                freq[nums[i]]++;
            }

            if (freq[nums[i]] > max_freq)
            {
                max_freq = freq[nums[i]];
            }
        }

        int ans = 0;
        for (map<int, int>::iterator it = freq.begin(); it != freq.end(); it++)
        {
            if (it->second == max_freq)
            {
                ans += it->second;
            }
        }
        return ans;
    }

    int fasterMaxFrequencyElements(vector<int> &nums) //faster one loop approach
    {
        map<int, int> freq;
        int max_freq = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (freq.find(nums[i]) == freq.end())
            {
                freq[nums[i]] = 1;
            }
            else
            {
                freq[nums[i]]++;
            }

            if (freq[nums[i]] > max_freq)
            {
                ans = freq[nums[i]];
                max_freq = freq[nums[i]];
            }
            else if (freq[nums[i]] == max_freq)
            {
                ans += freq[nums[i]];
            }
        }
    }
    };