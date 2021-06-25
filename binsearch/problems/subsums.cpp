#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//https://www.spoj.com/problems/SUBSUMS/

vector<long long int> getSubsetSums(vector<int> arr) {
    int n = arr.size();

    vector<long long int> subsetSums;
    for(long long int mask = 0; mask<(1<<n); mask++) {
        long long int currentSubsetSum = 0;
        for(int i = 0; i<n; i++) {
            if (mask & (1<<i)) {
                currentSubsetSum+= arr[i];
            }
        }
        subsetSums.push_back(currentSubsetSum);
    }
    return subsetSums;
}

int main() {
    int n, a, b;
    cin>>n>>a>>b;
    vector<int> nums(n, 0);

    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    vector<int> left(nums.begin(), nums.begin()+ n/2);
    vector<int> right(nums.begin()+n/2, nums.end());

    vector<long long int> left_sums = getSubsetSums(left);
    vector<long long int> right_sums = getSubsetSums(right);

    sort(right_sums.begin(), right_sums.end());

    long long int ans = 0;

    for(long long int i=0; i<left_sums.size(); i++) {
        auto left_it = lower_bound(right_sums.begin(), right_sums.end(), a-left_sums[i]);
        auto right_it = upper_bound(right_sums.begin(), right_sums.end(), b-left_sums[i]);

        ans += right_it - left_it;
    }

    cout<<ans<<endl;
}