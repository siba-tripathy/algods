#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void recur_rev(vector<int>& arr, int start, int end) {
    if (end>start) {
        swap(arr[start], arr[end]);
        recur_rev(arr, ++start, --end);
        return;
    }
    return;
}

void printarray(vector<int>& arr) {
    for (int i=0; i<arr.size(); i++ ) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> arr = {4, 6, 7, 3, 4};
    recur_rev(arr, 0, arr.size()-1);
    printarray(arr);
}