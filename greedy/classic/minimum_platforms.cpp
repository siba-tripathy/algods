#include <bits/stdc++.h>
using namespace std;

// Medium. Tricky##$$$G##re$$$ed##y
// GFG: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution {


   public:

    // This is the DS based solution
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

    // IMP This is a slick, but easy solve. Ideal ans. Seems tricky but can be a very big improve over range/prefix sum intuitions.
    struct TrainComp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first==b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };

    int alternateMinPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        vector<pair<int, int>> trains(2*n);
        for (int i = 0; i < n; i++) {
            trains[2*i] = pair<int, int>(arr[i], 1);
            trains[2 * i + 1] = pair<int, int>(dep[i], -1);
        }
        sort(trains.begin(), trains.end(), TrainComp());
        int max_trains_parked = 0, cur_trains_parked=0;
        for (int i=0; i<2*n; i++) {
            cur_trains_parked+=trains[i].second;
            max_trains_parked = max(max_trains_parked, cur_trains_parked);
        }
        return max_trains_parked;
    }
};
