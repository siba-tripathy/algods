#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//https://www.spoj.com/problems/AGGRCOW/

bool checkIfPossible(vector<int>& arr, int minDistance, int cows) {
    int last_cow = arr[0], cows_placed = 1;

    for(int i=1; i<arr.size(); i++) {
        if (arr[i] - last_cow >= minDistance)   //MIN
            last_cow = arr[i], cows_placed++;
    }

    return (cows_placed >= cows);
}


int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,c;
        cin>>n>>c;
        vector<int> stalls = vector<int>(n, 0);
        for(int i=0; i<n; i++) {
            int a;
            cin>>a;
            stalls[i] = a;
        }

        /**
        * very imporatant to know why sorting of stalls position array is needed
        * its needed not for doing binary search: as binary search here is being performed on the answer range
        * its needed to be utilized in the checkIfPossible function: so that we know where is that last cow position
        * and if we are taking the minimum number of gaps that we want to for one iteration
        **/

        sort(stalls.begin(), stalls.end());

        int beg=1, end = stalls[n-1], ans;
        while(beg<=end) {
            int mid = (beg+end)/2;
            if (checkIfPossible(stalls, mid, c)) {
                ans=mid, beg=mid+1;    //MAXI
            } else {
                end = mid-1;
            }
        }
        cout<<ans<<endl;
    } 
}