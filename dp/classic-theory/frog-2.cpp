#include<iostream>
#include<vector>
#include<climits>

using namespace std;

//Q: https://atcoder.jp/contests/dp/tasks/dp_b
//AC


//bottom up solution
int findCheapestPath(vector<int> &stoneHeights, int maxHop) {
    int n = stoneHeights.size();
    vector<int> cheapestPaths = vector<int>(n, 0);

    for(int i = 1; i<n; i++) {
        int cheapestDist = INT_MAX;
        int j = i-1;
        while(j>=0 && j>=i-maxHop) {
            cheapestDist = min(cheapestDist, cheapestPaths[j]+ abs(stoneHeights[i] - stoneHeights[j]));
            j--;
        }
        cheapestPaths[i] = cheapestDist;
        //cout<<cheapestPaths[i]<<endl;
    }
    return cheapestPaths[n-1];
}

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> stoneHeights = vector<int>(n, 0);
    for(int i = 0; i<n ; i++) {
        cin>>stoneHeights[i];
    }
    cout<<findCheapestPath(stoneHeights, k);
}