#include<iostream>
#include<vector>

using namespace std;

//https://leetcode.com/problems/paint-house-ii/
//AC

int minCostToPaint(vector<vector<int> >& costs, int houses, int paints) {
	vector<int> dp1(paints);
	vector<int> dp2(paints);

	for(int i = 0; i<paints; i++) {
		dp1[i] = costs[0][i];
	}

	for(int i=1; i<houses; i++) {
		for(int j=0; j<paints; j++) {
			int minPrevious = INT_MAX;
			for(int k=0; k<paints; k++) {
				if (k!= j) {
					minPrevious = min(minPrevious, dp1[k]);
				}
			}
			dp2[j] = costs[i][j] + minPrevious;
		}
		swap(dp2, dp1);
	}
    int ans=INT_MAX;
    for(int i = 0; i<paints; i++) {
        ans=min(ans, dp1[i]);
	}
	return ans;

}

int main() {
	int n,k;
	vector<vector<int> > costs(n, vector<int>(k));
	for(int i = 0; i< n; i++) {
		for(int j=0; j<k; j++) {
			cin>>costs[i][j];
		}
	}
	
	cout<<minCostToPaint(costs, n, k);
}