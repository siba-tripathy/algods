#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> prices(n);

	for(int i = 0; i<n; i++) {
		cin>>prices[i];
	}

	if (n==0) {
		return 0;
	}

	vector<int> maxProfits(n, 0);
	for(int i =1; i<n; i++) {
		//not pick for sell
		int p1 = maxProfits[i-1];
		//pick for sell
		int p2=0;
		for(int j=i-1; j>=0; j--) {
			if (j==0 || j == 1) {
				p2 = max(p2, prices[i] - prices[j]);
			} else {
			    p2 = max(p2,maxProfits[j-2] + prices[i] - prices[j]);
            }
		}
		maxProfits[i] = max(p1, p2);
	}

	cout<<maxProfits[n-1];
}