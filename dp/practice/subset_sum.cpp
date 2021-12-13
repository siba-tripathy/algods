#include<iostream>
#include<vector>

using namespace std;

//can you achieve a sum of x by unsing some elements of array arr (any subset)


bool isPossible(vector<int>& sizes, int n, int sum) {
	vector<int> dp1(sum+1, 0);
	vector<int> dp2(sum+1, 0);
    dp1[0] = 1;
	for(int i=0; i<n; i++) {
	for(int j=0; j<sum+1; j++) {
		//pick
		int p1=0;
		if(dp1[j-sizes[i]] == 1) {
			p1 = 1;
		}
		//not pick
		int p2 = dp1[j];
		dp2[j] = p1 | p2;
	}
	swap(dp2, dp1);
	dp2.clear();
	}
	return 1 == dp1[sum];
}

int main() {
	int n, sum;
	cin>>n>>sum;
	vector<int> sizes(n, 0);
	for(int i = 0; i<n; i++) {
		cin>>sizes[i];
	}

	cout<<isPossible(sizes, n, sum);
}