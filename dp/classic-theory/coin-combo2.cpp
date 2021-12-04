#include<iostream>
#include<vector>

using namespace std;


//https://cses.fi/problemset/task/1636
//AC

int getAllCoinCombos(int sumRequired, vector<int>& coins) {
    vector<int> coinCombos = vector<int>(sumRequired+1, 0);
    coinCombos[0]=1;
    for(int j = 0; j<coins.size(); j++) {
        for(int i = 1; i <= sumRequired; i++) {
            //here we just have to check for jth coin, i.e. we need to check for i - coins[j] and add the combo count of i - coins[j]
            if (i - coins[j] < 0) continue;
            else coinCombos[i] = (coinCombos[i] + coinCombos[i - coins[j]]) % 1000000007;
        }
    }
    return coinCombos[sumRequired];
}

int main() {
    int n, sum;
    cin>>n>>sum;
    vector<int> coins = vector<int>(n);
    for(int i = 0; i<n; i++) {
        cin>>coins[i];
    }
    //vector<int> coinCombos = vector<int>(sum+1, -1);
    cout<<getAllCoinCombos(sum, coins)<<endl;
    // for(int i=0; i<sum+1; i++) {
    //     cout<<coinCombos[i]<<" ";
    // }

}