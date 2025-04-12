#include<bits/stdc++.h>

using namespace std;

// LC : AC: https://leetcode.com/problems/add-digits/description/

int main() {
    int x=0;
    cin>>x;
    
    while(x>=10) {
        int sum_of_digits = 0;
        while(x>0) {
            sum_of_digits += x%10;
            x=x/10;
        }
        x=sum_of_digits;
    }
        cout<<x;
    return 1;
}