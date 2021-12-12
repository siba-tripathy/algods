#include<iostream>
#include<vector>

using namespace std;

int topDownKnapsack(vector<int>& weights, vector<int>& costs, int i, int W, int n, vector<vector<int> >& dp) {
	if(i==n || W <= 0) {
		return 0;
	}

	if (dp[i][W]!= -1) {
		return dp[i][W];
	}
	//pick
	int p1 = 0;
	if(weights[i] <= W) {
		p1 = costs[i] + topDownKnapsack(weights, costs, i+1, W-weights[i], n, dp);
	}
	//not pick
	int p2 = topDownKnapsack(weights, costs, i+1, W, n, dp);

	int profit = max(p1, p2);

	dp[i][W] = profit;
	return profit;
}


int bottomUpKnapsack(vector<int>& weights, vector<int>& costs, int n, int w) {
	vector<vector<int> > dp(n+1, vector<int>(w+1, 0));
	for(int i = 1; i<=n; i++) {
		for(int j = 1; j<=w; j++) {
			//pick
			int p1 = 0;
			if(weights[i-1] <= j) {
				p1 = costs[i-1]+dp[i-1][j-weights[i-1]];
			}
			//not pick
			int p2 = dp[i-1][j];
			dp[i][j] = max(p1, p2);
		}
	}
	return dp[n][w];
}

//optimize space by using only 2 1D arrays
int bottomUpKnapsackBetter(vector<int>& weights, vector<int>& costs, int n, int w) {
	vector<int> dp1(w+1, 0);
	vector<int> dp2(w+1, 0);
	for(int i = 1; i<=n; i++) {
		for(int j = 1; j<=w; j++) {
			//pick
			int p1 = 0;
			if(weights[i-1] <= j) {
				p1 = costs[i-1]+dp1[j-weights[i-1]];
			}
			//not pick
			int p2 = dp1[j];
			dp2[j] = max(p1, p2);
		}
        swap(dp1, dp2);      
		//dp1=dp2;                     // IMP assignment is not working????
        //dp2.swap(dp1);
		dp2.clear();
	}
	return dp1[w];
}

int main() {
	int n, w;
    cin>>n>>w;
	vector<int> weights(n);
	vector<int> costs(n);
	for(int i = 0; i<n; i++) {
		cin>>weights[i];
	}
	for(int i = 0; i<n; i++) {
		cin>>costs[i];
	}
    vector<vector<int> > dp (105, vector<int>(10000, -1));    //105 -> max count of items, 10000-> max weight sum
    //cout<<topDownKnapsack(weights, costs, 0, w, n, dp);
    cout<<bottomUpKnapsackBetter(weights, costs, n, w);
}