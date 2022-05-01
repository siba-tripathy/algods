#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>


using namespace std;

//https://codeforces.com/problemset/problem/1217/D
//AC
//Good Question


vector<pair<int, int> > directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs_util(int cur, int par, vector<vector<pair<int, int> > >& adj, vector<int>& col, vector<int>& vis) {
	
	vis[cur] = 1;
	for(pair<int, int> e : adj[cur]) {                 //no parent check - to consider edges to parent as back edges - anyways we do recursive dfs only on tree edges
			if (vis[e.first] == 0) {                      //tree edge
				col[e.second]=1;
				dfs_util(e.first, cur, adj, col, vis);
			} else if(vis[e.first] == 1) {                //back edge
				col[e.second] = 2;
			} else {                                      //cross edge or forward edge - not creating cycles
                col[e.second] = 1;
            }
	}

	vis[cur] = 2;
	return;
	
}

void dfs(vector<vector<pair<int, int> > >& adj, vector<int>& col) {
	
	int n=adj.size()-1;
	vector<int> vis(n+1, 0);
	for(int i=1; i<=n; i++) {
		if(vis[i] == 0) {
			dfs_util(i, 0, adj, col, vis);
		}
	}
	return;
}


int main() {
	int n, m;
	cin>>n>>m;
	vector<vector<pair<int, int> > > adj(n+1);
	for(int i=0; i<m; i++) {
		int x, y;
		cin>>x>>y;
		adj[x].push_back({y, i});
	}
	vector<int> col(m);
	dfs(adj, col);

    cout<<*max_element(col.begin(), col.end())<<endl;
	for(int i:col) {
		cout<<i<<" ";
	}

	return 0;
}