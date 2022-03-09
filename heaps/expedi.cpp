#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

//AC - too many input problems - Good question - Med-hard
//https://www.spoj.com/problems/EXPEDI/

int main() {
	int t;
    cin>>t;
	while(t--) {
		long long int n,l,p;
		cin>>n;
		vector<pair<long long int, long long int> > stations(n);
		for(int i=0; i<n; i++) {
			long long int a,b;
			cin>>a>>b;
			stations[i].first = a;
            stations[i].second = b;
		}
        cin>>l>>p;
		long long int cur_reach=p;
		long long int stops = 0;
        //max heap so that we can use the prev station that had max fuel
		priority_queue<long long int> mh;
        int i=0;
        //make dist from target to dist from source car
        for(int i=0; i<n; i++) {
			stations[i].first = l-stations[i].first;
		}
        //arrange in order of arrival of car
        sort(stations.begin(), stations.end());
		for(i=0; i<n; i++) {
            //check if net station is not reachable - use max fuel stations from past
			while(cur_reach < stations[i].first) {
                if (mh.empty()) {//used up all past stations
                    break;
                }
				cur_reach+=mh.top();
				mh.pop();
				stops++;
			}
            //make sure ith station is reachable
            //fail if not
            if (cur_reach < stations[i].first) { 
                break; 
            }
            //ith station reachable
            //can add ith station's fuel as option for future
            mh.push(stations[i].second);
		}
        //if could not traverse till last station then fail
        if (i!=n) {
            cout<<-1<<endl;
            continue;
        }
    
        //traversed last station but still did not reach target
        //use max fuel stations from past
		while(cur_reach<l) {
            if (mh.empty()) {//used up all
                break;
            }
			cur_reach+=mh.top();
			mh.pop();
			stops++;
		}
		if(cur_reach<l) {//couldnot reach l even after all fuel used
            cout<<-1<<endl;
		} else {
            cout<<stops<<endl;
		}
	}
    return 0;
}