#include<iostream>
#include<vector>
#include<climits>

using namespace std;


//https://www.spoj.com/problems/PRATA/
bool isPossibleToCook(long long int time, int rank, long long int pratas) {
    return (((pratas*(pratas+1)*rank)/2) <= time);
}

int maxPratasPerCook(long long int time, int rank) {
    long long int beg = 0, end = time, ans = 0;
    while(beg<=end) {
        long long int mid = (beg+end)/2;
        if(isPossibleToCook(time, rank, mid)) {
            ans = mid;
            beg = mid+1;
        } else {
            end = mid-1;
        }
    }
    return ans;
}

int maxPratas(vector<int>& cookRanks, long long int time) {
    int maxPratasPossible = 0;
    for(int i=0; i<cookRanks.size(); i++) {
        int rank = cookRanks[i];
        maxPratasPossible+= maxPratasPerCook(time, rank);
    }
    return maxPratasPossible;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int par, cooks;
        cin>>par;
        cin>>cooks;
        vector<int> ranks(cooks, 0);
        for(int i=0; i<cooks; i++) {
            cin>>ranks[i];
        }

        long long int min_time = 0, max_time = 4*(par+1)*(par), ans=INT_MAX;

        while(min_time<=max_time) {
            long long int mid = (min_time+max_time)/2;
            if(maxPratas(ranks, mid) >= par) {
                ans = mid;
                max_time = mid-1;
            } else {
                min_time = mid+1;
            }
        }
        cout<<ans<<endl;
    }
}