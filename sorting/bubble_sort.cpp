#include<vector>
#include<iostream>
using namespace std;

void bubble_sort(vector<int>& arr) {
    if(arr.size() < 2) {
        return;
    }
    int n = arr.size();
    for(int i=0; i< n-1; i++) {
        for (int j = 0; j<n-1-i; j++) {
            for (int x : arr) {
                    cout<<x<<" ";
                }
                cout<<endl;
            if (arr[j]> arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    return;
}

int main(){
    int n;
    vector<int> arr{9};
    bubble_sort(arr);
    cout<<endl<<"Sorted Array is: ";
    for (int x: arr) {
        cout<<" "<<x; 
    }
}
