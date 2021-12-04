#include<iostream>
#include<vector>

using namespace std;

//https://leetcode.com/problems/coin-change/
//both approaches AC

int findMinCoins(int amount, vector<int>& coins, vector<int>& ans) {
    if(amount == 0) {
        return 0;
    }
    if (amount < 0) {
        return -1;
    }
    if (ans[amount] != -2) {
        return ans[amount];
    }
    int minCoins = -1; //let it denote impossible at first
    for(int i=0; i<coins.size(); i++) {
        int minCoinsNext = findMinCoins(amount - coins[i], coins, ans);
        if (minCoinsNext != -1) {
            if (minCoins == -1) {
                minCoins = 1+minCoinsNext;
            }
            minCoins = min(minCoins, 1+ minCoinsNext);
        }
    }
    ans[amount] = minCoins;
    return minCoins;
}

int findMinCoinsBU(int amount, vector<int>& coins) {
    vector<int> minCoins = vector<int>(amount+1, -1);
    minCoins[0]=0;
    for(int i = 1; i <= amount; i++) {
        for(int j = 0; j < coins.size(); j++) {
            if(i - coins[j] == 0) {
                minCoins[i] = 1;
            }
            else if (i - coins[j] > 0) {
                if (minCoins[i- coins[j]] != -1) {
                    if (minCoins[i] == -1) {
                        minCoins[i] = 1 + minCoins[i - coins[j]];
                    } else {
                        minCoins[i] = min(minCoins[i], 1 + minCoins[i - coins[j]]);
                    }
                }
            }
        }
    }
    return minCoins[amount];
}

int main() {
    int amount,n;
    cin>>amount>>n;
    vector<int> coins = vector<int>(n);
    for(int i = 0; i<n; i++) {
        cin>>coins[i];
    }
    vector<int> ans = vector<int>(amount+1, -2);
    //cout<<findMinCoins(amount, coins, ans);
    cout<<findMinCoinsBU(amount, coins);
}
