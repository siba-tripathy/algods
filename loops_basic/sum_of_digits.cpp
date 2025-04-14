#include<bits/stdc++.h>

using namespace std;

//GFG : AC : https://www.geeksforgeeks.org/problems/sum-of-digits1742/1

int main() {
    int x = 76753;
    int sum = 0;
    while(x>0) {
        sum+=x%10;
        x=x/10;
    }
    cout<<sum;
    return 1;
}