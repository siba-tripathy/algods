#include <bits/stdc++.h>
using namespace std;

// LC: https://leetcode.com/problems/jump-game-ii/
// Very Good. Greedy Solve very imp and tricky.

class Solution {
   public:
    int jump(vector<int>& nums) {
        return min_count_loop_greedy(nums);
        // return min_count(0, nums);
    }

    // loop based solution (O(n^2)) - AC
    int min_count_loop(vector<int>& nums) {
        vector<int> min_steps(nums.size(), INT_MAX);  // min steps to reach at index i
        min_steps[0] = 0;
        for (int i = 0; i <= nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size() && j <= i + nums[i]; j++) {
                min_steps[j] = min(min_steps[j], 1 + min_steps[i]);
            }
        }
        return min_steps[nums.size() - 1];
    }

    // greedy solution  O(n) - Best
    int min_count_loop_greedy(vector<int>& nums) {
        int jumps = 0;
        int cur_end = 0;        // farthest we have come with current jump
        int next_farthest = 0;  // fahtest we can go in the next 1 jump
        for (int i = 0; i < nums.size() - 1; i++) {
            next_farthest = max(next_farthest, i + nums[i]);

            if (i == cur_end) {
                jumps++;
                cur_end = next_farthest;
            }
        }
        return jumps;
    }

    // recursive solution (O(2^n)) - TLE
    int min_count(int cur_pos, vector<int>& nums) {  // gives min jumps needed to go from cur_pos to end
        if (cur_pos == nums.size() - 1) {
            return 0;
        }
        if (nums[cur_pos] == 0) {
            return INT_MAX;
        }
        int min_jump = INT_MAX;
        for (int i = cur_pos + 1; i < nums.size() && i <= cur_pos + nums[cur_pos]; i++) {
            min_jump = min(min_jump, min_count(i, nums));
        }
        if (min_jump == INT_MAX) {
            return INT_MAX;
        }
        // cout<<"Min jumps needed from index "<<cur_pos<<", to reach end is"<<min_jump+1<<endl;
        return min_jump + 1;
    }
};