#include<iostream>
#include<vector>

using namespace std;

//good question - hard
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
//see explanantion: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/135704/Detail-explanation-of-DP-solution

int main() {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0 ; i<n; i++){
		cin>>arr[i];
	}

	int transactions =2;
	vector<vector<int> > profits(transactions+1, vector<int>(n, 0));
	
	for(int k=1; k<=transactions; k++) {
        int min = arr[0];
		for(int i=1; i<n; i++) {
			//not pick - not selling any on ith day's price
			int p1 = profits[k][i-1];
			//pick - sell some here
			int p2=0;
            min = std::min(min, arr[i] - profits[k-1][i-1]);
			p2 = max(p2, arr[i] - min);
			profits[k][i] = max(p1, p2);
		}
	}
	cout<<profits[transactions][n-1];

}