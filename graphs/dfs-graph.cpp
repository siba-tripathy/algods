#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

void dfs_util(int cur, vector<vector<int> >& adj, vector<bool>& visited) {
    cout<<cur;
    visited[cur]=true;
    for(int nb: adj[cur]) {
        if (!visited[nb]) {
            visited[nb]=true;
            dfs_util(nb, adj, visited);
            
        }
    }
}

void dfs(vector<vector<int> >& adj) {
	int n=adj.size()-1; //number of nodes
	vector<bool> visited(n+1, false);
    
	int component_count = 0;
	for(int i=1; i<=n; i++) {
		if(!visited[i]) {
			dfs_util(i, adj, visited);
			component_count++;             //utilise different components
            cout<<endl;
		}
	}
	cout<<"Found "<<component_count<<" componenets"<<endl;
}

bool detect_cycle_dfs_util(int i, int par, vector<bool> &vis, vector<vector<int> >& adj)
{
	cout << i << ' ';
	vis[i] = 1;
	for (int nb : adj[i])
	{
		if (nb == par)
			continue;

		if (vis[nb])
		{
			// from = nb, to = i;
			return 1;
		}

		bool cyc = detect_cycle_dfs_util(nb, i, vis, adj);
		if (cyc)
			return 1;
	}
	return 0;
}

bool detect_cycle_dfs(vector<vector<int> >& adj)
{
    int n = adj.size()-1;
	vector<bool> vis(n + 1);

	for (int i = 1; i <= n; ++i)
		if (!vis[i])
		{
			bool found = detect_cycle_dfs_util(i, -1, vis, adj);

			if (found)
				return 1;
			cout << '\n';
		}

	return 0;
}

int main() {
	int n,m; 
	cin>>n>>m;
	vector<vector<int> > adj(n+1);
	for(int i=0; i<m; i++) {
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(adj);
	return 0;
}

/*
10 10
1 2
1 3
1 5
2 3
3 4
3 5
3 6
4 6
7 8
7 9
*/