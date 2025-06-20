#include<bits/stdc++.h>

using namespace std;

// Great Q. Med (Higly Recommended) :: https://leetcode.com/problems/longest-alternating-subarray/

class Solution
{
public:
    int alternatingSubarray(vector<int> &nums)
    {
        bool needBigger = true; // to check for continuation and next need +1 or -1, can be done by cur %2 as well.
        int ans = 0, cur = 0;
        // driven by actual variation of elements
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] == 1)
            { // if we got a +1
                if (needBigger == true)
                {                               // if we needed a +1 for longer alt sub arrary or start of alt sub array
                    cur == 0 ? cur = 2 : cur++; // handle continuation and start
                }
                else
                {            // if we needed -1 for continuation but got a +1
                    cur = 2; // start of new subarray
                }
                needBigger = false; // what we need to continuation next
            }
            else if (nums[i] - nums[i - 1] == -1)
            { // if we got a -1
                if (needBigger == false)
                { // and we needed a -1 for longer alt sub array
                    cur++;
                }
                else
                {            // if we needed a +1 for longer or start
                    cur = 0; // we end the streak and still look for start
                }
                needBigger = true; // next needed both in case of continuation or start (start needs to be. +1)
            }
            else
            { // any other diff, end the streak and look for +1 next
                cur = 0;
                needBigger = true;
            }
            ans = max(ans, cur);
        }
        if (ans == 0)
        {
            return -1;
        }
        return ans;
    }
};

/**
driven by needBigger or needSmaller

for (int i=1; i<nums.size(); i++) {
            if (needBigger) {
                if (nums[i] == nums[i-1] + 1) {
                    if(cur==0) {
                        cur=2;
                    } else {
                        cur++;
                    }
                    needBigger = false;
                } else {
                    cur=0;
                }
            } else {
                if(nums[i] == nums[i-1]-1) {
                    cur++;
                } else {
                    cur=0;
                    //more logic here to handle potential start of subarray
                }
                needBigger = true;
            }

        }
**/