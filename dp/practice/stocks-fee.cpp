#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, fee;
	cin>>n>>fee;
	vector<int> prices(n);

	for(int i = 0; i<n; i++) {
		cin>>prices[i];
	}

	if (n==0) {
		return 0;
	}

	vector<int> maxProfits(n, 0);

    //see how minPrevPrice calculation is optimized - one loop is reduced
    int minPrevPrice = prices[0];
	for(int i =1; i<n; i++) {
		//not pick for sell
		int p1 = maxProfits[i-1];
		//pick for sell
		int p2=0;
        minPrevPrice = min(minPrevPrice, prices[i] - maxProfits[i-1]);
        p2 = prices[i] - minPrevPrice;
		maxProfits[i] = max(p1, p2-fee);
	}

	cout<<maxProfits[n-1];
}