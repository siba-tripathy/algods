#include<iostream>
#include<vector>

using namespace std;

//can you achieve two partitions of array st there sum is equal
//Solution: similiar to subset sum , target is total sum/2;


bool isPossible(vector<int>& sizes, int n) {

    int sum=0;
    for(int i=0; i<n; i++) {
        sum+= sizes[i];
    }

    if(sum%2 == 1) {
        return false;
    }
    int target = sum/2;
    
	vector<int> dp1(target+1, 0);
	vector<int> dp2(target+1, 0);
    dp1[0] = 1;
	for(int i=0; i<n; i++) {
	for(int j=0; j<target+1; j++) {
		//pick
		int p1=0;
		if(sizes[i] <= j && dp1[j-sizes[i]] == 1) {
			p1 = 1;
		}
		//not pick
		int p2 = dp1[j];
		dp2[j] = p1 | p2;
	}
	swap(dp2, dp1);
	dp2.clear();
    // for(int i = 0; i<target+1; i++) {
    //     cout<<dp1[i]<<" ";
    // }
    // cout<<endl;
	}
    // for(int i = 0; i<target+1; i++) {
    //     cout<<dp1[i]<<" ";
    // }
    //cout<<endl;
	return 1 == dp1[target];
}

int main() {
	int n;
	cin>>n;
	vector<int> sizes(n, 0);
	for(int i = 0; i<n; i++) {
		cin>>sizes[i];
	}

	cout<<isPossible(sizes, n);
}