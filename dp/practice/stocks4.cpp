#include<iostream>
#include<vector>

//Nice Question -  hard
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
//AC


using namespace std;

int main() {
	int n, transactions;
	cin>>n>>transactions;
	vector<int> arr(n);
	for(int i = 0 ; i<n; i++){
		cin>>arr[i];
	}

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