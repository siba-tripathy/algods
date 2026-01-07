#include <bits/stdc++.h>
using namespace std;

// LC Med. Very Very Great Impl Problem. Learn: custom sorting, set ordering, bin search in built and iterator application.
// Please implement yourself from scratch for great revision.
// https://leetcode.com/problems/my-calendar-i/

class MyCalendar {
   public:
    struct SlotCompareStartAsc {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            return a.first < b.first;
        }
    };
    set<pair<int, int>, SlotCompareStartAsc> cal;
    MyCalendar() {
    }

    bool book(int startTime, int endTime) {
        pair<int, int> event{startTime, endTime};
        if (cal.empty()) {
            cal.insert(event);
            return true;
        }
        auto ub = cal.upper_bound(event);

        if (ub != cal.end()) {  // whenever ub is not at very end, ie can be in begin or middle, check end time overlap
            if (event.second > ub->first) {
                return false;
            }
        }
        if (ub != cal.begin()) {
            ub--;
            if (event.first < ub->second) {
                return false;
            }
        }
        cal.insert(event);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */