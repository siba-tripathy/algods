#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> arr = {1};
    for (int i=0; i<arr.size()/2; i++) {
        int temp = arr[i];
        arr[i] = arr[arr.size()-1-i];
        arr[arr.size()-1-i] = temp;
    }

    for (int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
}
