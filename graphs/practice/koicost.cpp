#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//all correct except the calculation part: watch Pulkit's video on youtube
//complex calculation: https://www.youtube.com/watch?v=XaVUt9pC3t0
class union_find
{

public:
	int *pr;         //parent
	int *sz;         //size
	int cmp;
    long long int edgeWeightToAdd;
    long long int totalCost= 0;

	union_find(int n, int totalWeight)
	{
		pr = new int[n + 1];
		sz = new int[n + 1];

		for (int i = 1; i <= n; ++i)
			pr[i] = i, sz[i] = 1;

		cmp = n;
        edgeWeightToAdd = totalWeight;
	}

	int root(int i)
	{
		if (pr[i] == i)
			return i;

		return pr[i] = root(pr[pr[i]]);         //path compression
	}

	int find(int i, int j)
	{
		return (root(i) == root(j));
	}

	int un(int i, int j, int weight)
	{
		int u = root(i);
		int v = root(j);

        
		if (u == v) {
			return 0;
        }

		if (sz[u] < sz[v])
			swap(u, v);

		pr[v] = u;

        
        totalCost = (totalCost + (sz[u]*sz[v]*edgeWeightToAdd) % 1000000000) % 1000000000;
        edgeWeightToAdd-=weight;
		sz[u] += sz[v];
        
		cmp--;
		return 1;
	}
}; //default indexing is 1-based

class edge {

    public: 

    int x;
    int y;
    int weight;

    edge(int a, int b, int c) {
        x=a, y=b, weight = c;
    }
};

bool compareEdge(edge a, edge b) {
    return a.weight > b.weight;
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<edge> arr(m, edge(0,0,0));

    int edge_sum = 0;
    for(int i=0; i<m; i++) {
        int x, y, weight;
        cin>>x>>y>>weight;
        arr[i] = edge(x, y, weight);
        edge_sum += weight;
    }

    sort(arr.begin(), arr.end(), compareEdge);
    union_find dsu(n, edge_sum);

    for(int i=0; i<m; i++) {
        edge e = arr[i];
        dsu.un(e.x, e.y, e.weight);
        //cout<<dsu.totalCost<<endl;
    }
    long long int ans = dsu.totalCost;
    //(dsu.edgeWeightToAdd*n*(n-1)) % 1000000000;
    //ans = (dsu.totalCost + ans) % 1000000000;
    cout<<ans;
}