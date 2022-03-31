#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>


using namespace std;

vector<int> parent(100);

//https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/
//failing a test case - couldnot debug
//logic works on examples i tested - logic as per pulkit

pair<int, int> dfs(int cur, int par, vector<vector<int> >& adj) {
	int max_depth1=0, max_depth2 = 0;
	int max_diameter = 0;
	int max_subtree_diameter = 0;
    bool has_child = false;
	for(int nb: adj[cur]) {
		if(nb != par) {
            has_child = true;
			pair<int, int> diameter_and_depth = dfs(nb, cur, adj);
			
			//not including the cur (root node)
			max_subtree_diameter = max(max_subtree_diameter, diameter_and_depth.first);
			
			//including the root node - need max1 and max2 depths of all subtrees
            //children will contribute 1 + their max depth to the max depth of the parent node
			if (diameter_and_depth.second + 1> max_depth1) {
				max_depth2 = max_depth1;
				max_depth1 = diameter_and_depth.second + 1;
			} else if (diameter_and_depth.second > max_depth2) {
				max_depth2 = diameter_and_depth.second + 1 ;
			}
		}
	}
    if (!has_child) {
        cout<<cur<<" "<<0<<" "<<0<<endl;
        return {0, 0};
    }
    int max_diameter_including_root = 0;
    if (max_depth2 > 0) {
        max_diameter_including_root = max_depth1+max_depth2;
    } else if (max_depth1 > 0) {
        max_diameter_including_root = max_depth1;
    }
	max_diameter = max(max_diameter_including_root, max_subtree_diameter);
    cout<<cur<<" "<<max_diameter<<" "<<max_depth1<<endl;
	return {max_diameter, max_depth1};
}

int main() {
	int n;
	cin>>n;
	vector<vector<int> > adj(n+1);
	int root;
	for(int i=0; i<n; i++) {
		int x;
		cin>>x;
        if(x==-1) {
            root = i;
        } else {
		    adj[x].push_back(i);
		    adj[i].push_back(x);
        }
	}

	pair<int, int> ans = dfs(root, -1, adj);
	cout<<max(ans.first, ans.second);
	return 0;
}