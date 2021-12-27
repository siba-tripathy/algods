#include<iostream>
#include<vector>

using namespace std;

//worked on sanket's input - AC

//top-down recursive
int mcm(vector<int>& sizes, int i, int j, vector<vector<int> >& minCounts) {
    if (minCounts[i][j] != -1) { return minCounts[i][j];}
    if (j==i+1) {return minCounts[i][j] = 0;}
    int minSteps = INT_MAX;
    for(int k = i+1; k<j; k++) {
        int leftMCM = mcm(sizes, i, k, minCounts);
        int rightMCM = mcm(sizes, k, j, minCounts);
        minSteps = min(minSteps, leftMCM + rightMCM + sizes[i]*sizes[k]*sizes[j]);
    }
    return minCounts[i][j] = minSteps;
}

//botton-up
//AC
int mcmBU(vector<int>& sizes) {
    int n= sizes.size();
    vector<vector<int> > minCounts(n, vector<int>(n, -1));

    for (int i = 0 ; i<n-1 ; i++) {
        minCounts[i][i+1] = 0;
    }

    for(int len = 2; len<n; len++) {
        for(int i =0; i<n-len; i++) {
            int j = i + len;

            int minCost = INT_MAX;
            for(int k = i+1; k<j; k++) {
                minCost = min(minCost, minCounts[i][k] + minCounts[k][j] + sizes[i]*sizes[k]*sizes[j]);
            }
            minCounts[i][j] = minCost;
        }
    }
    return minCounts[0][n-1];
}

int main() {
    int n;
    cin>>n;
    vector<int> sizes(n);
    for(int i =0; i<n; i++) {
        cin>>sizes[i];
    }
    vector<vector<int> > minCounts(n+1, vector<int>(n+1, -1));
    
    //cout<<mcm(sizes, 0, n-1, minCounts);
    cout<<mcmBU(sizes);
}