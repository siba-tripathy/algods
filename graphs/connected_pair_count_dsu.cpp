#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>


//IMP Pattern - dsu - go on doing unions and finding ans, ans is a special pattern - formula to find no 
//of connected node pairs
//https://codeforces.com/problemset/problem/1213/G

//some test case fails but sample passes

using namespace std;

class union_find {
	public:
		int* pr;
		int* sz;
		int cmp;
		int ans;

	union_find(int n) {
		pr = new int[n+1];
		sz = new int[n+1];

		for(int i=1; i<=n; i++) {
			pr[i] = i, sz[i] = 1;
		}

		cmp = n;
		ans=0;
	}

	int root(int i) {
		if(i == pr[i]) {
			return i;
		}

		return pr[i] = root(pr[i]);
	}

	bool find(int i, int j) {
		return root(i) == root(j);
	}

	int nc2(int n) {
		return n*(n-1)/2;
	}

	void un(int i, int j) {
		int u = root(i);
		int v = root(j);

		if(u==v) {
			return;
		}

		if(sz[u] < sz[v]) {
			swap(u, v);
		}

		ans += sz[u] * sz[v];
		//-(nc2(sz[u]) + nc2(sz[v])) + nc2(sz[u] + sz[v]);
		pr[v] = u;
		sz[u] += sz[v];

		cmp--;
	}
};

class edge {
	public:
		int x;
		int y;
		int weight;

	edge(int a, int b, int c) {
		x=a; y=b; weight = c;
	}
};

bool compare(edge& a, edge& b) {
	return a.weight < b.weight;
}

 
int main() {
	int n,q; 
	cin>>n>>q;
	vector<edge> edges;
	for(int i=0; i<n-1; i++) {
		int x, y, wt;
		cin>>x>>y>>wt;
		
		edges.push_back(edge(x, y, wt));
	}

	sort(edges.begin(), edges.end(), compare);
	
	union_find dsu (n);
	vector<pair<int, int> > queries(q);
	vector<pair<int, int> > ans;

	for(int i=0; i<q; i++) {
		int x;
		cin>>x;
		queries[i] = {x, i};
	}
	sort(queries.begin(), queries.end());
	
	int nextEdgeToMerge = 0;
	for(int i=0; i<q; i++) {

		
		while((nextEdgeToMerge <= (int)edges.size()-1) && edges[nextEdgeToMerge].weight <= queries[i].first) {
			
			dsu.un(edges[nextEdgeToMerge].x, edges[nextEdgeToMerge].y);
			nextEdgeToMerge++;
			
		}
		ans.push_back({queries[i].second, dsu.ans});
	}
	
	sort(ans.begin(), ans.end());
	for(int i=0; i<ans.size(); i++) {
		cout<<ans[i].second<<" ";
	}
	return 0;
}