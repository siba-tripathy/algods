#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;

//https://leetcode.com/problems/arithmetic-slices-ii-subsequence
//AC

int main() {
	int n;
	cin>>n;
	vector<int> arr(n, 0);
	for(int i =0; i<n; i++) {
		cin>>arr[i];
	}
	vector<unordered_map<int, int> > count(n);
	long long int diff = arr[1] - arr[0];
	long long int ans = 0;
	count[1][diff] = 1;
	for(int i = 2; i<n; i++) {
		for(int j = i-1; j>=0; j--) {
			long long int diff = (long long int)arr[i] - arr[j];
			if(count[j].count(diff)) {
				count[i][diff] += (count[j][diff]+1);
				ans+= count[j][diff];
			} else {
				count[i][diff] += 1;
			}
		}
	}
	cout<<ans;
}