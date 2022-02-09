#include<iostream>
#include<vector>

using namespace std;
//find max value of expression abs(Xj - Xi) + Pi + Pj


int main() {
    vector<int> xrr = {2, 4, 7, 8, 9, 10, 11, 14}; //sorted - X
    vector<int> prr = {2, 4, 1, 3, 7, 5, 7, 9};   //unsorted - P

    int max_diff=prr[0]-xrr[0];//trick chose j>i always so that can get rid of abs
    int ans=INT_MIN;
    for(int i=0; i<xrr.size(); i++) {
        ans=max(ans, prr[i]+xrr[i]+max_diff);
        max_diff = max(max_diff, prr[i]-xrr[i]);
    }
    cout<<ans;


}