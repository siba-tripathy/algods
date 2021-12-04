#include<iostream>
#include<vector>

using namespace std;

//https://leetcode.com/problems/2-keys-keyboard/
//AC


int minSteps(int n) {
    vector<int> ans = vector<int>(n, 0);
    ans[0] = 0;
    if (n == 1) {
        return 0;
    }
    for(int i = 2; i<=n; i++) {
        ans[i-1] = i;
        for(int j = i-1; j>=1; j--) {
            if (i%j == 0) {
                ans[i-1] = ans[j-1] + i/j;
                break;
            }
        }
    }
    return ans[n-1];
}

int main() {
    int n;
    cin>>n;
    cout<<minSteps(n);
}