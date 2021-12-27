#include<iostream>
#include<vector>
#include<climits>

using namespace std;

//botton-up
//AC
int mcmBU(vector<int>& mixtures) {
    int n= mixtures.size();
    vector<vector<int> > minGas(n, vector<int>(n, -1));
    vector<vector<int> > result(n, vector<int>(n, -1));

    for (int i = 0 ; i<n ; i++) {
        minGas[i][i] = 0;
        result[i][i] = mixtures[i];
    }

    for(int len = 2; len<=n; len++) {
        for(int i =0; i<=n-len; i++) {
            int j = i + len-1;

            int minCost = INT_MAX;
            int resultOfMinCost = 0;
            for(int k = i; k<j; k++) {
                int gas = minGas[i][k] + minGas[k+1][j] + result[i][k]*result[k+1][j];
                if(gas < minCost) {
                    minCost = gas;
                    resultOfMinCost = (result[i][k]+result[k+1][j])%100;
                }
            }
            minGas[i][j] = minCost;
            result[i][j] = resultOfMinCost;
        }
    }
    return minGas[0][n-1];
}

int main() {
    int n;
    while(cin>>n) {
    
    
    vector<int> mixtures(n);
    for(int i =0; i<n; i++) {
        cin>>mixtures[i];
    }
    
    cout<<mcmBU(mixtures)<<endl;
    }
}