#include<iostream>
#include<stack>

using namespace std;

int main() {
	int n;
	cin>>n;
	stack<int> road, wait;

	for(int i=0; i<n; i++) {
		int a;
		cin>>a;
		road.push(a);
	}

	int cur=1;

	while(!road.empty()) {
        
		if (road.top() == cur) {
			road.pop();
			cur++;
		} else if (!wait.empty() && wait.top() == cur) {
            cout<<road.top()<<endl;
			wait.pop();
			cur++;
		} else {
			int roadTop = road.top();
			wait.push(roadTop);
			road.pop();
		}
	}

	if (road.empty() && wait.empty()) {
		cout<<"possible"<<endl;
	} else {
		cout<<"impossible"<<endl;
	}
}