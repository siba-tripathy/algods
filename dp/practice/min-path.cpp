#include<iostream>
#include<vector>

using namespace std;

//easy
//https://leetcode.com/problems/minimum-path-sum
//AC

int main() {
	int n, m;
	cin>>n>>m;
	vector<vector<int> > arr(n, vector<int>(m));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>arr[i][j];
		}
	}

	vector<vector<int> > minCost(n, vector<int>(m, INT_MAX));

	minCost[0][0] = arr[0][0];
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(i>0) {
				minCost[i][j] = min(minCost[i][j], arr[i][j] + minCost[i-1][j]);
			}
			if(j>0) {
				minCost[i][j] = min(minCost[i][j], arr[i][j] + minCost[i][j-1]);
			}
		}
	}

	cout<<minCost[n-1][m-1];
}