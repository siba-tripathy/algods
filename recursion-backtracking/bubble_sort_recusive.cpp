#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printarray(vector<int>& arr) {
    for (int i=0; i<arr.size(); i++ ) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void recur_sort(vector<int>& arr, int i, int n) {
    if (n == 1) {
        return;
    } else if (i==n-1) {
        printarray(arr);
        recur_sort(arr, 0, n-1);
        return;
    }

    if (arr[i] > arr[i+1]) {
        swap(arr[i], arr[i+1]);
    }
    recur_sort(arr, i+1, n);
}

int main() {
    vector<int> arr = {5, 4, 3, 2, 1};
    recur_sort(arr, 0, 5);
}

