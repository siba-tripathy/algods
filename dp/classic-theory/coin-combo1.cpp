#include<iostream>
#include<vector>

using namespace std;

//https://cses.fi/problemset/task/1635
//AC
long long int getCoinCombos(long long int sumRequired, vector<long long int>& coins, vector<long long int>& coinCombos) {
    if (sumRequired == 0) {
        return 1;
    }
    else if (sumRequired<0) {
        return 0;
    }
    if (coinCombos[sumRequired] != -1) {
        return coinCombos[sumRequired];
    }
    long long int combos = 0;
    for(long long int i = 0; i<coins.size(); i++) {
        combos = (combos + getCoinCombos(sumRequired-coins[i], coins, coinCombos)) % 1000000007;
    }
    coinCombos[sumRequired] = combos;
    return combos;
}

int main() {
    long long int n, sum;
    cin>>n>>sum;
    vector<long long int> coins = vector<long long int>(n);
    for(long long int i = 0; i<n; i++) {
        cin>>coins[i];
    }
    vector<long long int> coinCombos = vector<long long int>(sum+1, -1);
    cout<<getCoinCombos(sum, coins, coinCombos)<<endl;
    // for(long long int i=0; i<sum+1; i++) {
    //     cout<<coinCombos[i]<<" ";
    // }

}