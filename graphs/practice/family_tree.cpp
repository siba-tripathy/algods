#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

//https://www.codechef.com/submit/FAMTREE
//AC


vector<int> parent(100005);

pair<long long int, long long  int> dfs(int cur, int par, vector<vector<int> >& adj, vector<long long int>& wealth, long long int& ans) {
	long long int max_child =wealth[cur], min_child = wealth[cur];
    //while calculating ans(max diff), we need to check each individual subtree's max and min and calculate what cur can give us for a particular subtree
    //take care that while calculating ans(max diff in the above statement, we dont mix one subtree's min and another's max)
    //but we want to return the max and min of mixture of all subtrees of the node and the node included, so that they can be used in parent's calculation together - 
    //as for parent they belong to same subtree.
	for(int nb: adj[cur]) {
		if(nb != par) {
			pair<long long int, long long int> max_min = dfs(nb, cur, adj, wealth, ans);
            max_child = max(max_min.first, max_child);
	        min_child = min(max_min.second, min_child);
            ans = max({ans, max_child - wealth[cur], wealth[cur] - min_child});
		}
	}
    //cout<<cur<<" "<<max_child<<" "<<min_child<<endl;
    return {max_child, min_child};
	
}


int main() {
	int n;
	cin>>n;
	vector<long long int> wealth(n+1);
	vector<int> parent(n+1);
	vector<vector<int> > adj(n+1);
	for(int i=1; i<=n; i++) {
		cin>>wealth[i];
	}
	int root;
    //this is how you get root and adjacency list from parent array - to operate with dfs
	for(int i=1; i<=n; i++) {
		cin>>parent[i];
		if(parent[i] == -1) {
			root = i;
		} else {
			adj[i].push_back(parent[i]);
			adj[parent[i]].push_back(i);
		}
	}
    long long int ans=0;
	dfs(root, 0, adj, wealth, ans);
	cout<<ans;
	return 0;
}