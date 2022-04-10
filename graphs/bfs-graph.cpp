#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;


void bfs_util(int start, vector<vector<int> >& adj, vector<bool>& visited) {
	
	queue<int> q;
	q.push(start);
    visited[start]=true;
    vector<int> d(n+1, -1);
    d[src] = 0;                     //to calculate distance from start

	while(!q.empty()) {

		int cur = q.front();   
        q.pop();             //deal with / utilise the front     // can also help calculate number of nodes in the component
		cout<<cur<<" ";

		for(int nb : adj[cur]) {
			if(!visited[nb]) {				//enque the not visited neighbours for later utilisation
				q.push(nb);
				visited[nb]=true;
                d[nb] = d[cur] + 1;           
			}
		}
	}
}

void bfs(vector<vector<int> >& adj) {
	int n=adj.size()-1; //number of nodes
	vector<bool> visited(n+1, false);
    
	int component_count = 0;
	for(int i=1; i<=n; i++) {
		if(!visited[i]) {
			bfs_util(i, adj, visited);
			component_count++;             //utilise different components
            cout<<endl;
		}
	}
	cout<<"Found "<<component_count<<" componenets"<<endl;
}

int main() {
	int n,m; 
	cin>>n>>m;
	vector<vector<int>> adj(n+1);
	for(int i=0; i<m; i++) {
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bfs(adj);
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