#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

//https://codeforces.com/problemset/problem/982/C
//AC - nice question
//hint at end

vector<int> parent(100);

int dfs(int cur, int par, vector<vector<int> >& adj, int& ans) {  //returns size of subtree rooted at cur and updates ans if its size is even
	int net_size_of_tree_at_cur = 1;
	for(int nb: adj[cur]) {
		if(nb != par) {
			int size = dfs(nb, cur, adj, ans);
			if(size%2==0) {
				ans++;
			} else {
				net_size_of_tree_at_cur+=size;
			}
		}
	}
	return net_size_of_tree_at_cur;
}

int main() {
	int n;
	cin>>n;
	vector<vector<int> > adj(n+1);
	int root;
	for(int i=1; i<n; i++) {
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	if (n%2==1) {
		cout<<-1;
		return 0;
	}
	int ans = 0;
	dfs(1, 0, adj, ans);
	cout<<ans;
	return 0;
}



















//hint - even minus even is always even
//odd minus even is odd