#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>


using namespace std;

long long int dfs(int cur, int par, vector<vector<int> >& adj, vector<long long int>& value, long long int& x) {
	int sum_of_childrens_contri = 0;
	for(int nb: adj[cur]) {
		if(nb != par) {
			sum_of_childrens_contri += dfs(nb, cur, adj, value, x);
		}
	}
	return max(sum_of_childrens_contri + value[cur], -x);
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
        long long int x;
		cin>>n>>x;
		vector<vector<int> > adj(n+1);
		vector<long long int> value(n+1);
		int root=1;
		for(int i=1; i<=n; i++) {
			cin>>value[i];
		}
		for(int i=1; i<n; i++) {
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		long long int ans = dfs(1, 0, adj, value, x);
		cout<<ans<<endl;
	}
	return 0;
}