#include<iostream>
#include<vector>

using namespace std;


int calcPaths(vector<vector<int> >& maze, int i, int j) {
	if (i==maze.size()-1 && j == maze.size()-1) {
		return 1;
	} else {
		int possibilities = 0;
		maze[i][j] = 2; // means visited
		if (i-1 >0 && maze[i-1][j] == 0) {
			possibilities+= calcPaths(maze, i-1, j);
		}
		if (j-1 >0 && maze[i][j-1] == 0) {
			possibilities+= calcPaths(maze, i, j-1);
		}
		if (i+1 <maze.size() && maze[i+1][j] == 0) {
			possibilities+= calcPaths(maze, i+1, j);
		}
		if (j+1 <maze.size() && maze[i][j+1] == 0) {
			possibilities+= calcPaths(maze, i, j+1);
		}
		maze[i][j] = 0;
		return possibilities;
	}
}

int main() {
	int n;
	cin>>n;
	vector<vector<int> > maze = vector<vector<int> >(n, vector<int>(n, 0));
	for(int i = 0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin>>maze[i][j];
		}
	}
    cout<<calcPaths(maze, 0, 0);

}