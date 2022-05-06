#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>

using namespace std;


//https://codeforces.com/contest/510/problem/C?f0a28=1
//AC
//Med - Good question
//hint at end

int main() {
	int m;
	cin>>m;
	vector<string> input(m);
	for(int i=0; i<m; i++) {
		cin>>input[i];
	}
	vector<vector<int> > adj(26);
	vector<int> in_degree(26, 0);
	for(int i=0; i<m-1; i++) {

		string x = input[i];
		string y = input[i+1];
		int x_i =0 , y_i=0;
		while(x_i <x.length() && y_i < y.length() && x[x_i] == y[y_i]) {
			x_i++;
			y_i++;
		}
		if (x_i == x.length()) {
		} else if (y_i == y.length()) {
			cout<<"Impossible";
			return 0;
		} else {
			adj[x[x_i] - 'a'].push_back(y[y_i] - 'a');
			in_degree[y[y_i] - 'a']++;
		}
	}

    //topo sort by BFS as its easier for a multi component case / where we dont know the source
	//cycle detection is also pretty straight forward
	queue<int> zero_indegrees;
	for(int i=0; i<26; i++) {
		if (in_degree[i] == 0) {
			zero_indegrees.push(i);
		}
	}
	string ans;
	while(!zero_indegrees.empty()) {

		int front = zero_indegrees.front();
		zero_indegrees.pop();
		ans+=(char)('a' + front);

		for(int i=0; i<adj[front].size(); i++) {
			int nb = adj[front][i];
			in_degree[nb]--;
			if(in_degree[nb] == 0) {                   //dont need any checks as indegree will only once go to 0
				zero_indegrees.push(nb);
			}
		}
	}
    bool possible = true;
    for(int i=0; i<26; i++) {
        if (in_degree[i] > 0) {
            possible = false;
        }
    }
    if (!possible) {
        cout<<"Impossible";
    } else {
	    cout<<ans;
    }
	

	return 0;
}

























//topo sort