#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;


//using stack works correctly - but long
vector<int> dfs(vector<vector<int> >& adj) {
	int start = 1;

	stack<int> s;
	s.push(start);
	
    vector<int> par(adj.size());
    vector<int> dist(adj.size());   //dist from start

	while(!s.empty()) {
		int x = s.top();
		cout<<x<<" ";
		s.pop();
		for(int z : adj[x]) {
			if(z != par[x]) {
				s.push(z);
                dist[z] = dist[x]+1;
			    par[z]=x;
            }
		}
	}
    return dist;
}

//short simple dfs
void dfs(int cur, int par, vector<vector<int> >& adj) {
    cout<<cur<<" ";
    for(int x: adj[cur]) {
        if(x != par)                     //because its a tree, all nodes in adjacency list are children, except tht one parent and
        dfs(x, cur, adj);                // as no cycles, no repeatation of grandparents in the adjcency list. thus this check is sufficient.
    }
}

/*
//short simple dfs - use this template
void dfs(int cur, int par, vector<vector<int> >& adj) {
    cout<<cur<<" ";
    for(int x: adj[cur]) {
        if(x != par)
        dfs(x, cur, adj);
    }
}
*/

int main() {
	int nodes;
	int edges;
	cin>>nodes>>edges;
	vector<vector<int> > adj(nodes+1);
	for(int i=0; i<edges; i++) {
		int x;
		int y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
    dfs(1, 0, adj);
	//vector<int> dist = dfs(adj);
    // for(int i=1; i<dist.size(); i++) {
    //     cout<<i<<" "<<dist[i]<<endl;
    // }
	return 0;
}

/*sample input
8
7
1 2
1 3 
1 4
2 7
2 8
3 5
5 6
*/
