#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>

using namespace std;

//https://codeforces.com/contest/1388/problem/D
//Great question(Please try to think: two parts -> find max ans, second-> find sequence)
//AC

int main() {
	int n;
	cin>>n;
	vector<long long int> a(n);
	vector<int> b(n);

	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
    long long int ans=0;

	vector<int> in_degrees(n, 0);
	queue<int> zero_indegrees;
	
	for(int i=0; i<n; i++) {
		cin>>b[i];
        if(b[i] > 0) {
            b[i]--;
        }
		in_degrees[b[i]]++;
	}

	for(int i=0; i<n; i++) {
		if(in_degrees[i] == 0) {
			zero_indegrees.push(i);
		}
	}

	vector<long long int> val(a.begin(), a.end());
    vector<int> negatives;
    vector<int> positives;

	while(!zero_indegrees.empty()) {
		int front = zero_indegrees.front();
        zero_indegrees.pop();

		ans += val[front];
        if (val[front] > 0) {
            positives.push_back(front+1);
		} else {
            negatives.push_back(front+1);
        }

		if (b[front] != -1) {                               //stop if no further connection
			in_degrees[b[front]]--;                         //always remove next connection
			if(in_degrees[b[front]] == 0) {                 //if next conn is now zero indegrees, add to queue 
				zero_indegrees.push(b[front]);
			}
			if (val[front] > 0) {                           //contribute to next conn val only if you are contributing positively
				val[b[front]]+= val[front];
            }
		}
	}



	cout<<ans<<endl;
	for(int i =0; i<positives.size(); i++) {
        cout<<positives[i]<<" ";
    }
    for(int i=negatives.size()-1; i>= 0 ; i--) {
        cout<<negatives[i]<<" ";
    }

	return 0;
}