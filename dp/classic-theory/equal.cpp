#include<iostream>
#include<vector>
#include<climits>               //IMP to include

using namespace std;

//https://www.hackerrank.com/challenges/equal/problem
// all test case passing but one

//calculate minOps needed to take i {1, 999}, to 0. [as we have reverse the problem from incre all but 1 -> decre only 1 element: same meaning]
void findMinOps(vector<int>& minOps) {
    vector<int> stepSizes = {1, 2, 5};
    for (int i = 1; i<minOps.size(); i++) {
        for(int j = 0; j<stepSizes.size(); j++) {
            if (i - stepSizes[j] < 0) continue;
            if (minOps[i- stepSizes[j]] != -1) {
                if (minOps[i] < 0) {
                    minOps[i] = 1 + minOps[i - stepSizes[j]];
                } else {
                    minOps[i] = min(minOps[i], 1 + minOps[i - stepSizes[j]]);
                }
            }
        }
    }
    return;
}

int main() {
    int t;
    cin>>t;
    vector<int> minOps = vector<int>(1000, -1); //max value of initial counts/positions is < 1000, i.e.: 999, so size = 1000, as ans[0] = 0
    minOps[0]=0;
    findMinOps(minOps);

    // for (int i = 0; i<= 12; i++) {
    //     cout<<minOps[i]<<" ";
    // }
    // cout<<endl;
    while(t--) {
        int n;
        cin>>n;
        vector<int> startPositions = vector<int>(n);
        int mini = INT_MAX;
        for(int i = 0; i<n; i++) {
            cin>>startPositions[i];
            mini = min(mini, startPositions[i]);
        }
        int totalMinOps = INT_MAX;
        for (int dest = 0; dest<=mini; dest++) {
            int totalOps = 0;
            for (int i = 0; i<n ; i++) {
                totalOps += minOps[startPositions[i] - dest];
                // if (dest == 7) {
                //     cout<<"ops for start: "<<startPositions[i]<<" and dest = 7 is "<<minOps[startPositions[i] - dest];
                // }
            }
            //cout<<"total ops for dest:"<<dest<<" is "<<totalOps<<endl;
            totalMinOps = min(totalMinOps, totalOps);
        }
        cout<<totalMinOps<<endl;
    }
    return 0;
}