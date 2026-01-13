#include<bits/stdc++.h>

using namespace std;

// Easy-Med. Pattern. IMP Problem.
// LC: https://leetcode.com/problems/house-robber

//bottom-up approach
int maxAmountRobbed(vector<int> &arr) {
    vector<int> maxAmountRobbable = vector<int>(arr.size(), 0);

    //max robbable till first house is money in first house
    maxAmountRobbable[0] = arr[0];
    //max robbable till second house is max of first and second house
    if (arr.size()>1) {
        maxAmountRobbable[1] = max(arr[0], arr[1]);
    }
    if(arr.size() > 2) {
        for(int i = 2; i<arr.size(); i++) {
            //pick or not pick ith house
            maxAmountRobbable[i] = max(maxAmountRobbable[i-1], arr[i] + maxAmountRobbable[i-2]);
        }
    }
    return maxAmountRobbable[arr.size()-1];
}

//top-down DP approach: naive recusrsive is optimized with memoization
int maxAmountRobbed_RecusrsiveMemoized(vector<int> &arr, int i, vector<int>& ans) {
    if (i == 0) {
        ans[0] = arr[0];
        return arr[0];
    }
    if (i==1) {
        ans[1] = max(arr[1], arr[0]);
        return max(arr[1], arr[0]);
    }

    if (ans[i] == -1) {
        int includingCurrent = arr[i] + maxAmountRobbed_RecusrsiveMemoized(arr, i-2, ans);
        int excludingCurrent = maxAmountRobbed_RecusrsiveMemoized(arr, i-1, ans);
        return max(includingCurrent, excludingCurrent);
    } else {
        return ans[i];
    }
    
}

//naive recursive
int maxAmountRobbed_Recusrsive(vector<int> &arr, int i) {
    if (i == 0) {
        return arr[0];
    }
    if (i==1) {
        return max(arr[1], arr[0]);
    }

    int includingCurrent = arr[i] + maxAmountRobbed_Recusrsive(arr, i-2);
    int excludingCurrent = maxAmountRobbed_Recusrsive(arr, i-1);
    return max(includingCurrent, excludingCurrent);
}

int main() {
    int n;
    cin>>n;
    vector<int> moneyInHouses = vector<int>(n, 0);
    for(int i=0; i<n; i++) {
        cin>>moneyInHouses[i];
    }
    vector<int> ans = vector<int>(n, -1);
    //bottom - up approach
    cout<<maxAmountRobbed(moneyInHouses);

    //top-down : recursion + memoization
    //cout<<maxAmountRobbed_RecusrsiveMemoized(moneyInHouses, n-1, ans);
}
