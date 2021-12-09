#include<iostream>
#include<vector>

using namespace std;

//https://leetcode.com/problems/longest-increasing-subsequence
//AC

int main() {
	int n;
    cin>>n;
	vector<int> arr = vector<int>(n, 0);
	for(int i =0; i<n; i++) {
		cin>>arr[i];
	}

	vector<int> lisSize = vector<int>(n, 1);
	lisSize[0] = 1;
	int maxLis = 1;
	for(int i=1; i<n; i++) {
		for(int j = i-1; j>=0; j--) {
			if (arr[j]<arr[i]) {
				lisSize[i] = max(lisSize[i], 1 + lisSize[j]);
			}
		}
		maxLis = max(maxLis, lisSize[i]);
	}
    cout<<maxLis;

}