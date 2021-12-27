#include<iostream>
#include<vector>

using namespace std;

long long int getXYProfit(int i, int j, vector<long long int>& arr, vector<vector<long long int> >& profits, int turn) {
	if (profits[i][j] != -1) {
		return profits[i][j];
	}
	if (i == j) {
		if (turn == 1) {
			return arr[i];
		} else {
			return -arr[i];
		}
	}
	if (turn == 1) {
		return profits[i][j] = max(arr[i] + getXYProfit(i+1, j, arr, profits, turn ^ 1), arr[j] + getXYProfit(i, j-1, arr,  profits, turn ^ 1));
	} else {
		return profits[i][j] = min(-arr[i] + getXYProfit(i+1, j, arr, profits, turn ^ 1), -arr[j] + getXYProfit(i, j-1, arr, profits, turn ^ 1));
	}
}

int main() {
	int n;
	cin>>n;
	vector<long long int> arr(n);
	for(int i =0; i<n; i++) {
		cin>>arr[i];
	}

	vector<vector<long long int> > profits (n, vector<long long int>(n, -1));
	cout<<getXYProfit(0, n-1, arr, profits, 1);
}