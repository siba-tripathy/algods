#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//given n elements, find the sum of max of all sub-arrays
//trick: calc for each element - how many subarrays is it max of


//

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    vector<int> pg(n); vector<int> ng(n);     //stores preb greater and next greater indices = -1 if none for pg ,n if none for ng
    stack<int> s;           //stores indices


    //find prev greater
    for(int i=0; i<n; i++) {  //remember to use arr[s.top()] in next line - not s.top directly as s stores indices
        while(!s.empty() && arr[s.top()]<= arr[i]) {  //we dont need the smaller elements as they will never be max of any subarray that has a big element to the right
            s.pop();
        }
        if (s.empty()) {
            pg[i] = -1;
        } else {
            pg[i] = s.top();
        }
        //this push may be confusing. think why we do this. do dry run. read next line comment
        s.push(i);   // we store it because it can be prev greater of some one in future. it will be discarded if future element is bigger than this
    }
    stack<int> s2;
    
    //find next greater - similar
    for(int i=n-1; i>=0; i--) {  //remember to use arr[s.top()] in next line - not s.top directly as s stores indices
        while(!s2.empty() && arr[s2.top()]<= arr[i]) {
            s2.pop();
        }
        if (s2.empty()) {
            ng[i] = n;
        } else {
            ng[i] = s2.top();
        }

        s2.push(i);
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        ans += (i-pg[i])*(ng[i]-i)*arr[i];
    }
    cout<<ans;
    
}