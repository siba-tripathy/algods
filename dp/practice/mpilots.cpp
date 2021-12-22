#include<iostream>
#include<vector>

using namespace std;

//NICE Question
//https://www.spoj.com/problems/MPILOT/
//AC

int getMinCost(vector<int>& a, vector<int>& c, vector<vector<int> >& minCostWithCaptains, int n, int i, int captains) {
	if(i==n) {
		return 0;
	}

    if (minCostWithCaptains[i][captains] != -1) {
        return minCostWithCaptains[i][captains];
    }

    if (i-captains == n/2) {
        return minCostWithCaptains[i][captains] = getMinCost(a, c, minCostWithCaptains, n, i+1, captains+1) + c[i];
    }
	if (captains < (i+1)/2) { //as there can be only i+1/2 captains at a point where you are considering i+1 pilots
		return minCostWithCaptains[i][captains] = min(
            getMinCost(a, c, minCostWithCaptains, n, i+1, captains+1) + c[i],
            getMinCost(a, c, minCostWithCaptains, n, i+1, captains) + a[i]
        );
	} else {
		return minCostWithCaptains[i][captains] = getMinCost(a, c, minCostWithCaptains, n, i+1, captains) + a[i];
	}
}

int main() {
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> c(n);

	for(int i = 0; i<n; i++) {
		cin>>c[i]>>a[i];
	}

    vector<vector<int> > minCostWithCaptains(10001, vector<int>(5001, -1));

	//first person will always be assistant
	cout<< a[0]+getMinCost(a, c, minCostWithCaptains, n, 1, 0);
}