#include<iostream>
#include<vector>
#include<climits>               //IMP to include

using namespace std;

//https://www.hackerrank.com/challenges/equal/problem
// all test case passing but one

//calculate minOps needed to take i {1, 999}, to 0. [as we have reverse the problem from incre all but 1 -> decre only 1 element: same meaning]
void findMinOps(vector<int>& minOps) {
    vector<int> operationSizes = {1, 2, 5};
    for (int i = 1; i<minOps.size(); i++) {
        for(int j = 0; j<operationSizes.size(); j++) {
            if (i - operationSizes[j] < 0) continue;
            if (minOps[i- operationSizes[j]] != -1) {
                if (minOps[i] < 0) {
                    minOps[i] = 1 + minOps[i - operationSizes[j]];
                } else {
                    minOps[i] = min(minOps[i], 1 + minOps[i - operationSizes[j]]);
                }
            }
        }
    }
    return;
}

int main() {
    int t;
    cin>>t;
    vector<int> minOps = vector<int>(10004, -1); //max value of initial counts/positions is < 1000, and we check for value - (min-4), so range is 0 to 1004 {1004 when max = 1000 and min = 0}
    minOps[0]=0;
    findMinOps(minOps);

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
        for (int dest = mini-4; dest<=mini; dest++) {
            int totalOps = 0;
            for (int i = 0; i<n ; i++) {
                totalOps += minOps[startPositions[i] - dest];
                // ops to reduce x to target t = f(x-t)
            }
            totalMinOps = min(totalMinOps, totalOps);
        }
        cout<<totalMinOps<<endl;
    }
    return 0;
}