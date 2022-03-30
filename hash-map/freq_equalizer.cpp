#include<iostream>
#include<unordered_map>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

//https://codeforces.com/contest/1490/problem/F
//not ac but time complexity is same as pulkit's : https://codeforces.com/contest/1490/submission/107629110
//TLE at test case 12

int main() {
	int t;
    cin>>t;
	while(t--) {
		int n;
		cin>>n;
		unordered_map<int, int> freq;
		for(int i=0; i<n; i++) {
			int x;
            cin>>x;
			freq[x]++;
		}
		map<int, int> occ_counts;
		for(auto& e: freq) {
			occ_counts[e.second]++;
		}
		vector<pair<int, int> > occ;
		for(auto& e: occ_counts) {
			pair<int, int> p(e.first, e.second);
			occ.push_back(p);
		}
		//sort(occ.begin(), occ.end());
		int ans = INT_MAX;
		vector<int> prev_del_ops(occ.size());
		vector<int> next_del_ops(occ.size());

		for(int i=1; i<occ.size(); i++) {
			prev_del_ops[i]=prev_del_ops[i-1]+occ[i-1].first*occ[i-1].second;
		}

		for(int i=occ.size()-2; i>=0; i--) {
			next_del_ops[i]=next_del_ops[i+1]+(occ[i+1].first - occ[i].first)*occ[i+1].second;
			occ[i].first+=occ[i+1].first;
            ans = min(ans, prev_del_ops[i]+next_del_ops[i]);
		}
        ans=min(ans, prev_del_ops[occ.size()-1]);
		cout<<ans<<endl;
	}
}