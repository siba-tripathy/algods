#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int main() {
    vector<int> arr{ 2, 3, 11, 4, 2, 9, 7, 8, 12};               //only in c++11 so use -std=c++11
    int k = 3;
    vector<int> ans;
    int n = arr.size();
    deque<int> tracker;

    for(int i=0; i<k; i++) {
        while(!tracker.empty() && arr[tracker.back()] <= arr[i]) {
            tracker.pop_back();
        }
        tracker.push_back(i);
    }
    ans.push_back(arr[tracker.front()]);                   // remember to push values not indices int he ans vector
    for(int i=k; i<n; i++) {  // here i is the end position of the window
        if(tracker.front() == i-k) {   //i-k is the prev leftmost element - goes out of bounds
            tracker.pop_front();
        }

        while(!tracker.empty() && arr[tracker.back()] <= arr[i]) {
            tracker.pop_back();
        }
        tracker.push_back(i);
        ans.push_back(arr[tracker.front()]);                 // remember to push values not indices int he ans vector
    }

    for(int i = 0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}