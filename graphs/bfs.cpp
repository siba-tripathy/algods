#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

//works correctly - checked with pulkit example
vector<int> bfs(vector<vector<int> >& adj) {
	int start = 1;

	queue<int> q;
	q.push(start);
	
    vector<int> par(adj.size());
    vector<int> dist(adj.size());   //dist from start

	while(!q.empty()) {
		int x = q.front();
		cout<<x<<" ";
		q.pop();
		for(int z : adj[x]) {
			if(z != par[x]) {
				q.push(z);
                dist[z] = dist[x]+1;
			    par[z]=x;
            }
		}
	}
    return dist;
}

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
	vector<int> dist = bfs(adj);
    for(int i=1; i<dist.size(); i++) {
        cout<<i<<" "<<dist[i]<<endl;
    }
	return 0;
}