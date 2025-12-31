#include <bits/stdc++.h>
using namespace std;

// Medium. Tricky##$$$G##re$$$ed##y
// GFG: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution {
   public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n=arr.size();
        vector<pair<int, int>> trains(n);
        for (int i=0; i<n; i++) {
            trains[i] = pair<int, int>(arr[i], dep[i]);
        }
        sort(trains.begin(), trains.end());
        priority_queue<int, vector<int>, greater<int>> station;
        int max_trains_parked = 0;
        for (int i=0; i<n; i++) {  
            // see how we handle all 3 cases with this single if statement
            if (!station.empty() && station.top() < trains[i].first) {
                station.pop();
            }
            station.push(trains[i].second);
            max_trains_parked = max(max_trains_parked, (int)station.size());
        }
        return max_trains_parked;
    }
};
