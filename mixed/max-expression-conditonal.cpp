#include<iostream>
#include<vector>
#include<deque>

using namespace std;
//find max value of expression abs(Xj - Xi) + Pi + Pj


int main() {
    vector<int> xrr = {2, 4, 7, 8, 9, 10, 11, 14}; //sorted - X
    vector<int> prr = {2, 4, 1, 3, 7, 5, 7, 9};   //unsorted - P
    int k = 3;
    //trick chose j>i always so that can get rid of abs
    
    deque<int> q;
    q.push_back(0);
    int ans=INT_MIN;
    for(int i=1; i<xrr.size(); i++) {
        //making the out of bounds decision on front - to maintain range
        while(!q.empty() && xrr[i] - xrr[q.front()] >k) {
            q.pop_front();
        }
        //check what the max possible value of expression is consider current ith index as ending element
        //max is at front in this deque max of subaaray approach
        if(!q.empty()) {
            ans=max(ans, prr[i]+xrr[i]+prr[q.front()] - xrr[q.front()]);
        }
        //keeping max at front and tracking future eligible maxes - smaller ones cant be max in future
        //pls understand why <= is used :  (similra to the queue main approach)
        //as we want max for future so want nearest greter which can contribute longer and not get popped wrongly when its out of bounds and we store indices 
        while(!q.empty() && prr[q.back()] - xrr[q.back()] <= prr[i]-xrr[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout<<ans;


}