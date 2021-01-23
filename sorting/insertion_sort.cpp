#include<vector>
#include<iostream>
using namespace std;

void insertion_sort(vector<int>& arr) {
    if(arr.size() < 2) {
        return;
    }
    int n = arr.size();
    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j;
        for (j = i-1; j>=0; j--) {
            cout<<endl;
            if (arr[j]> key) {
                arr[j+1] = arr[j];
            } else {
                break;
            }
        }
        arr[j+1] = key;
        for (int x : arr) {
            cout<<x<<" ";
        }
    }
    return;
}


int main(){
    int n;
    vector<int> arr{12, 11, 3, 2, 5, 7, 9, 6, 3, 4, 10};
    insertion_sort(arr);
    cout<<endl<<"Sorted Array is: ";
    for (int x: arr) {
        cout<<" "<<x; 
    }
}