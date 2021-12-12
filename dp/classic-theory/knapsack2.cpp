#include<iostream>
#include<vector>
#include<limits>

using namespace std;


int bottomUpKnapsack(vector<int>& weights, vector<int>& value, int n, int w) {
	vector<int> dp1(20, INT_MAX);  // +1 because it helps create the base case of zeros and makes the recurrence impl easier
	vector<int> dp2(20, INT_MAX);
    dp1[0]=0;
	for(int i = 0; i<n; i++) {
		for(int j=0; j<20; j++) {
			//pick
			int p1 = INT_MAX;
			if (value[i] <= j) {
				if (dp1[j-value[i]] != INT_MAX) {
					p1 = dp1[j-value[i]] + weights[i];
				}
			}
			int p2 = dp1[j];
			dp2[j] = min(p1, p2);
		}
		swap(dp2, dp1);
		dp2.clear();
	}

	int ans;
	for(int j=0; j<20; j++) {
		if(dp1[j]<=w) {
			ans=j;
		}
	}
	
    cout<<endl;
	return ans;
}


int main() {
	int n, w;
	cin>>n>>w;
	vector<int> weights(n, 0);
	vector<int> value(n, 0);
	for(int i = 0; i<n; i++) {
		cin>>weights[i];
	}
	for(int i = 0; i<n; i++) {
		cin>>value[i];
	}

	cout<<bottomUpKnapsack(weights, value, n, w);

}