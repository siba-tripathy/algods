#include<iostream>
#include<vector>

using namespace std;

//https://leetcode.com/problems/minimum-cost-for-tickets/
//nice question
//AC


int main() {
	int d;
	cin>>d;
	vector<int> days(d);
	vector<int> costs(3);
	for(int i=0; i<d; i++) {
		cin>>days[i];
	}

	for(int i=0; i<3; i++) {
		cin>>costs[i];
	}

	sort(days.begin(), days.end());
	int lastDay = days[d-1];
	vector<int> minCost(lastDay+1, INT_MAX);
	minCost[0] = 0;    //base case: travelling 0th day does not cost anything

	int cur_journey_day = 0;
	for(int i=1; i<=lastDay; i++) {
		if (days[cur_journey_day] == i) {
			//1 day ticket
			int p1 = minCost[i-1] + costs[0];
			//7 day ticket
			int p7 = i >= 7 ? minCost[i-7] + costs[1] : costs[1];
			//30 day ticket
			int p30 = i >= 30 ?  minCost[i-30] + costs[2] : costs[2];
			minCost[i] = min(p1, min(p7, p30));
			cur_journey_day++;
		} else {
			minCost[i] = minCost[i-1];
		}
	}
	cout<<minCost[lastDay];
}