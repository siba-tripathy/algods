#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n, 0);
        long long int sum = 0;
        for(int i=0; i<n; i++) {
            cin>>arr[i];
            sum+=arr[i];
        }
        sort(arr.begin(), arr.end());
        bool firstLose = false;
        for(int i=0; i<n; i++) {
            if(arr[i]>i+1)
                firstLose = true;
        }
        int expected = n*(n+1)/2;
        int diff = expected - sum;
        // if (diff <= 0 && (*max_element(arr.begin(), arr.end()) > ))
        //     cout<<"Second"<<endl;
        if(firstLose == true) {
            cout<<"Second"<<endl;
        } else {
            if(diff%2 == 0)
                cout<<"Second"<<endl;
            else
                cout<<"First"<<endl;
        }
    }
}