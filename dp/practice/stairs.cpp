#include<iostream>
#include<vector>

using namespace std;
//v. easy
//https://leetcode.com/problems/min-cost-climbing-stairs
//AC

int main() {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}


	vector<int> minCost(n);
	minCost[0] = 0;
	minCost[1] = 0;

	for(int i =2; i<n; i++) {
		minCost[i] = min(minCost[i-1] + arr[i-1], minCost[i-2] + arr[i-2]);
	}

	cout<<min(arr[n-1] + minCost[n-1], arr[n-2] + minCost[n-2]);
}