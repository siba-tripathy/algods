#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

vector<int> parent(100);

pair<int, int> dfs(int cur, int par, vector<vector<int> >& adj) {
    //cout<<cur<<" ";
    parent[cur]=par;
    pair<int, int> closest_leaf(INT_MAX, INT_MAX);
    for(int x: adj[cur]) {
        if(x != par) {
        	pair<int, int> child_closest = dfs(x, cur, adj);
        	if (child_closest.second < closest_leaf.second) {
        		closest_leaf = child_closest;
        	}
        }
    }
    if( closest_leaf.second == INT_MAX) {
    	closest_leaf.first = cur;
    	closest_leaf.second = 1;
    } else {
    	closest_leaf.second+=1;
    }
    return closest_leaf;
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
    pair<int, int> closest_leaf = dfs(1, 0, adj);
    int node = closest_leaf.first;
    stack<int> path;
    while(node!=0) {
    	path.push(node);
    	node=parent[node];
    }
    while(!path.empty()) {
    	cout<<path.top()<<" ";
    	path.pop();
    }
	return 0;
}